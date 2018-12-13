#pragma once
#include <cstdlib>
#include <iostream>
constexpr int MAX = 1000;
class Colony
{
	int population;
public:
	inline Colony(const int number = 1):population(number) {};
	~Colony() = default;
	constexpr int getPopulation() { return population; }
	Colony &operator++(){ population += (int)(rand() % MAX); return *this; }
	Colony operator++(int n) { Colony tmp = *this; population += n; return tmp; }
	friend std::ostream &operator<<(std::ostream &output, Colony &other)
	{
		output <<"Population--->"<< other.population << std::endl;
		return output;
	}
};

