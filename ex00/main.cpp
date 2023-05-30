/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:10:30 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/30 17:38:43 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (std::cerr << "tuto : ./btc [input.csv]" << std::endl, 1);

	BitcoinExchange	B;

	if (B.fillMap())
		return (2);
	if (B.recupInput(av[1]))
		return (3);
	
	// BitcoinExchange	copy;
	// copy = B;
	// copy.printMap();

	// BitcoinExchange	copyConstr(B);
	// copyConstr.printMap();
	
	return (0);
}
