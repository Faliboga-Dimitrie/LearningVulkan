#include <iostream>

struct Tracer
{
	int id;

	Tracer(int value) : id{ value }
	{
		std::cout << "Constructed " << this->id << std::endl;
	}

	~Tracer()
	{
		std::cout << "Destroyed " << this->id << std::endl;
	}
};

void inspectOrder(bool condition)
{
	Tracer t1{ 1 };

	if (condition)
	{
		Tracer t2{ 2 };
		Tracer t3{ 3 };
	}
	else
	{
		Tracer t2{ 2 };//Messing with names haha
	}

	for (int i{ 0 }; i < 3; ++i)
	{
		Tracer t3{ 69 };
		static Tracer t1{ 10 + i }; 
	}

	Tracer t4{ 12 };
	std::cout << "Congrats, out of the function you go!" << std::endl << std::endl;
}

int main()
{
	inspectOrder(true);
	inspectOrder(false);
	std::cout << "the program ended!";
}