/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:26:24 by crepou            #+#    #+#             */
/*   Updated: 2023/12/08 23:20:02 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	std::cout << "BitcoinExchange constructor called" << std::endl;
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src)
{
	*this = src;
	return ;
}

BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << "BitcoinExchange destructor called" << std::endl;
	return ;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs)
{
	(void)rhs;
	return (*this);
}

long long BitcoinExchange::hash_func(int year, int month, int day) {
	return year * 10000 + month * 100 + day;
}

int BitcoinExchange::get_first_year( void ) {
	std::map<long long, double>::iterator it = _data.begin();
	return it->first / 10000;
}

int BitcoinExchange::get_last_year( void ) {
	std::map<long long, double>::iterator it = _data.end();
	it--;
	return it->first / 10000;
}

void BitcoinExchange::insert_data(int year, int month, int day, double rate) {
	long long key = hash_func(year, month, day);
	_data[key] = rate;
}

double BitcoinExchange::get_rate(int year, int month, int day) {
	long long key = hash_func(year, month, day);
	std::map<long long, double>::iterator it = _data.end();
	if (_data.find(key) == _data.end()) {
		while (it != _data.begin()) {
			if (it->first < key) {
				return it->second;
			}
			it--;
		}
	}
	return _data[key];
}

int BitcoinExchange::get_year(std::string date) {
	int year = std::stoi(date.substr(0, 4));
	if (year >= 1000 && year < 2009)
	{
		std::cerr << "Error: There are no data before 2009" << std::endl;
		return -2;
	} else if (year > 2022) {
		std::cerr << "Error: There are no data after 2022" << std::endl;
		return -2;
	} else if (year < 1000)
		return -1;
	return year;
}

int BitcoinExchange::get_month(std::string date) {
	int month = std::stoi(date.substr(5, 2));
	if (month < 1 || month > 12)
		return -1;
	return month;
}

int BitcoinExchange::get_day(std::string date) {
	int day = std::stoi(date.substr(8, 2));
	const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int month = get_month(date);
	if (month == -1)
		return -1;
	if (day < 1 || day > daysInMonth[month])
		return -1;
	return day;
}

std::string BitcoinExchange::key_to_date(long long key) {
	std::string date = std::to_string(key / 10000);
	date += "-";
	if ((key % 10000) / 100 < 10)
		date += "0";
	date += std::to_string((key % 10000) / 100);
	date += "-";
	if (key % 100 < 10)
		date += "0";
	date += std::to_string(key % 100);
	return date;
}

void BitcoinExchange::save_data( void ) {
	std::string line;
	std::string date;
	int year;
	int month;
	int day;
	double rate;
	bool first_line = true;

	std::ifstream dataFile("data.csv");
	if (dataFile.is_open()) {
		while (std::getline(dataFile, line))
		{
			if (first_line) {
				first_line = false;
				continue ;
			}
			date = line.substr(0, 10);
			year = get_year(date);
			month = get_month(date);
			day = get_day(date);
			rate = std::stod(line.substr(11));
			insert_data(year, month, day, rate);
		}
	}
	else {
		throw std::invalid_argument("Unable to open data.csv.");
	}
}

std::map<long long, double> BitcoinExchange::get_data( void ){
	return _data;
}

std::string BitcoinExchange::get_date(std::string line) {
	return line.substr(0, 10);
}

bool BitcoinExchange::is_valid_date(std::string date) {
	unsigned long i = 0;
	for (; i < date.size(); i++) {
		if (i < 4 || (i > 4 && i < 7) || i > 7)
		{
			if (date[i] < '0' || date[i] > '9')
			{
				std::cerr << "Error: bad input => " << date << std::endl;
				return false;
			}
		} else if (i == 4 || i == 7) {
			if (date[i] != '-')
			{
				std::cerr << "Error: bad input => " << date << std::endl;
				return false;
			}
		}
	}
	return true;
}

std::string BitcoinExchange::get_info(std::string line) {
	if (line.size() < 11)
		return "0";
	std::string mehr = line.substr(10);
	unsigned long i = 0;
	for (; i < mehr.size(); i++) {
		if (((i == 0 || i == 2) && mehr[i] != ' ') || (i == 1 && mehr[i] != '|'))
		{
			std::cerr << "Error: Invalid line format" << std::endl;
			return "";
		}
		else if (i == 3 && mehr[i] == '-')
		{
			std::cerr << "Error: not a positive number." << std::endl;
			return "";
		}
		if (i > 2 && ((mehr[i] < '0' || mehr[i] > '9') && mehr[i] != '.'))
		{
			std::cerr << "Error: not a correct amount format => " << mehr.substr(3) << std::endl;
			return "";
		}
	}
	return mehr.substr(3);
}

void BitcoinExchange::print_data( std::string line ) {
	std::string date = get_date(line);
	if (is_valid_date(date))
	{
		std::string info = get_info(line);
		if (info.empty())
			return ;
		double amount = std::stod(get_info(line));
		if (amount > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			return ;
		}
		int day;
		int month;
		int year;
		if ((day = get_day(date)) == -1 || (month = get_month(date)) == -1 || (year = get_year(date)) == -1)
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			return ;
		}
		if (year == -2)
			return ;
		double rate = get_rate(year, month, day);
		std::cout << date << " | " << amount << " = " << amount * rate << std::endl;
	}
}