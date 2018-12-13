#include "Colonies.h"
#include <iostream>
#include <functional>


Colonies::Colonies(int number):numberOfColonies(number),colonyArray(new Colony[number])
{}
Colony & Colonies::operator[](int index)
{
	if (index >= 0 || index < numberOfColonies)
		return colonyArray[index];
}

const Colony & Colonies::operator[](int index) const
{
	if (index >= 0 || index < numberOfColonies)
		return colonyArray[index];
}

void Colonies::filter(const std::function<bool(int)>& compare) const
{
	for (int i = 0; i < numberOfColonies; i++)
		if (compare(colonyArray[i].getPopulation()))
			std::cout << colonyArray[i].getPopulation() << std::endl;
}

std::ostream & operator<<(std::ostream &output, Colonies &col)
{
	for (int i = 0; i < col.getNumberCol(); i++)
		output << col[i].getPopulation() << std::endl;
	return output;
}

void Colonies::copy(const Colonies &other)
{
	if (!other.colonyArray)
	{
		colonyArray = new Colony[other.numberOfColonies];
		for (int i = 0; i < other.numberOfColonies; i++)
			colonyArray[i] = other.colonyArray[i];
	}
	else
	{
		colonyArray = nullptr;
		numberOfColonies = 0;

	}
}

void Colonies::move(Colonies &&other)
{
	numberOfColonies = std::move(other.numberOfColonies);
	colonyArray = std::move(other.colonyArray);
	other.colonyArray = nullptr;
}