/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:11:24 by msharifi          #+#    #+#             */
/*   Updated: 2023/06/01 23:20:22 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	std::vector<int> vect;
	std::list<int> list;

	if (ac < 3)
		return (std::cerr << "tuto : ./PmergeMe + 2 or more positive integer sequence" << std::endl , 1);
	if (vectorSort(vect, ac, av))
		return (2);
	ListSort(list, ac, av);
	return (0);
}
