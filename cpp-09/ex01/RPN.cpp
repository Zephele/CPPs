/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:45:44 by ratanaka          #+#    #+#             */
/*   Updated: 2026/05/22 00:45:12 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//==========================================//
//				CONSTRUCTORS				//
//==========================================//

RPN::RPN(): _nums(std::stack<int>()){}

RPN::RPN(const RPN& other): _nums(other._nums){}

RPN& RPN::operator=(const RPN& other){
	if (this != &other)
		_nums = other._nums;
	return *this;
}

RPN::~RPN(){}

//==========================================//
//				FUNCTIONS					//
//==========================================//

static int takeNumber(std::string expression, std::size_t *i){
	int			numConverted;
	std::string numString;
	while (isdigit(expression[*i])){
		numString += expression[*i];
		*i += 1;
	}
	return (numConverted = atoi(numString.c_str()));
}

void RPN::calcExpression(char expr, bool *error){
	int	num1, num2; 

	num1 = _nums.top();
	_nums.pop();
	num2 = _nums.top();
	_nums.pop();

	switch (expr)
	{
		case '+':
			_nums.push(num2 + num1);
			break;
		case '-':
			_nums.push(num2 - num1);
			break;
		case '*':
			_nums.push(num2 * num1);
			break;
		case '/':
			if (num1 == 0) {
				std::cout << "Error" << std::endl;
				*error = true;
				return ;
			} else { _nums.push(num2 / num1); }
			break;
		default:
			break;
	}
}

void	RPN::calculator(std::string expression){
	bool	error = false;
	int		tempNum = 0;
	for (std::size_t i = 0; i < expression.size(); i++){
		if (expression[i] == ' ' || expression[i] == '\t'){continue;}
		if (isdigit(expression[i])) {
			tempNum = takeNumber(expression, &i);
			if (tempNum < 0 || tempNum > 10) {
				std::cout << "Error" << std::endl;
				return ;
			} else {_nums.push(tempNum);}	
		} else {
			calcExpression(expression[i], &error);
			if (error)
				return ;
		}
	}
	std::cout << _nums.top() << std::endl;
}
