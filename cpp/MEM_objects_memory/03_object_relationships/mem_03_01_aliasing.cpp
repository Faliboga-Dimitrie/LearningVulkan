#include <iostream>

void mutate(int& first, int& second, int amount)
{
	first += amount;
	second += first;
	amount += 100;

	std::cout << "MUTATE "
		<< first << ' '
		<< second << ' '
		<< amount << '\n';
}

void reroute(int* chosen, int* alternative)
{
	chosen = alternative;
	*chosen += 3;
}

int main()
{
	int alpha{ 10 };
	int beta{ 20 };

	int snapshot{ alpha };
	int& alias{ alpha };

	int* cursor{ &alpha };
	int* watch{ &beta };

	mutate(alpha, beta, snapshot);

	std::cout << "AFTER_1 alpha = " << alpha << 
		" beta = " << beta << " snapshot = " << snapshot << std::endl;

	mutate(alpha, alpha, beta);

	std::cout << "AFTER_2 alpha = " << alpha <<
		" beta = " << beta << " snapshot = " << snapshot << std::endl;

	reroute(cursor, watch);

	std::cout << "AFTER_3 alpha = " << alpha <<" beta = " << beta <<std::endl;

	*cursor = 7;

	std::cout << "FINAL alpha = " << alpha <<
		" beta = " << beta << " snapshot = " << snapshot<<
		" alias = " << alias << " *cursor = " << *cursor <<
		" *watch = " << *watch << std::endl;

	return 0;
}