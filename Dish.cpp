#include "Dish.h"

Dish::Dish(std::vector<std::string> theIngrideients, std::string newName)
{
	name = newName;
	for (auto& x : theIngrideients)
		ingredients.insert(x);
}

Dish::Dish(std::string& newName)
{
	name = newName;
}

bool Dish::hasIngredients(std::string thisIngredient)
{
	return ingredients.find(thisIngredient) != ingredients.end();
}

void Dish::setDishes(std::vector<std::string> theIngrideients)
{
	for (auto& x : theIngrideients)
		ingredients.insert(x);
}

bool Dish::addIngredient(std::string new_ingredient)
{
	return false;
}

bool Dish::removeIngredient(std::string this_ingredient)
{
	return false;
}

std::unordered_set<std::string>& Dish::getIngredients()
{
	// TODO: insert return statement here
	return ingredients;
}

void Dish::set_name(std::string newName)
{
	name = newName;
}

std::string Dish::get_name() const
{
	return name;
}

bool Dish::operator<(const Dish& other) const
{
	return get_name() < other.get_name();
}

bool Dish::operator>(const Dish& other) const
{
	return get_name() > other.get_name();
}

bool Dish::operator==(const Dish& other) const
{
	return get_name() == other.get_name();
}