/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:11:24 by msharifi          #+#    #+#             */
/*   Updated: 2023/06/01 20:00:21 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	std::vector<int>	vect;

	if (ac < 2)
		return (std::cerr << "tuto : ./PmergeMe + positive integer sequence" << std::endl , 1);
	std::clock_t	start = clock();
	if (fillVect(vect, ac, av))
		return (2);

	std::cout << "Sequence non triee : ";
	printVector(vect);
	divideVector(vect, 0, vect.size() - 1);
	std::cout << "After sort : ";
	printVector(vect);
	double time = 1000000.0 * (clock() - start) / CLOCKS_PER_SEC;
	std::cout << time << " ms" << std::endl;
	return (0);
}
