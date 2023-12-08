/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 21:39:07 by crepou            #+#    #+#             */
/*   Updated: 2023/12/08 23:25:36 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./btc [filename]" << std::endl;
		return (1);
	}
	
	std::ifstream inputFile(argv[1]);
	
	if (inputFile.is_open()) {
		std::cout << "File opened successfully.\n";
		BitcoinExchange exchange;
		try {
			exchange.save_data();
			bool first_line = true;
			std::string line;
			while (std::getline(inputFile, line)) {
				if (first_line) {
					first_line = false;
					continue;
				}
				exchange.print_data(line);
			}
		} catch (std::exception &e) {
			std::cout << "Error! " << e.what() << std::endl;
		}

		// Close the file
		inputFile.close();
	} else {
		std::cerr << "Unable to open the file.\n";
	}
	
	return 0;
}