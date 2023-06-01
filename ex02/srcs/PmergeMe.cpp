/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:11:19 by msharifi          #+#    #+#             */
/*   Updated: 2023/06/01 17:25:57 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	fillVect(std::vector<int> &vect, int ac, char **av)
{
	int	number;

	for (int i = 1; i < ac; i++)
	{
		std::istringstream	iss(av[i]);
		if (iss >> number && number >= 0)
			vect.push_back(number);
		else
			return (std::cerr << av[i] << " : is not a positiv integer" << std::endl, 1);
	}
	return (0);
}

std::vector<int>	*FillVectTab(std::vector<int> &vect, int *vectTabSize)
{
	*vectTabSize = vect.size();
	if (*vectTabSize % 2 != 0)
		(*vectTabSize)++;
	*vectTabSize /= 2;
	std::vector<int>	*vectTab = new std::vector<int>[*vectTabSize];
	for (int i = 0; i < *vectTabSize; i ++)
	{
		vectTab[i].push_back(vect.back());
		vect.pop_back();

		if (vect.empty() == false)
		{
			vectTab[i].push_back(vect.back());
			vect.pop_back();
		}
	}
	return (vectTab);
}

void	sortPair(std::vector<int> *vectTab, int vectTabSize)
{
	for (int i = 0; i < vectTabSize; i++)
	{
		for (int j = 0; j < static_cast<int>(vectTab[i].size()) && vectTab[i].empty() == false; j++)
		{
			if (vectTab[i].front() > vectTab[i].back())
				std::swap(vectTab[i][0], vectTab[i][1]);
		}
	}
}

void	printVector(const std::vector<int> vect)
{
	for (std::vector<int>::const_iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

}

void	printVectorTab(const std::vector<int> *vectTab, int vectTabSize)
{
	for (int i = 0; i < vectTabSize; i++) {
		std::cout << "Vecteur " << i << ": ";
		for (int j = 0; j < static_cast<int>(vectTab[i].size()); ++j) {
			std::cout << vectTab[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
