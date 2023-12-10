/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:40:52 by crepou            #+#    #+#             */
/*   Updated: 2023/12/10 20:26:40 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::Rpn(void)
{
	return ;
}

Rpn::Rpn(Rpn const & src)
{
	*this = src;
	return ;
}

Rpn::~Rpn(void)
{
	return ;
}

Rpn & Rpn::operator=(Rpn const & obj)
{
	if (this != &obj)
		this->num_stack = obj.num_stack;
	return (*this);
}

int Rpn::getResult( std::string str )
{
	unsigned long i = 0;
	if (str.length() == 0)
	{
		std::cout << "Error: invalid expression" << std::endl;
		return -1;
	}
	for (; i < str.length(); i++)
	{
		if (i % 2 == 0 && (str[i] == '+'))
		{
			if (num_stack.size() < 2)
			{
				std::cout << "Error: invalid expression" << std::endl;
				return -1;
			}
			int result = num_stack.top();
			num_stack.pop();
			result = num_stack.top() + result;
			num_stack.pop();
			num_stack.push(result);
		} else if (i % 2 == 0 && (str[i] == '-'))
		{
			if (num_stack.size() < 2)
			{
				std::cout << "Error: invalid expression" << std::endl;
				return -1;
			}
			int result = num_stack.top();
			num_stack.pop();
			result = num_stack.top() - result;
			num_stack.pop();
			num_stack.push(result);
		} else if (i % 2 == 0 && (str[i] == '*'))
		{
			if (num_stack.size() < 2)
			{
				std::cout << "Error: invalid expression" << std::endl;
				return -1;
			}
			int result = num_stack.top();
			num_stack.pop();
			result = num_stack.top() * result;
			num_stack.pop();
			num_stack.push(result);
		} else if (i % 2 == 0 && (str[i] == '/'))
		{
			if (num_stack.size() < 2)
			{
				std::cout << "Error: invalid expression" << std::endl;
				return -1;
			}
			int result = num_stack.top();
			num_stack.pop();
			result = num_stack.top() / result;
			num_stack.pop();
			num_stack.push(result);
		}
		else if (i % 2 == 0 && (str[i] >= '0' && str[i] <= '9'))
			num_stack.push(str[i] - '0');
		else if (i % 2 == 1 && str[i] == ' ')
			continue;
		else
		{
			std::cout << "Error: invalid character" << std::endl;
			return -1;
		}
	}
	return num_stack.top();
}
