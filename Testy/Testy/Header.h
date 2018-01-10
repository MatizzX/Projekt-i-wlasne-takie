#pragma once
#include <iostream>
#include <sstream>
#include <string>

struct list
{
	double value_stored_in_side_list;
	list* next;
};

struct main_list
{
	list side_list;
	main_list* next;
};