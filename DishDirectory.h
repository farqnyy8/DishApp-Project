#pragma once
#ifndef DISHDIRECTORY_H
#define DISHDIRECTORY_H

#include "Dish.h"
#include <unordered_set>
#include <set>

/*
The app must support:
1. adding just the name of a dish
2. deleting a dish
3. viewing all dish names we've added.
*/

class DishDirectory
{
public:
	DishDirectory() {}
	const std::set<Dish>& get_dishes();
	bool add_dish(Dish& new_dish);
	bool add_dish(std::vector<std::string>& ingredients, std::string& dish_name);
	bool remove_dish(Dish& this_dish);
	bool remove_dish(std::string& dish_name);
	bool is_empty() const;
	int number_of_dishes() const;

private:
	std::set<Dish> dishes;
};

#endif