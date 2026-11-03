#include <iostream>

void inspectAliases()
{
	int* owner{ new int{25} };
	int* obsever{ owner };
	int& ref{ *obsever };

	ref += 5;
	std::cout << "Value through observer: " << *obsever << std::endl;
	std::cout << "Value through ref: " << ref << std::endl;

	delete owner;
	owner = nullptr;
	obsever = nullptr;

	//ref can't be reatribuited because it acts as an alias. 
	// It's dangling because the dynamically allocated int has been freed
}

void inspectBlockLifetime()
{
	int value1{ 10 };
	int value2{ 100 };
	int* ptr{};

	ptr = &value1;
	std::cout << "value1 = " << *ptr << std::endl;

	{
		int value3{ 200 };
		ptr = &value3;
		std::cout << "value3 = " << *ptr << std::endl;
	}

	//value3 has automatic storage duration and was destroyed when the code exited the inner block
	
	ptr = &value2;
	std::cout << "value2 = " << *ptr << std::endl;
}

int main()
{
	int* ptr{};
	if (ptr == nullptr)
		std::cout << "Yeah, it's nullptr\n";

	int mainValue{ 1000 };
	ptr = &mainValue;
	std::cout << "mainValue = " << *ptr << std::endl;
	
	inspectAliases();
	inspectBlockLifetime();

	return 0;

	/*
	int* ptr{new int{10}};
	int* alias{ptr};

	delete ptr;

	Dangerous:
	- Dereferencing alias causes undefined behavior because
	  the dynamically allocated int no longer exists.

	- Deleting ptr does not automatically reset alias to nullptr.
	  After deallocation, even comparing the invalid pointer
	  with nullptr is not a portable validity check.

	- try/catch cannot reliably detect dangling pointer usage
	  because undefined behavior does not necessarily throw
	  a C++ exception.
	*/
}