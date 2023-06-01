/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:11:19 by msharifi          #+#    #+#             */
/*   Updated: 2023/06/01 23:20:37 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool	isDigit(char *str)
{
	int	i = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		i++;
	if (!str[i])
		return (true);
	return (false);
}

int	vectorSort(std::vector<int> &vect, int ac, char **av)
{
	std::clock_t	start = clock();
	if (fillVect(vect, ac, av))
		return (2);

	std::cout << "Sequence non triee : ";
	printVector(vect);

	divideVector(vect, 0, vect.size() - 1);
	std::cout << "After vector sort : ";
	printVector(vect);
	double time = 1000000.0 * (clock() - start) / CLOCKS_PER_SEC;
	std::cout << "[" << time << "]" << " ms to sort with std::vector" << std::endl << std::endl;
	return (0);
}

int	fillVect(std::vector<int> &vect, int ac, char **av)
{
	int	number;

	for (int i = 1; i < ac; i++)
	{
		std::istringstream	iss(av[i]);
		if (isDigit(av[i]) && iss >> number && number >= 0)
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

void	ListSort(std::list<int> &list, int ac, char **av)
{
	std::clock_t	start = clock();
	fillList(list, ac, av);
	std::cout << "Sequence non triee : ";
	printList(list);

	divideList(list, list.begin(), list.end());
	std::cout << "After list sort : ";
	printList(list);
	double time = 1000000.0 * (clock() - start) / CLOCKS_PER_SEC;
	std::cout << "[" << time << "]" << " ms to sort with std::list" << std::endl;
}

void	fillList(std::list<int> &list, int ac, char **av)
{
	int	number;

	for (int i = 1; i < ac; i++)
	{
		std::istringstream	iss(av[i]);
		iss >> number;
		list.push_back(number);
	}
}

void	printList(const std::list<int> list)
{
	for (std::list<int>::const_iterator it = list.begin(); it != list.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	divideList(std::list<int> &list, std::list<int>::iterator left, std::list<int>::iterator right)
{
	std::list<int>::iterator	mid = left;
	int							i = 0;

	for (std::list<int>::iterator travel = left; travel != right; travel++)
		i++;
	if (i > 1)
	{
		for (int j = 0; j < i / 2; j++)
			mid++;
		divideList(list, left, mid);
		divideList(list, mid, right);
		mergeList(left, mid, right);
	}
}

void	mergeList(std::list<int>::iterator left, std::list<int>::iterator mid, std::list<int>::iterator right)
{
	std::list<int> list;

	// Merge les 2 vecteurs ensembles en les triant par insertion
	std::list<int>::iterator itLeft = left;
	std::list<int>::iterator itRight = mid;
	while (itLeft != mid && itRight != right)
	{
		if (*itLeft < *itRight)
		{
			list.push_back(*itLeft);
			itLeft++;
		}
		else if (*itRight < *itLeft)
		{
			list.push_back(*itRight);
			itRight++;
		}
		else
		{
			list.push_back(*itLeft);
			list.push_back(*itRight);
			itLeft++;
			itRight++;
		}
	}

	// Copie du reste de la sequence
	while (itLeft != mid)
	{
		list.push_back(*itLeft);
		itLeft++;
	}
	while (itRight != right)
	{
		list.push_back(*itRight);
		itRight++;
	}

	// Mettre a jour la vraie liste a partir de left jusqu'a list.end() (fin des changements de cette sequence)
	for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
	{
		*left = *it;
		left++;
	}
}
