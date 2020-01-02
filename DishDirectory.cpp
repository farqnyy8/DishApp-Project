#include "DishDirectory.h"

const std::set<Dish>& DishDirectory::get_dishes()
{
	return dishes;
}

bool DishDirectory::add_dish(Dish& new_dish)
{
	if (dishes.find(new_dish) != dishes.end())
		return false;
	dishes.insert(new_dish);
	return true;
}

bool DishDirectory::add_dish(std::vector<std::string>& ingredients, std::string& dish_name)
{
	Dish new_dish(ingredients, dish_name);
	return add_dish(new_dish);
}

bool DishDirectory::remove_dish(Dish& this_dish)
{
	if (dishes.find(this_dish) == dishes.end())
		return false;
	dishes.erase(this_dish);
	return true;
}

bool DishDirectory::remove_dish(std::string& dish_name)
{
	Dish this_dish(dish_name);
	return remove_dish(this_dish);
}

bool DishDirectory::is_empty() const
{
	return dishes.size() == 0;
}

int DishDirectory::number_of_dishes() const
{
	return dishes.size();
}