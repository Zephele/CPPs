/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 16:13:11 by ratanaka          #+#    #+#             */
/*   Updated: 2026/04/23 22:17:31 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>
# include "Array.hpp"

template <typename T>
static void	printArray(const Array<T>& arr, const std::string& name)
{
	std::cout << name << " (size=" << arr.size() << "): ";
	for (unsigned int i = 0; i < arr.size(); ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

int	main(void)
{
	try
	{
		std::cout << "=== Default constructor ===" << std::endl;
		Array<int> empty;
		std::cout << "empty.size() = " << empty.size() << std::endl;

		std::cout << "\n=== Int array fill/access ===" << std::endl;
		Array<int> nums(5);
		for (unsigned int i = 0; i < nums.size(); ++i)
			nums[i] = static_cast<int>(i * 10);
		printArray(nums, "nums");

		std::cout << "\n=== Copy constructor (deep copy) ===" << std::endl;
		Array<int> copy(nums);
		nums[0] = 999;
		printArray(nums, "nums (modified)");
		printArray(copy, "copy (must stay unchanged)");

		std::cout << "\n=== Assignment operator ===" << std::endl;
		Array<int> assigned;
		assigned = nums;
		nums[1] = 777;
		printArray(nums, "nums (modified again)");
		printArray(assigned, "assigned (must stay unchanged)");

		std::cout << "\n=== Const access ===" << std::endl;
		const Array<int> constNums(copy);
		std::cout << "constNums[2] = " << constNums[2] << std::endl;

		std::cout << "\n=== Bounds check ===" << std::endl;
		std::cout << "Trying nums[42]..." << std::endl;
		std::cout << nums[42] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}

