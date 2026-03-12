/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:45:04 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/02 09:18:46 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << '\n';
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string str(argv[i]);
		for (int j = 0; j < (int)str.length(); j++)
			str[j] = std::toupper(str[j]);
		std::cout << str;
	}
	std::cout << '\n';
	return (0);
}