/******************************************************
** Program: menu.h
** Author: Youli Zhao
** Date: 10/13/2018
** Description:
** Input:
** Output:
******************************************************/
#ifndef menu_h
#define menu_h
#include"pizza.h"
#include<string>
#include<iostream>

using namespace std;

class Menu{
	private:
		int num_pizzas;
		Pizza* pizzas;
	public:
		Menu();
		Menu(int,Pizza*);
		
		int get_num_pizzas()const;
		Pizza* get_pizzas()const;

		void set_num_pizzas(int);
		void set_pizzas(Pizza*);

		Menu search_pizza_by_cost(string upper_bound, string size);
		Menu search_pizza_by_ingredients_to_include(string*ingredients,int num_ingredients);
		Menu search_pizza_by_ingredients_to_exclude(string* ingredients,int num_ingredients);
		void add_to_menu(Pizza pizza_to_add);
		//void minus_to_menu(Pizza pizza_to_minus);
		void minus_to_menu();
		void remove_from_menu(int index_of_pizza_on_menu);
		void print_menu();
		Menu add_item_to_menu(/*Pizza pz*/);
		
		~Menu();
		Menu(const Menu&);
		Menu& operator = (const Menu&);
};

#endif
