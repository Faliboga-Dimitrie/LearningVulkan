#include <iostream>

void inspectLifetime()
{
	int value;
	value = 10;
	std::cout << "Value: " << value << std::endl;

	int* ptr_1 = nullptr;
	ptr_1 = new int;

	int* ptr_2{ ptr_1 };
	*ptr_1 = 100;
	std::cout << "Dynamically alocated int value: " << *ptr_2 << std::endl;

	{
		int value{ 12 };
		std::cout << "Hello, I am Value from inner block: " << value << std::endl;
	}

	std::cout << "The Value inside the inner block sadly passed away, now it's only me, Value from outer block: " << value << std::endl << std::endl;

	delete ptr_1;
	ptr_1 = nullptr;
	ptr_2 = nullptr;
}

int main()
{
	inspectLifetime();
	inspectLifetime();

	return 0;
}