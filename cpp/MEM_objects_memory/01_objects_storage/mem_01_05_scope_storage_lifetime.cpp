#include <iostream>

void inspectScope()
{
	static int counter{ 0 };
	int value{ 9 };
	int* ptr{ &value };

	{
		int value{ 99 };

		++value;
		++*ptr;

		std::cout << "Inner block: value = " << value << " *ptr = " << *ptr << std::endl;
	}

	std::cout << "Outer block: value = " << value << " *ptr = " << *ptr 
		<< " different from inner block for value because at the exit from the inner"
		<< " block the value declared inside ceased to exist" << std::endl;

	++counter;

	std::cout << "Counter = " << counter << std::endl;

	int* s_ptr{ nullptr };

	{
		int value{ 10 };
		s_ptr = &value;

		std::cout << "Inside block: " << *s_ptr << std::endl;
	}

	// The pointed-to object's lifetime has ended.
	std::cout << "Pointer object is still alive, "
		"but its pointee is not." << std::endl << std::endl;

	s_ptr = nullptr;
}

int main()
{
	inspectScope();
	inspectScope();

	return 0;
}