/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:30:47 by msharifi          #+#    #+#             */
/*   Updated: 2023/05/31 19:09:10 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool	isOperation(std::string &token)
{
	if (token == "+" || token == "-" || token == "*" || token == "/")
		return (true);
	return (false);
}

void	printStack(std::stack<int> stack)
{
	std::stack<int> tempStack = stack;

    while (!tempStack.empty())
	{
        std::cout << tempStack.top() << " ";
        tempStack.pop();
    }
    std::cout << std::endl;
}

bool	exeOperation(std::string token, std::stack<int> &stack)
{
	if (stack.size() <= 1)
		return (std::cerr << "Not enough numbers to operate with " << token << std::endl, true);
	int	n2 = stack.top();
	stack.pop();
	int	n1 = stack.top();
	stack.pop();

	if (token == "+")
		stack.push(n1 + n2);
	else if (token == "-")
		stack.push(n1 - n2);
	else if (token == "*")
		stack.push(n1 * n2);
	else if (token == "/")
	{
		if (n2 == 0)
			return (std::cerr << "Can't divide by 0 !" << std::endl, true);
		stack.push(n1 / n2);
	}
	return (false);
}

bool	fillStack(std::string &expression, std::stack<int> stack)
{
	std::istringstream	iss(expression);
	std::string			token;

	while (iss >> token)
	{
		if (token.size() != 1 || (!std::isdigit(token[0]) && !isOperation(token)))
			return (std::cerr << "Invalid input : " << token[0] << std::endl, true);
		else if (std::isdigit(token[0]))
			stack.push(token[0] - 48);
		else if (isOperation(token))
			if (exeOperation(token, stack))
				return (1);
	}
	printStack(stack);
	return (0);
}
