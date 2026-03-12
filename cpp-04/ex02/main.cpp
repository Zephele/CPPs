/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratanaka <ratanaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 15:21:57 by ratanaka          #+#    #+#             */
/*   Updated: 2026/03/11 15:52:02 by ratanaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
// 	std::cout << "=== Testing CORRECT polymorphism (with virtual) ===" << std::endl;
// 	std::cout << std::endl;
	
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();

// 	std::cout << std::endl;
// 	std::cout << "Type: " << j->getType() << std::endl;
// 	std::cout << "Sound: ";
// 	j->makeSound(); // Should output: Woof woof!
	
// 	std::cout << std::endl;
// 	std::cout << "Type: " << i->getType() << std::endl;
// 	std::cout << "Sound: ";
// 	i->makeSound(); // Should output: Meow!
	
// 	std::cout << std::endl;
// 	std::cout << "Type: " << meta->getType() << std::endl;
// 	std::cout << "Sound: ";
// 	meta->makeSound(); // Should output: Some generic sound
	
// 	std::cout << std::endl;
// 	std::cout << "Deleting objects:" << std::endl;
// 	delete (meta);
// 	delete (j);
// 	delete (i);

// 	std::cout << std::endl;
// 	std::cout << "=== Testing WRONG polymorphism (without virtual) ===" << std::endl;
// 	std::cout << std::endl;
	
// 	const WrongAnimal* wrongMeta = new WrongAnimal();
// 	const WrongAnimal* wrongCat = new WrongCat();

// 	std::cout << std::endl;
// 	std::cout << "Type: " << wrongCat->getType() << std::endl;
// 	std::cout << "Sound: ";
// 	wrongCat->makeSound(); // Should output: Some generic wrong sound (WRONG!)
	
// 	std::cout << std::endl;
// 	std::cout << "Type: " << wrongMeta->getType() << std::endl;
// 	std::cout << "Sound: ";
// 	wrongMeta->makeSound(); // Should output: Some generic wrong sound
	
// 	std::cout << std::endl;
// 	std::cout << "Deleting objects:" << std::endl;
// 	delete (wrongMeta);
// 	delete (wrongCat); // Only WrongAnimal destructor called (WRONG!)

// 	std::cout << std::endl;
// 	std::cout << "=== Testing direct instantiation ===" << std::endl;
// 	std::cout << std::endl;
	
// 	Dog directDog;
// 	Cat directCat;
	
// 	std::cout << std::endl;
// 	std::cout << "Direct Dog sound: ";
// 	directDog.makeSound();
// 	std::cout << "Direct Cat sound: ";
// 	directCat.makeSound();
	
// 	std::cout << std::endl;
// 	std::cout << "=== Testing copy constructor ===" << std::endl;
// 	std::cout << std::endl;
	
// 	Dog dog1;
// 	Dog dog2(dog1);
	
// 	std::cout << std::endl;
// 	std::cout << "=== Testing assignment operator ===" << std::endl;
// 	std::cout << std::endl;
	
// 	Cat cat1;
// 	Cat cat2;
// 	cat2 = cat1;
	
// 	std::cout << std::endl;
// 	std::cout << "=== End of tests (stack destructors will be called) ===" << std::endl;

// 	return 0;
// }
	
int main()
{
	const int N = 4;
	// Animal animal; test
	Animal* animals[N];

	std::cout << "\033[1;32m\n--- Creating animals array (half Dogs, half Cats) ---\n\033[0m" << std::endl;
	for (int i = 0; i < N; ++i)
	{
		if (i < N / 2){
			std::cout << std::endl;
			animals[i] = new Dog();
			Dog* dog = dynamic_cast<Dog*>(animals[i]);
			std::cout << "\033[1;35m\n====================================\033[0m" << std::endl;
			std::cout << "	Sounds and Ideas:\n" << std::endl;
			if (i % 2 == 0)
				dog->getBrain()->setIdea(i, "Going for a walk");
			else
				dog->getBrain()->setIdea(i, "Playing fetch");
			std::cout << "\033[1;32mDog: \033[0m";
			dog->makeSound();
			std::cout << "\033[1;32mDog: \033[0m";
			std::cout << dog->getBrain()->getIdea(i);
			std::cout << "\033[1;35m\n====================================\033[0m" << std::endl;
		}
		else {
			std::cout << std::endl;
			animals[i] = new Cat();
			std::cout << "\033[1;35m\n====================================\033[0m" << std::endl;
			std::cout << "	Sounds and Ideas:\n" << std::endl;
			Cat* cat = dynamic_cast<Cat*>(animals[i]);
			if (i % 2 == 0)
				cat->getBrain()->setIdea(i, "Watching birds");
			else
				cat->getBrain()->setIdea(i, "Taking a nap");
			std::cout << "\033[1;32mCat: \033[0m";
			cat->makeSound();
			std::cout << "\033[1;32mCat: \033[0m";
			std::cout << cat->getBrain()->getIdea(i);
			std::cout << "\033[1;35m\n====================================\033[0m" << std::endl;
		}
	}
	std::cout << "\033[1;32m\n--- Deleting animals array via Animal* ---\n\033[0m" << std::endl;
	for (int i = 0; i < N; ++i)
		delete animals[i];
	std::cout << std::endl;

	std::cout << "\033[1;32m--- Testing deep copy ---\033[0m" << std::endl;
	Dog originalDog;
	originalDog.getBrain()->setIdea(0, "Protect the house");
	Dog copiedDog(originalDog);
	std::cout << "\033[1;32m------\033[0m" << std::endl;
	std::cout << "Original Dog idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Dog idea: " << copiedDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "\033[1;32m------\033[0m" << std::endl;
	copiedDog.getBrain()->setIdea(0, "Chase the ball");
	std::cout << "Original Dog idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Dog idea: " << copiedDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "\033[1;32m------\033[0m" << std::endl;

	Cat originalCat;
	originalCat.getBrain()->setIdea(1, "Sleep on the sofa");
	Cat assignedCat;
	assignedCat = originalCat;
	std::cout << "\033[1;32m------\033[0m" << std::endl;
	std::cout << "Original Cat idea: " << originalCat.getBrain()->getIdea(1) << std::endl;
	std::cout << "Assigned Cat idea: " << assignedCat.getBrain()->getIdea(1) << std::endl;
	std::cout << "\033[1;32m------\033[0m" << std::endl;
	assignedCat.getBrain()->setIdea(1, "Climb the curtain");
	std::cout << "Original Cat idea: " << originalCat.getBrain()->getIdea(1) << std::endl;
	std::cout << "Assigned Cat idea: " << assignedCat.getBrain()->getIdea(1) << std::endl;
	std::cout << "\033[1;32m------\033[0m" << std::endl;

	return 0;
}
