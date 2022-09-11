#include "Index.h"

Index::Index(int min, int max) : min(min), max(max)
{
	current = min;
}

int Index::next()
{
	current++;
	checkLoop();
	return get();
}

int Index::previous()
{
	current--;
	checkLoop();
	return get();
}

int Index::get() const
{
	return current;
}

int Index::operator()() const
{
	return get();
}

void Index::checkLoop()
{
	if (current < min)
		current = max;
	else if (current > max)
		current = min;
}
