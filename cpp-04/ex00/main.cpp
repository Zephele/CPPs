/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:21:57 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/02 16:51:07 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== Testing CORRECT polymorphism (with virtual) ===" << std::endl;
	std::cout << std::endl;
	
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << "Type: " << j->getType() << std::endl;
	std::cout << "Sound: ";
	j->makeSound(); // Should output: Woof woof!
	
	std::cout << std::endl;
	std::cout << "Type: " << i->getType() << std::endl;
	std::cout << "Sound: ";
	i->makeSound(); // Should output: Meow!
	
	std::cout << std::endl;
	std::cout << "Type: " << meta->getType() << std::endl;
	std::cout << "Sound: ";
	meta->makeSound(); // Should output: Some generic sound
	
	std::cout << std::endl;
	std::cout << "Deleting objects:" << std::endl;
	delete (meta);
	delete (j);
	delete (i);

	std::cout << std::endl;
	std::cout << "=== Testing WRONG polymorphism (without virtual) ===" << std::endl;
	std::cout << std::endl;
	
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << std::endl;
	std::cout << "Type: " << wrongCat->getType() << std::endl;
	std::cout << "Sound: ";
	wrongCat->makeSound(); // Should output: Some generic wrong sound (WRONG!)
	
	std::cout << std::endl;
	std::cout << "Type: " << wrongMeta->getType() << std::endl;
	std::cout << "Sound: ";
	wrongMeta->makeSound(); // Should output: Some generic wrong sound
	
	std::cout << std::endl;
	std::cout << "Deleting objects:" << std::endl;
	delete (wrongMeta);
	delete (wrongCat); // Only WrongAnimal destructor called (WRONG!)

	std::cout << std::endl;
	std::cout << "=== Testing direct instantiation ===" << std::endl;
	std::cout << std::endl;
	
	Dog directDog;
	Cat directCat;
	
	std::cout << std::endl;
	std::cout << "Direct Dog sound: ";
	directDog.makeSound();
	std::cout << "Direct Cat sound: ";
	directCat.makeSound();
	
	std::cout << std::endl;
	std::cout << "=== Testing copy constructor ===" << std::endl;
	std::cout << std::endl;
	
	Dog dog1;
	Dog dog2(dog1);
	
	std::cout << std::endl;
	std::cout << "=== Testing assignment operator ===" << std::endl;
	std::cout << std::endl;
	
	Cat cat1;
	Cat cat2;
	cat2 = cat1;
	
	std::cout << std::endl;
	std::cout << "=== End of tests (stack destructors will be called) ===" << std::endl;

	return 0;
}