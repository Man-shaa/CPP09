/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:11:21 by msharifi          #+#    #+#             */
/*   Updated: 2023/06/01 17:21:50 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <list>
# include <ctime>

int					fillVect(std::vector<int> &vect, int ac, char **av);
void				printVector(const std::vector<int> vect);
std::vector<int>	*FillVectTab(std::vector<int> &vect, int *vectTabSize);
void				printVectorTab(const std::vector<int> *vectTab, int vectTabSize);
void				sortPair(std::vector<int> *vectTab, int vectTabSize);

#endif
