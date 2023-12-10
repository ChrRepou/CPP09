/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:25:24 by crepou            #+#    #+#             */
/*   Updated: 2023/12/08 23:43:03 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <stdexcept>
#include <limits>

class BitcoinExchange
{
	private:
		std::map<long long, double> _data;
	
	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const & src);
		~BitcoinExchange(void);
		BitcoinExchange & operator=(BitcoinExchange const & obj);
		
		long long hash_func(int year, int month, int day);
		void insert_data(int year, int month, int day, double rate);
		double get_rate(int year, int month, int day);
		int get_year(std::string date);
		int get_month(std::string date);
		int get_day(std::string date);
		void save_data( void );
		std::string get_date(std::string line);
		std::string key_to_date(long long key);
		std::map<long long, double> get_data( void );
		bool is_valid_date(std::string date);
		std::string get_info(std::string line);
		void print_data( std::string line );
		int get_first_year( void );
		int get_last_year( void );
		//std::string get_date(long long key);
};

#endif