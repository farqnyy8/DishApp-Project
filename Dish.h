#pragma once

#ifndef DISH_H
#define DISH_H
//added a comment
#include <string>
#include <functional>
#include <unordered_set>
#include <vector>

class Dish
{
public:
	Dish(std::vector<std::string> theIngrideients, std::string newName = "");
	Dish(std::string& name);
	void set_name(std::string newName);
	std::string get_name() const;
	bool hasIngredients(std::string thisIngredient);
	void setDishes(std::vector<std::string> theIngrideients);
	bool addIngredient(std::string new_ingredient);
	bool removeIngredient(std::string this_ingredient);
	std::unordered_set<std::string>& getIngredients();
	bool operator>(const Dish& other) const;
	bool operator<(const Dish& other) const;
	bool operator==(const Dish& other) const;

private:
	std::string  name;
	std::unordered_set<std::string> ingredients;
	//O(1)
};

namespace std
{
	template<>
	struct hash<Dish>
	{
		std::size_t operator()(Dish& dish_to_hash) const noexcept
		{
			std::hash<std::string> hf;
			return 	hf(dish_to_hash.get_name());
		}
	};
}

#endif // !DISH_H