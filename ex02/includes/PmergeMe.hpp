/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 19:11:21 by msharifi          #+#    #+#             */
/*   Updated: 2023/06/01 19:33:20 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <list>
# include <ctime>

int		fillVect(std::vector<int> &vect, int ac, char **av);
void	printVector(const std::vector<int> vect);
void	divideVector(std::vector<int> &vect, int left, int right);
void	mergeVector(std::vector<int> &vect, int left, int mid, int right);

#endif
