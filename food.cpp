#include "food.h"
#include <iostream>
using namespace std;

Food::Food(string s, int cal)
{
	_name = s;
	_cal = cal;
}

Food Food:: operator+(const Food& f)
{
	// modify this function
	string foodName = _name + " " + f._name;
	int foodCal = _cal + f._cal;
	return Food(foodName, foodCal);
}


bool Food:: operator>(const Food& f)
{
	return _cal > f._cal;
}

bool Food:: operator==(const Food& f)
{
	return _name.compare(f._name) == 0;
}


ostream& operator<<(ostream& os, const Food& f)
{
	os << f._name << " with " << f._cal << " calories" ;
	return os;
}
