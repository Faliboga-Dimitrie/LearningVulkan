#include <iostream>

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

void inspect(const Tracer& ref)
{
	std::cout << "Inspect " << ref.id << std::endl;
}

const Tracer& forward(const Tracer& ref)
{
	return ref;
}

int main()
{
	std::cout << "BEGIN\n\n";

	Tracer{ 1 };
	std::cout << "AFTER_DIRECT\n";

	const Tracer& extended{ Tracer{2} };
	std::cout << "AFTER_EXTENDED\n extended id = " << extended.id << std::endl;

	inspect(Tracer{ 3 });
	std::cout << "AFTER_INSPECT\n";

	{
		Tracer named{ 4 };
		const Tracer& forwareded{ forward(named) };

		std::cout << "named id = " << forwareded.id << std::endl;

		const Tracer& dangling{ forward(Tracer{5}) };
		std::cout << "AFTER_FORWARD_TEMP\n";
		//dangling is a dangling ref because Tracer{5} was destryed at the end of the compleate expression
		//const Tracer& dangling{ forward(Tracer{5}) }; after returning from forward, not in forward 
		//or at exit from forward!
	}

	std::cout << "END_MAIN\n";
}