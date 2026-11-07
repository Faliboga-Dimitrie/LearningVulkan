#include <iostream>
#include <limits>

bool readAt(const int* data, int count, int index, int& result)
{
	if (data == nullptr)
		return false;

	if (count <= 0)
		return false;

	if (index >= count || index < 0)
		return false;

	result = data[index];
	return true;
}

bool incrementSafely(int& value)
{
	if (value != std::numeric_limits<int>::max())
	{
		value++;
		return true;
	}

	return false;
}

int main()
{
	int values[3]{ 10,20,30 };
	int result{ -1 };
	int index{ -1 };

	std::cout << "Result before call: " << result << std::endl;
	std::cout << std::boolalpha << "Index is " << index << " readAt is " << readAt(values, 3, index, result) << std::endl;
	std::cout << "Result after call: " << result << std::endl;

	++index;

	std::cout << "Result before call: " << result << std::endl;
	std::cout << std::boolalpha << "Index is " << index << " readAt is " << readAt(values, 3, index, result) << std::endl;
	std::cout << "Result after call: " << result << std::endl;

	index += 2;

	std::cout << "Result before call: " << result << std::endl;
	std::cout << std::boolalpha << "Index is " << index << " readAt is " << readAt(values, 3, index, result) << std::endl;
	std::cout << "Result after call: " << result << std::endl;

	++index;

	std::cout << "Result before call: " << result << std::endl;
	std::cout << std::boolalpha << "Index is " << index << " readAt is " << readAt(values, 3, index, result) << std::endl;
	std::cout << "Result after call: " << result << std::endl;

	++index;

	std::cout << "Result before call: " << result << std::endl;
	std::cout << std::boolalpha << "Index is " << index << " readAt is " << readAt(values, 3, index, result) << std::endl;
	std::cout << "Result after call: " << result << std::endl;

	index = 1;

	std::cout << "Result before call: " << result << std::endl;
	std::cout << std::boolalpha << "Index is " << index << " readAt is " << readAt(nullptr, 3, index, result) << std::endl;
	std::cout << "Result after call: " << result << std::endl;

	int limit_value{ std::numeric_limits<int>::max() - 1 };

	std::cout << "limit_value before call: " << limit_value << std::endl;
	std::cout << std::boolalpha << "limit_values was incremented: " << incrementSafely(limit_value) << std::endl;
	std::cout << "limit_value after call: " << limit_value << std::endl;

	std::cout << "limit_value before call: " << limit_value << std::endl;
	std::cout << std::boolalpha << "limit_values was incremented: " << incrementSafely(limit_value) << std::endl;
	std::cout << "limit_value after call: " << limit_value << std::endl;
}