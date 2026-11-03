#include <iostream>
#include <memory>

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

struct Device
{
	Tracer first{ 10 };
	std::unique_ptr<Tracer> owned{
		std::make_unique<Tracer>(30)
	};
	Tracer second{ 20 };

	Device()
	{
		std::cout << "Device Constructor\n";
		throw int{ 99 };
	}

	~Device()
	{
		std::cout << "Device Destructor\n";
	}
};

void inner()
{
	Tracer innerObject{ 4 };

	{
		Tracer nestedObject{ 5 };

		std::cout << "THROWING\n";

		throw int{ 77 };
	}
}

void middle()
{
	Tracer middleObject{ 3 };

	inner();

	std::cout << "MIDDLE_END\n";
}

void createDevice()
{
	Device device;
	std::cout << "DEVICE_READY\n";
}

int main()
{
	Tracer root{ 1 };

	try 
	{
		Tracer guard{ 2 };

		middle();

		std::cout << "AFTER_MIDDLE\n";
	}
	catch (int error)
	{
		Tracer handler{ 6 };
		std::cout << "CAUGHT " << error << std::endl;
	}

	try
	{
		createDevice();
	}
	catch (int error)
	{
		std::cout << "DEVICE_CAUGHT " << error << std::endl;
	}

	std::cout << "END_MAIN\n";

	return 0;
}