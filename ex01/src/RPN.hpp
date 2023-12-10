/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crepou <crepou@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 23:37:39 by crepou            #+#    #+#             */
/*   Updated: 2023/12/10 20:25:53 by crepou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class Rpn
{
	private:
		std::stack<int> num_stack;
		
	public:
	 	Rpn(void);
		Rpn(Rpn const & src);
		~Rpn(void);
		Rpn & operator=(Rpn const & obj);

		int getResult(std::string str);
};

#endif