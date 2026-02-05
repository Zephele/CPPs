/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 13:10:44 by ratanaka          #+#    #+#             */
/*   Updated: 2026/02/05 14:48:18 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


static void run_test(Harl &harl, const std::string &level){
	std::cout << "\n=== Test: " << level << " ===" << std::endl;
	harl.complain(level);
}

int main(){
	Harl harl;

	run_test(harl, "DEBUG");
	run_test(harl, "INFO");
	run_test(harl, "WARNING");
	run_test(harl, "ERROR");
	run_test(harl, "UNKNOWN");

	return 0;
}