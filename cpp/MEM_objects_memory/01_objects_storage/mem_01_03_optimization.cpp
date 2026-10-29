#include <iostream>

int computeDirect()
{
	int a{ 10 };
	int b{ 20 };

	return a + b;
}

int computeIndirect()
{
	int a{ 10 };
	int* p{ &a };

	*p = 30;

	return a;
}

int main()
{
	std::cout << "Direct method: " << computeDirect() << std::endl;
	std::cout << "Indirect method: " << computeIndirect() << std::endl;
	return 0;
}