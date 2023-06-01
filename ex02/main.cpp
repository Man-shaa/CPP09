/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:11:24 by msharifi          #+#    #+#             */
/*   Updated: 2023/06/01 18:35:59 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int ac, char **av)
{
	std::vector<int>	vect;
	std::vector<int>	*vectTab;
	int					vectTabSize;

	if (ac < 2)
		return (std::cerr << "tuto : ./PmergeMe + positive integer sequence" << std::endl , 1);
	std::clock_t	start = clock();
	if (fillVect(vect, ac, av))
		return (2);

	std::cout << "Sequence non triee : ";
	printVector(vect);
	vectTab = FillVectTab(vect, &vectTabSize);
	printVectorTab(vectTab, vectTabSize);
	sortPair(vectTab, vectTabSize);
	std::cout << "APRES SORTPAIR" << std::endl;
	printVectorTab(vectTab, vectTabSize);
	double time = 1000000.0 * (clock() - start) / CLOCKS_PER_SEC;
	std::cout << time << " ms" << std::endl;
	delete[] (vectTab);
	return (0);
}
