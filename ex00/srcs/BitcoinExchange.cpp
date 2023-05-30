/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:10:19 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/30 19:31:08 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
	return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &toCopy)
{
	if (this != &toCopy)
		*this = toCopy;
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
	return ;
}

BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << "BitcoinExchange destructor called" << std::endl;
	return ;
}

BitcoinExchange	&BitcoinExchange::operator = (BitcoinExchange const &toCopy)
{
	_dataMap.insert(toCopy._dataMap.begin(), toCopy._dataMap.end());
	return (*this);
}

int	BitcoinExchange::fillMap(void)
{
	std::ifstream	infile("data.csv");
	if (infile.is_open() == false)
		return (std::cerr << "Open data.csv failed" << std::endl, 1);

	std::string	line;
	std::getline(infile, line);
	while (std::getline(infile, line))
	{
		int		sepPos = line.find(',', 0);
		std::string	date = line.substr(0, sepPos);
		std::string	valueStr = line.substr(sepPos + 1);

		float	value;
		std::istringstream	iss(valueStr);
		if (!(iss >> value))
			return (std::cerr << "Bad value : " << valueStr << std::endl, 2);
		_dataMap[date] = value;
	}
	infile.close();
	return (0);
}

void	BitcoinExchange::printMap(void) const
{
	for (std::map<std::string, float>::const_iterator it = _dataMap.begin(); it != _dataMap.end(); it++)
	{
        std::cout << it->first << ", " << std::fixed << std::setprecision(2) <<  it->second << std::endl;
	}
}

int	BitcoinExchange::recupInput(char *av) const
{
	std::ifstream	input(av);
	if (input.is_open() == false)
		return (std::cerr << "Open " << av << " failed" << std::endl, 1);

	std::string	line;
	std::getline(input, line);
	while (std::getline(input, line))
	{
		std::istringstream	iss(line);
		std::string			date;
		char				sep;
		float				value = 0.0;
		float				rate = 0.0;
		std::string			rest;

		if (iss >> date >> sep >> value >> rest)
			std::cerr << "Bad line : " << line << std::endl;
		else if (parseValue(value))
			;
		else if (parseDate(date))
			std::cerr << "Error: bad input => " << date << std::endl;
		else
		{
			rate = getExchangeRate(date);
			std::cout << date << " => " << value << " = " << rate * value << std::endl; 
		}
		// Fonction multliplier _dataMap->value et value pour avoir le total et le print
	}
	input.close();
	return (0);
}

int	BitcoinExchange::parseValue(float value) const
{
	if (value < 0)
		return (std::cerr << "Error: not a positive number." << std::endl, 1);
	else if (value > 1000)
		return (std::cerr << "Error: too large a number." << std::endl, 2);
	return (0);
}

int	BitcoinExchange::parseDate(std::string date) const
{
	if (checkFormat(date))
		return (1);
	std::istringstream iss(date);
    int					year, month, day;
	int					maxDays = 31;
	char				delim;

    iss >> year >> delim >> month >> delim >> day;

	if (year < 2009 || year > 2022 || month < 1 || month > 12 || day < 1)
		return (2);
	else if (year == 2009 && month == 1 && day < 02)
		return (3);
	else if (month == 4 || month == 6 || month == 9 || month == 11)
        maxDays = 30;
	else if (month == 2)
	{
        if (isLeapYear(year))
            maxDays = 29;
        else
            maxDays = 28;
    }
	return (!(day <= maxDays));
}

bool BitcoinExchange::checkFormat(std::string date) const
{
	std::istringstream iss(date);
    std::string year, month, day;

    std::getline(iss, year, '-');
    std::getline(iss, month, '-');
    std::getline(iss, day, '-');

	if (year.empty() || month.empty() || day.empty()) // Check que le format est bien YYYY-MM-DD
		return (true);
	return (false);
}

bool BitcoinExchange::isLeapYear(int year) const
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

float BitcoinExchange::getExchangeRate(const std::string &date) const
{
	std::map<std::string, float>::const_iterator it = _dataMap.lower_bound(date);
	if (it == _dataMap.end())
		return ((--it)->second);
	if (it->first > date)
		it--;
	return (it->second);
}
