/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:11:19 by msharifi          #+#    #+#             */
/*   Updated: 2023/06/01 19:51:57 by msharifi         ###   ########.fr       */
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

void	printVector(const std::vector<int> vect)
{
	for (std::vector<int>::const_iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

}

void	divideVector(std::vector<int> &vect, int left, int right)
{
	if (left < right)
	{
		int	mid = (left + right) / 2;
		divideVector(vect, left, mid);
		divideVector(vect, mid + 1, right);
		mergeVector(vect, left, mid, right);
	}
}

void	mergeVector(std::vector<int> &vect, int left, int mid, int right)
{
	int	leftVectSize = mid - left + 1;
	int	rightVectSize = right - mid;

	std::vector<int>	leftVect(leftVectSize);
	std::vector<int>	rightVect(rightVectSize);

	// Creer deux vecteurs correspondants au deux parties de la sequence qu'on veut merge (deux pairs)
	
	for (int i = 0; i < leftVectSize; i++)
		leftVect[i] = vect[left + i];
	for (int i = 0; i < rightVectSize; i++)
		rightVect[i] = vect[mid + i + 1];

	// Merge les 2 vecteurs ensembles en les triant par insertion

	int	i = 0, j = 0, k = left;
	while (i < leftVectSize && j < rightVectSize)
	{
		if (leftVect[i] < rightVect[j])
		{
			vect[k] = leftVect[i];
			i++;
		}
		else
		{
			vect[k] = rightVect[j];
			j++;
		}
		k++;
	}

	// Copie du reste de la sequence

	while (i < leftVectSize)
	{
		vect[k] = leftVect[i];
		k++;
		i++;
	}
	while (j < rightVectSize)
	{
		vect[k] = rightVect[j];
		k++;
		j++;
	}
}

