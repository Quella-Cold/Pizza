/******************************************************
** Program: pizza.cpp
** Author: Youli Zhao
** Date: 10/13/2018
** Description:
** Input:
** Output:
******************************************************/
#include "./pizza.h"
Pizza::Pizza(){
	name = " ";
	small_cost = 0;
	medium_cost = 0;
	large_cost = 0;
	num_ingredients = 0;
	ingredients = NULL;
}

Pizza::Pizza(string pz_name,int s_cost,int m_cost,int l_cost,int num_ingre, string* ingre){
	name = pz_name;
	small_cost = s_cost;
	medium_cost = m_cost;
	large_cost = l_cost;
	num_ingredients = num_ingre;
	ingredients = ingre;
}

string Pizza::get_name()const {return name;}
void Pizza::set_name(string pz_name){name = pz_name;}

int Pizza::get_small_cost() const {return small_cost;}
void Pizza::set_small_cost(int s_cost){small_cost = s_cost;}

int Pizza::get_medium_cost() const{return medium_cost;}
void Pizza::set_medium_cost(int m_cost){medium_cost = m_cost;}

int Pizza::get_large_cost() const {return large_cost;}
void Pizza::set_large_cost(int l_cost){large_cost = l_cost;}

int Pizza::get_num_ingredients() const {return num_ingredients;}
void Pizza::set_num_ingredients(int num_ingre){num_ingredients = num_ingre;}

string* Pizza::get_ingredients() const {return ingredients;}
void Pizza::set_ingredients(string* ingre){	ingredients = ingre;}

void Pizza::read_pizza(fstream& pz_info){
	pz_info>>name>>small_cost>>medium_cost>>large_cost>>num_ingredients;
	ingredients = new string[num_ingredients];
	for(int i=0;i<num_ingredients;i++)
		pz_info>>ingredients[i];
}

void Pizza::print(){
	cout<<"pizza: "<<name<<"\n"<<"small_cost: "<<small_cost<<"\n"<<"medium_cost: "<<medium_cost<<"\n"<<"large_cost: "<<large_cost<<"\n"<<"ingredients: ";
	for(int i=0;i<num_ingredients;i++) 
		cout<<ingredients[i] << endl; 
}

Pizza::~Pizza(){
	if(ingredients !=NULL)	
		delete [] ingredients;
}

Pizza::Pizza(const Pizza& copy){
	name = copy.name;
	small_cost = copy.small_cost;
	medium_cost = copy.medium_cost;
	large_cost = copy.large_cost;
	num_ingredients = copy.num_ingredients;
	ingredients = new string[num_ingredients];
	for(int i=0;i<num_ingredients;i++) 
		ingredients[i] = copy.ingredients[i];
}

Pizza& Pizza::operator = (const Pizza& copy){
	if(ingredients !=NULL){
		delete [] ingredients;
	}
	name = copy.name;
	small_cost = copy.small_cost;
	medium_cost = copy.medium_cost;
	large_cost = copy.large_cost;
	num_ingredients = copy.num_ingredients;
	if(num_ingredients != 0){
		ingredients = new string[num_ingredients];
		for(int i=0;i<num_ingredients;i++) 
			ingredients[i] = copy.ingredients[i];
	}
	else{ingredients = NULL;}
	return *this;
}

// void Pizza::print_ingre(){
// 	for(int i=0;i<num_ingredients;i++) 
// 		cout <<ingredients[i] << " ";
// }



















