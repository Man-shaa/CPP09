/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:25:08 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/31 18:51:02 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cerr << "tuto : ./RPN [\"rpn expression\"]" << std::endl, 1);

	std::stack<int>	stack;
	std::string		expression = av[1];
	if (fillStack(expression, stack))
		return (2);
	return (0);
}