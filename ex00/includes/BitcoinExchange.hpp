/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:10:17 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/30 19:10:45 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <iomanip>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	_dataMap;

	public:

		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &copy);
		~BitcoinExchange(void);

		BitcoinExchange	&operator = (BitcoinExchange const &toCopy);

		int		fillMap(void);
		void	printMap(void) const;
		int		recupInput(char *av) const;
		int		parseValue(float value) const;
		int		parseDate(std::string date) const;
		bool	isLeapYear(int year) const;
		bool	checkFormat(std::string date) const;
		float	getExchangeRate(const std::string &date) const;

		
};

#endif
