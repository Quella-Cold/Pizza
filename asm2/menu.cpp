/******************************************************
** Program: menu.cpp
** Author: Youli Zhao
** Date: 10/13/2018
** Description:
** Input:
** Output:
******************************************************/
#include "./menu.h"
#include "./restaurant.h"
#include <cstdlib>

Menu::Menu(){
	num_pizzas = 0;
	pizzas = NULL;
}

Menu::Menu(int num_pz,Pizza* pz){
	num_pizzas = num_pz;
	pizzas = pz;
}

int Menu::get_num_pizzas()const{return num_pizzas;}
void Menu::set_num_pizzas(int num_pz){num_pizzas = num_pz;}

Pizza* Menu::get_pizzas()const{return pizzas;}
void Menu::set_pizzas(Pizza* pz){pizzas = pz;}


/*********************************************
function:search_pizza_by_cost
description:users give an upper bound and a size of their pizza
parameters: upper_bound, size
pre-conditions: upper_bound is a string, size is a string
post-conditions: return a new menu that is match the condition of users
**********************************************/
Menu Menu::search_pizza_by_cost(string upper_bound,string size){
	int s_cost = 0;
	Menu new_menu;
	if(size=="s"||size=="S"){
		for(int i=0;i<num_pizzas;i++){
			if(atoi(upper_bound.c_str()) >= pizzas[i].get_small_cost()){
				new_menu.add_to_menu(pizzas[i]);
			}
		}
	}

	if(size=="m"||size=="M"){
		for(int i=0;i<num_pizzas;i++){
			if(atoi(upper_bound.c_str()) >=pizzas[i].get_medium_cost()){
				new_menu.add_to_menu(pizzas[i]);
			}
		}
	}

	if(size=="l"||size=="L"){
		for(int i=0;i<num_pizzas;i++){
			if(atoi(upper_bound.c_str()) >=pizzas[i].get_large_cost()){
				new_menu.add_to_menu(pizzas[i]);
			}
		}
	}
	return new_menu;
}	

/*********************************************
function:search_pizza_by_ingredients_to_include
description:user gives some ingredients that he wants.
parameters: ingredients, num_ingredients
pre-conditions: ingredients is a string, num_ingredients is an integer
post-conditions: return a new menu that is match the conditions of user
**********************************************/
Menu Menu::search_pizza_by_ingredients_to_include(string* ingredients, int num_ingredients){
	Menu copy (*this);
	Menu include_menu;
	for(int i=0;i<num_ingredients;i++){
		for(int j=0;j<copy.get_num_pizzas();j++){
			for(int k=0;k<copy.get_pizzas()[j].get_num_ingredients();k++){
				if(copy.get_pizzas()[j].get_ingredients()[k] == ingredients[i]){
					include_menu.add_to_menu(copy.get_pizzas()[j]);
					copy.remove_from_menu(j);
					j--;
					break;
				}
			}
		}
	}
	return include_menu;
}

/*********************************************
function:search_pizza_-by_ingredients_to_exclude
description:user gives some ingredients that he doesn't want.
parameters: ingredients, num_ingredients
pre-conditions:ingredients is a string, num_ingredients is an integer 
post-conditions: return a new menu that is match the conditions of user
**********************************************/
Menu Menu::search_pizza_by_ingredients_to_exclude(string* ingredients, int num_ingredients){
	Menu copy (*this);
	Menu include_menu;
	for(int i=0;i<num_ingredients;i++){
		for(int j=0;j<copy.get_num_pizzas();j++){
			for(int k=0;k<copy.get_pizzas()[j].get_num_ingredients();k++){
				if(copy.get_pizzas()[j].get_ingredients()[k] == ingredients[i]){
					include_menu.add_to_menu(copy.get_pizzas()[j]);
					copy.remove_from_menu(j);
					j--;
					break;
				}
			}
		}
	}
	return copy;
}


/*********************************************
function:add_to_menu
description: get one more pizza, and save it in the menu 
parameters: pizza_to_add
pre-conditions: pizza_to_add is an object of Pizza
post-conditions: 
**********************************************/
void Menu::add_to_menu(Pizza pizza_to_add){	
	Pizza* new_pizza_array = new Pizza[num_pizzas+1];
	for(int i=0;i<num_pizzas;i++){
		new_pizza_array[i] = pizzas[i];
	}
	new_pizza_array[num_pizzas] = pizza_to_add;
	delete [] pizzas;
	pizzas = new_pizza_array;
	num_pizzas++;
}

/*********************************************
function: minus_to_menu
description: delete some pizzas from the menu
parameters: 
pre-conditions: 
post-conditions: 
**********************************************/
void Menu::minus_to_menu(){
	string i="";
	cout<<"which pizza you want to delete?(giving an index number)"<<endl;
	cin >>i;
	remove_from_menu(atoi(i.c_str()));
}

/*********************************************
function: remove_from_menu
description:user give an index number, then delete this pizza from the menu
parameters: index_of_pizza_on_menu
pre-conditions: index_of_pizza_on_menu is an integer
post-conditions: 
**********************************************/
void Menu::remove_from_menu(int index_of_pizza_on_menu){
	if(num_pizzas!=0 && index_of_pizza_on_menu<num_pizzas){
		Pizza* new_pizza_array = new Pizza[num_pizzas-1];
		for(int i=0;i<index_of_pizza_on_menu;i++){
			new_pizza_array[i]=pizzas[i];
		}
		for(int i=index_of_pizza_on_menu+1;i<num_pizzas;i++){
			new_pizza_array[i-1]=pizzas[i];
		}
		delete [] pizzas;
		pizzas=new_pizza_array;
		num_pizzas--;
	}
	else{
		cout << "You cannot remove pizza!"<<endl;
	}

}

/*********************************************
function:add_item_to_menu
description:add some pizzas to menu
parameters: 
pre-conditions: 
post-conditions: return a new menu
**********************************************/
Menu Menu::add_item_to_menu(){
	ofstream new_menu_file("menu.txt");

	Pizza pz;
	string new_pizza_name="";
	cout<<"Set a name for your pizza: ";
	cin >> new_pizza_name; 
	pz.set_name(new_pizza_name);

	int new_s_price = 0;
	cout<<"Set a price for your small pizza: "<<endl;
	cin >> new_s_price;
	pz.set_small_cost(new_s_price);

	int new_m_price = 0;
	cout<<"Set a price for your medium pizza: "<<endl;
	cin >> new_m_price;
	pz.set_medium_cost(new_m_price);

	int new_l_price = 0;
	cout<<"Set a price for your large pizza: "<<endl;
	cin >> new_l_price;
	pz.set_large_cost(new_l_price);

	int new_num_of_ingredients = 0;
	cout<<"Set numbers of your ingredients: "<<endl;
	cin >> new_num_of_ingredients;
	pz.set_num_ingredients(new_num_of_ingredients);

	string* new_ingredients = new string[new_num_of_ingredients];
	cout<<"Set your ingredients: "<<endl;
	for(int i=0;i<new_num_of_ingredients;i++){
		//string ingre_name = "";
		cout << "Set your ingredients's name "<<i+1<<": " << endl;
		cin >> new_ingredients[i];
	}
	//delete [] new_ingredients;
	pz.set_ingredients(new_ingredients);
	add_to_menu(pz);
	
	//write it to txt file
	new_menu_file << num_pizzas <<"\n";
	for(int i=0;i<num_pizzas;i++){
		new_menu_file <<pizzas[i].get_name()<<" "<<pizzas[i].get_small_cost()<<" "<<pizzas[i].get_medium_cost()<<" "
		<<pizzas[i].get_large_cost()<<" "<<pizzas[i].get_num_ingredients()<<" ";
		for(int j=0;j<pizzas[i].get_num_ingredients();j++){
			new_menu_file << pizzas[i].get_ingredients()[j] << " ";
		}
		new_menu_file << "\n";
	}

	new_menu_file.close();
	return *this;
}

/*********************************************
function: print_menu
description: print all pizzas and their detail
parameters: 
pre-conditions: 
post-conditions: 
**********************************************/
void Menu::print_menu(){
	string ingredients_name;
	for(int i=0;i<num_pizzas;i++){
		cout<<pizzas[i].get_name()<<" "
		<<pizzas[i].get_small_cost()<<" "
		<<pizzas[i].get_medium_cost()<<" "
		<<pizzas[i].get_large_cost()<<" "
		<<pizzas[i].get_num_ingredients() << " ";
		//read array of ingredients.
		//string* new_ingredients_name = new pizzas[i].get_ingredients()[pizzas[i].get_num_ingredients()];
		for(int j=0;j<pizzas[i].get_num_ingredients();j++){
			cout<<pizzas[i].get_ingredients()[j] << " ";
		}
		cout << endl;
	}

}

/*********************************************
function:~Menu
description:delete dynamic array of Menu(distruct)
parameters: 
pre-conditions: 
post-conditions: 
**********************************************/
Menu::~Menu(){
	if( pizzas !=NULL)	
		delete [] pizzas;
}

/*********************************************
function: Menu
description: copy Menu (construct)
parameters: copy
pre-conditions: 
post-conditions: 
**********************************************/
//edit copy constructor and aoo
Menu::Menu(const Menu& copy){
	num_pizzas = copy.num_pizzas;
	pizzas = new Pizza[num_pizzas];
	for(int i=0;i<num_pizzas;i++)
		pizzas[i] = copy.pizzas[i];
}

/*********************************************
function: operator
description: assignment operator overload
parameters: copy
pre-conditions: 
post-conditions: 
**********************************************/
Menu& Menu::operator=(const Menu&copy){
	if(pizzas !=NULL)
		delete []pizzas;
	num_pizzas = copy.num_pizzas;
	if(num_pizzas !=0){
		pizzas = new Pizza[num_pizzas];
		for(int i=0;i<num_pizzas;i++){
			pizzas[i] = copy.pizzas[i];
		}
	}
		else{
			pizzas = NULL;
		}
	return *this;
}


















