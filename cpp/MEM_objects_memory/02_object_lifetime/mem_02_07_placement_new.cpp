#include <cstddef>
#include <iostream>
#include <new>

struct Tracer
{
	int id;

	Tracer(int value) : id{ value }
	{
		std::cout << "Construct " << this->id << std::endl;
	}

	~Tracer()
	{
		std::cout << "Destroy " << this->id << std::endl;
	}
};

int main()
{
	Tracer root{ 1 };
	alignas(Tracer) std::byte slotA[ sizeof(Tracer) ];
	alignas(Tracer) std::byte slotB[ sizeof(Tracer) ];

	Tracer* first = ::new (static_cast<void*>(slotA)) Tracer{ 10 };
	Tracer* second = ::new(static_cast<void*>(slotB)) Tracer{ 20 };

	std::cout << "POINT_A\n";
	std::cout << "first id = " << first->id << std::endl;
	std::cout << "second id = " << second->id << std::endl;

	first->~Tracer();

	std::cout << "POINT_B\n";

	Tracer* third = ::new(static_cast<void*>(slotA)) Tracer{ 30 };

	std::cout << "POINT_C\n";
	std::cout << "thrid id = " << third->id << std::endl;
	std::cout << "second id = " << second->id << std::endl;

	second->~Tracer();

	std::cout << "POINT_D\n";

	third->~Tracer();

	std::cout << "END_MAIN\n";
}