#include <type_traits>
#include <iostream>

struct Plain
{
	int value;
};

struct Manual
{
	int value;

	~Manual() {}
};

struct Defaulted
{
	int value;

	~Defaulted() = default;
};

struct Composit
{
	Manual component;
};

struct NonCopyable
{
	int value{ 10 };

	NonCopyable() = default;

	NonCopyable(const NonCopyable&) = delete;
};

struct Container
{
	NonCopyable item;
};

int main()
{
	std::cout << "Plain is_trivially_destructible? " << std::boolalpha << std::is_trivially_destructible_v<Plain> << std::endl;
	std::cout << "Plain is_copy_constructible? " << std::boolalpha << std::is_copy_constructible_v<Plain> << std::endl;

	static_assert(!std::is_trivially_destructible_v<Manual>, "Manual destructor shouldn't be trivial");
	static_assert(std::is_copy_constructible_v<Manual>, "Manual should have a copy constructor");
	std::cout << "Manual is_trivially_destructible? " << std::boolalpha << std::is_trivially_destructible_v<Manual> << std::endl;
	std::cout << "Manual is_copy_constructible? " << std::boolalpha << std::is_copy_constructible_v<Manual> << std::endl;

	static_assert(std::is_trivially_destructible_v<Defaulted>, "destructor should be trivial");
	static_assert(std::is_copy_constructible_v<Defaulted>, "Defaulted should have a copy constructor");
	std::cout << "Defaulted is_trivially_destructible? " << std::boolalpha << std::is_trivially_destructible_v<Defaulted> << std::endl;
	std::cout << "Defaulted is_copy_constructible? " << std::boolalpha << std::is_copy_constructible_v<Defaulted> << std::endl;

	static_assert(!std::is_trivially_destructible_v<Composit>, "Composit destructor shouldn't be trivial");
	std::cout << "Composit is_trivially_destructible? " << std::boolalpha << std::is_trivially_destructible_v<Composit> << std::endl;
	std::cout << "Composit is_copy_constructible? " << std::boolalpha << std::is_copy_constructible_v<Composit> << std::endl;

	static_assert(!std::is_copy_constructible_v<NonCopyable>, "NonCopyable shouldn't have a copy constructor");
	std::cout << "NonCopyable is_trivially_destructible? " << std::boolalpha << std::is_trivially_destructible_v<NonCopyable> << std::endl;
	std::cout << "NonCopyable is_copy_constructible? " << std::boolalpha << std::is_copy_constructible_v<NonCopyable> << std::endl;

	static_assert(!std::is_copy_constructible_v<Container>, "Container shouldn't have a copy constructor");
	std::cout << "Container is_trivially_destructible? " << std::boolalpha << std::is_trivially_destructible_v<Container> << std::endl;
	std::cout << "Container is_copy_constructible? " << std::boolalpha << std::is_copy_constructible_v<Container> << std::endl;
}