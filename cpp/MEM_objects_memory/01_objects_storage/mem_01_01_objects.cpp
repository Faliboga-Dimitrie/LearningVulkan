#include <iostream>

int main()
{
	int playerHealth{ 100 };
	int enemyHealth{ 100 };

	int* selectedHealth{ &playerHealth };

	std::cout << "Valoare player health: " << playerHealth << " adresa player health: " << &playerHealth << std::endl;
	std::cout << "Valoare enemy health: " << enemyHealth << " adresa enemy health: " << &enemyHealth << std::endl << std::endl;
	std::cout << "Valoare selectedHealth: " << selectedHealth << " adresa pointer-ului: " << &selectedHealth << " Valoarea obiectului indicat: " << *selectedHealth << std::endl << std::endl;

	playerHealth = 60;

	std::cout << "Valoare player health: " << playerHealth << " adresa player health: " << &playerHealth << std::endl;
	std::cout << "Valoare enemy health: " << enemyHealth << " adresa enemy health: " << &enemyHealth << std::endl << std::endl;
	std::cout << "Valoare selectedHealth: " << selectedHealth << " adresa pointer-ului: " << &selectedHealth << " Valoarea obiectului indicat: " << *selectedHealth << std::endl << std::endl;

	return 0;
}