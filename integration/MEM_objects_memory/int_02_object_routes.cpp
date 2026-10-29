#include <iostream>

int* getSharedValue()
{
	static int value{ 0 };
	return &value;
}

void auditRound()
{
	int value{ 0 };
	int* ptr_1{ &value };
	int* ptr_2{ &value };
	int* d_ptr{ new int{10} };

	{
		int value{ 0 };
		ptr_2 = &value;

		*ptr_1 += 10;
		*ptr_2 += 15;

		std::cout << "Outer block value: " << *ptr_1 << " and memory adress: " << ptr_1 << std::endl;
		std::cout << "Inner block value: " << *ptr_2 << " and memory adress: " << ptr_2 << std::endl;
	}

	ptr_2 = &value;
	*ptr_2 += 10;
	std::cout << "Outer value through first pointer: " << *ptr_1 << " = " << *ptr_2 << std::endl;

	*d_ptr *= 10;
	std::cout << "Dynamically alocated value: " << *d_ptr << std::endl;

	delete d_ptr;
	d_ptr = getSharedValue();

	++*d_ptr;
	std::cout << "Static value is " << *d_ptr << std::endl << std::endl;
}

int main()
{
	auditRound();
	auditRound();

	return 0;
}