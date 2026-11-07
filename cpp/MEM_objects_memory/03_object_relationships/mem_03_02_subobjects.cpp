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

struct Base
{
	Tracer basePart{ 10 };

	Base()
	{
		std::cout << "Base body\n";
	}

	~Base()
	{
		std::cout << "Base destructor body\n";
	}
};

struct Sensor
{
	Tracer signal{ 30 };

	Sensor()
	{
		std::cout << "Sensor body\n";
	}

	~Sensor()
	{
		std::cout << "Sensor destructor body\n";
	}
};

struct Device : Base
{
	Sensor sensor;
	Tracer localPart{ 20 };

	Device(bool fail)
	{
		std::cout << "Device body\n";

		if (fail)
			throw 7;
	}

	~Device()
	{
		std::cout << "Device destructor body\n";
	}
};

int main()
{
	Tracer root{ 1 };

	{
		Device good{ false };
		std::cout << "GOOD_READY\n";
	}

	std::cout << "BETWEEN\n";

	try 
	{
		Tracer guard{ 2 };

		Device bad{ true };

		std::cout << "BAD_READY\n";
	}
	catch (int error)
	{
		std::cout << "CAUGHT " << error << std::endl;
	}

	std::cout << "END\n";
}