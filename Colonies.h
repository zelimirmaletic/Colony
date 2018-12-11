#pragma once
#include "Colony.h"
#include <functional>
class Colonies
{
	Colony *colonyArray;
	int numberOfColonies;
	friend std::ostream &operator<<(std::ostream &, Colonies &);
public:
	Colonies(int);
	~Colonies();
	void setElement(const Colony col, int index) { colonyArray[index] = col; }
	inline int getNumberCol() { return numberOfColonies; }
	inline Colony getElement(int index) { return colonyArray[index]; }
	Colony &operator[](int);
	const Colony &operator[](int) const;
	void filter(const std::function<bool(int)>&) const;
private:
	inline void empty(){delete[] colonyArray;colonyArray = nullptr;}
};

