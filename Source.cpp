#include "Colonies.h"
#include "Colony.h"
#include <iostream>

int main()
{
	Colony colony1(20);
	Colony colony2(80);
	Colony colony3(1);
	Colony colony4(36);
	Colony colony5(250);

	++colony1;
	++colony2;
	++colony3;
	++colony4;
	++colony5;

	Colonies herd(5);
	herd.setElement(colony1, 0);
	herd.setElement(colony2, 1);
	herd.setElement(colony3, 2);
	herd.setElement(colony4, 3);
	herd.setElement(colony5, 4);

	

	std::cout << herd;

	colony2.operator++(150);
	std::cout << colony2;

	std::cout << std::endl<< "Filtered colonies:" << std::endl;
	herd.filter([](int number) {return number %2 == 0; });

	std::cin.get();
}