/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:11:21 by msharifi          #+#    #+#             */
/*   Updated: 2023/06/01 23:14:47 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <list>
# include <ctime>

bool	isDigit(char *str);

// VECTOR

int		vectorSort(std::vector<int> &vect, int ac, char **av);
int		fillVect(std::vector<int> &vect, int ac, char **av);
void	printVector(const std::vector<int> vect);
void	divideVector(std::vector<int> &vect, int left, int right);
void	mergeVector(std::vector<int> &vect, int left, int mid, int right);

// LIST
void	ListSort(std::list<int> &list, int ac, char **av);
void	fillList(std::list<int> &list, int ac, char **av);
void	printList(const std::list<int> list);
void	divideList(std::list<int> &list, std::list<int>::iterator left, std::list<int>::iterator right);
void	mergeList(std::list<int>::iterator left, std::list<int>::iterator mid,std::list<int>::iterator right);

#endif
