#include <iostream>

void inspectStorage()
{
	int value{ 10 };
	int* ptr_value{ &value };

	int* ptr_new{ new int{20} };
	int* ptr_new_second{ ptr_new };

	std::cout << "Value adress: " << &value << std::endl;
	std::cout << "ptr_value adress: " << &ptr_value << std::endl;
	std::cout << "ptr_new adress: " << &ptr_new << std::endl;
	std::cout << "ptr_new_second adress: " << &ptr_new_second << std::endl;

	std::cout << "ptr_value stored adress: " << ptr_value << " ptr_value value at adress: " << *ptr_value << std::endl;
	std::cout << "ptr_new stored adress: " << ptr_new << " ptr_new value at adress: " << *ptr_new << std::endl;
	std::cout << "ptr_new_second stored adress: " << ptr_new_second << " ptr_new_second value at adress: " << *ptr_new_second << std::endl;

	*ptr_new_second = 75;
	std::cout << "new value from ptr_new_second: " << *ptr_new_second << std::endl;
	std::cout << "new value from ptr_new: " << *ptr_new << std::endl;

	delete ptr_new;
	//delete ptr_new_second; //- this will probably cause a crash because the memory pointed by ptr_new_second has been already freed.
}

int main()
{
	inspectStorage();
	return 0;
}