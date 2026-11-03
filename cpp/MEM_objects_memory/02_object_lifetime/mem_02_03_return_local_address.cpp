#include <iostream>

int* getStaticValue()
{
	static int value{ 10 };
	return &value;
}

int* createDynamicValue(int value)
{
	int* ptr{ new int{value} };
	return ptr;
}

int getValueByCopy()
{
	int value{ 30 };
	return value;
}

void modifyExisting(int* ptr, int amount)
{
	if(ptr != nullptr)
		*ptr += amount;
}

int main()
{
	int* ptr1{ getStaticValue() };
	int* ptr2{ getStaticValue() };
	if (ptr1 == ptr2)
		std::cout << "Same adress so same object" << std::endl;
	else
	{
		std::cerr << "Something is wrong with getStaticValue()" << std::endl;
		return 1;
	}

	int* ptr3 = createDynamicValue(50);
	std::cout << "After creation " << *ptr3 << std::endl;
	modifyExisting(ptr3, 10);
	std::cout << "After modification " << *ptr3 << std::endl;

	int copy{ getValueByCopy() };
	std::cout << "copy = " << copy << std::endl;

	delete ptr3;
	ptr3 = nullptr;

	std::cout << "null pointer: " << ptr3;
}

/*
int* getLocalAddress()
{
	int local{ 100 };
	return &local;
}
Dangerous little thing because you are sending back a pointer to an object that will be destroyed
when exiting from getLocalAddress()
*/