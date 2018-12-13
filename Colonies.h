#pragma once
#include "Colony.h"
#include <functional>
#include <utility>
class Colonies
{
	Colony *colonyArray;
	int numberOfColonies;
	friend std::ostream &operator<<(std::ostream &, Colonies &);
public:
	Colonies(int);
	~Colonies() { empty(); }
	void setElement(const Colony col, int index) { colonyArray[index] = col; }
	constexpr int getNumberCol() { return numberOfColonies; }
	inline Colony getElement(int index) const { return colonyArray[index]; }
	Colony &operator[](int);
	const Colony &operator[](int) const;
	void filter(const std::function<bool(int)>&) const;
	inline Colonies &operator=(const Colonies &other) { copy(other); }
	inline Colonies &operator=(Colonies &&other) { move(std::move(other)); }
private:
	inline void empty(){delete[] colonyArray;colonyArray = nullptr;}
	void copy(const Colonies&);
	void move(Colonies &&);
};

