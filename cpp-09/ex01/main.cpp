/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/20 16:45:47 by ratanaka          #+#    #+#             */
/*   Updated: 2026/05/22 00:44:47 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	firstParamChecker(std::string expression, bool *firstParam, int i, int *nums){
	if (!isdigit(expression[i]) && firstParam == false){
		std::cout << "Error" << std::endl;
		return 1;
	}
	else if (isdigit(expression[i]) && firstParam == false){
		*firstParam = true;
		nums++;
		return 0;
	}
	return 0;
}

int lastParamChecker(std::string expression){
	for (int i = expression.size(); i > 0; i--){
		if (isdigit(expression[i])){
			std::cout << "Error" << std::endl;
			return 1;
		} else if ((expression[i] == '+' || expression[i] == '-'
			|| expression[i] == '*' || expression[i] == '/')) {
				return 0;
			} else if (expression[i] == ' ' || expression[i] == '\t') {continue;}
	}
	return 0;
}

int	validExpression(std::string expression){
	bool	firstParam = false;
	int		numsBefore = 0;
	int		nums = 0;
	int		oper = 0;
	for (std::size_t i = 0; i < expression.size(); i++){
		if (expression[i] == ' ' || expression[i] == '\t'){
			continue;
		} else {			
			if (firstParamChecker(expression, &firstParam, i, &nums)) {return 1;}
			if (isdigit(expression[i])){
				nums++;
				numsBefore++;
			} else if ((expression[i] == '+' || expression[i] == '-'
				|| expression[i] == '*' || expression[i] == '/') 
					&& nums > 1 && numsBefore > 1) {
					oper++;
					numsBefore--;
					continue;
				} else {
					std::cout << "Error" << std::endl;
					return 1;
				}
			}
	}
	if ((nums < 2 && oper >= 1) || (nums == 0)){
		std::cout << "Error" << std::endl;
		return 1;
	}
	if (nums > 1) {
		return lastParamChecker(expression);
	}
	return 0;
}

int	main(int argc, char* argv[]){
	if (argc != 2) {
		std::cout << "./RPN \"1 2 +\"" << std::endl;
		return 1;
	}
	std::string _exp = argv[1];

	if (validExpression(_exp))
		return 1;
	RPN calc;
	calc.calculator(_exp);
	return 0;
}