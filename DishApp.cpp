// DishApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
The app must support:
1. adding just the name of a dish
2. deleting a dish
3. viewing all dish names we've added.
*/

#include <iostream>
#include "DishDirectory.h"

char display();
void add_dish(DishDirectory& my_dish_directory);
void remove_dish(DishDirectory& my_dish_directory);
void view_dishes(DishDirectory& my_dish_directory);

int main()
{
    DishDirectory my_dish_directory;

    while (true)
    {
        std::cout << "***********************************************" << std::endl;
        switch (display())
        {
        case 'a':
            add_dish(my_dish_directory);
            break;
        case 'b':
            remove_dish(my_dish_directory);
            break;
        case 'c':
            view_dishes(my_dish_directory);
            break;
        case 'd':
            std::cout << "Bye...." << std::endl;
            return 0;
            break;
        }
        std::cout << "***********************************************" << std::endl << std::endl;
    }

    return 0;
}

char display()
{
    std::string choice; // handling invalid inputs
    bool valid_choice;

    std::cout << "a. Add a dish" << std::endl;
    std::cout << "b. Remove a dish" << std::endl;
    std::cout << "c. View all dishes" << std::endl;
    std::cout << "d. Exit program" << std::endl;
    std::cout << "Enter choice of action: ";
    getline(std::cin, choice);

    valid_choice = (int(choice[0]) - int('a') < 4) && (int(choice[0]) >= int('a'));
    while (!valid_choice || choice.size() > 1)
    {
        std::cout << "Wrong entry! Enter a correct choice of action: ";
        getline(std::cin, choice);
        valid_choice = (int(choice[0]) - int('a') < 4) && (int(choice[0]) >= int('a'));
    }

    return choice[0];
}

void add_dish(DishDirectory& my_dish_directory)
{
    std::vector<std::string> ingredients;
    std::string name;
    std::cout << "Enter the name of the new dish: ";
    getline(std::cin, name);

    std::string ing;
    std::cout << "Enter name of " << name << " ingredients (enter \"done\" to stop): ";
    getline(std::cin, ing);
    while (ing != "done")
    {
        ingredients.push_back(ing);
        std::cout << "Enter name of " << name << " ingredients (enter \"done\" to stop): ";
        getline(std::cin, ing);
    }

    if (my_dish_directory.add_dish(ingredients, name))
        std::cout << name << " has been added to the directory" << std::endl;
    else
        std::cout << name << " was already in the directory" << std::endl;
}

void remove_dish(DishDirectory& my_dish_directory)
{
    if (my_dish_directory.is_empty())
    {
        std::cout << "There are no dishes yet" << std::endl;
        return;
    }
    //view_dishes(my_dish_directory);
    std::string name;
    std::cout << "Enter the name of the dish to be removed: ";
    getline(std::cin, name);
    if (my_dish_directory.remove_dish(name))
        std::cout << name << " has been removed from the directory" << std::endl;
    else
        std::cout << name << " was not in the directory" << std::endl;
}

void view_dishes(DishDirectory& my_dish_directory)
{
    if (my_dish_directory.is_empty())
    {
        std::cout << "There are no dishes yet" << std::endl;
        return;
    }
    int i = 0;
    for (Dish x : my_dish_directory.get_dishes())
    {
        std::cout << "Dish " << ++i << ": " << x.get_name() << std::endl;
        std::cout << "Ingredients: ";

        if (x.getIngredients().size())
        {
            for (auto y : x.getIngredients())
            {
                std::cout << y << " ";
            }
            std::cout << std::endl;
        }
        else
            std::cout << "No ingredients was entered" << std::endl;
    }
}