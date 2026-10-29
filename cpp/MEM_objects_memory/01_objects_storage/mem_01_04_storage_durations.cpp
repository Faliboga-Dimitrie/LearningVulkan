#include <iostream>
#include <thread>

int globalCounter{ 1 };

void inspectStorage()
{
	int a{ 0 };
	static int b{ 0 };
	thread_local int c{ 0 };
	int* p{ new int{10} };

	++a;
	b += 5;
	c += 3;
	*p += 10;

	std::cout << "a value at function call number " << globalCounter << " is " << a << std::endl;
	std::cout << "b value at function call number " << globalCounter << " is " << b << std::endl;
	std::cout << "c value at function call number " << globalCounter << " is " << c << std::endl;
	std::cout << "p pointing value at function call number " << globalCounter << " is " << *p << std::endl << std::endl;

	++globalCounter;

	delete p;
}

void inspect(const char* label)
{
	static int sharedCount{ 0 };
	thread_local int threadCount{ 0 };

	++sharedCount;
	++threadCount;

	std::cout << label
		<< ": shared=" << sharedCount
		<< ", thread=" << threadCount
		<< '\n';
}

void worker()
{
	inspect("worker");
	inspect("worker");
}

int main()
{
	/*inspectStorage();
	inspectStorage();
	inspectStorage();*/

	inspect("main");
	inspect("main");

	std::thread other{ worker };
	other.join();

	inspect("main");

	return 0;
}