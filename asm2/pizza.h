/******************************************************
** Program: pizza.h
** Author: Youli Zhao
** Date: 10/13/2018
** Description:
** Input:
** Output:
******************************************************/
#ifndef pizza_h
#define pizza_h
#include<fstream>
#include<stdio.h>
#include<cstdlib>
#include<stdlib.h>
#include<string>
#include<iostream>

using namespace std;

class Pizza{
	private:
		string name;
		int small_cost;
		int medium_cost;
		int large_cost;
		int num_ingredients;
		string* ingredients;
	public:
		Pizza();
		Pizza(string,int,int,int,int, string*);

		string get_name() const;
		int get_small_cost() const;
		int get_medium_cost() const;
		int get_large_cost() const;
		int get_num_ingredients() const;
		string* get_ingredients() const;

		void set_name(string);
		void set_small_cost(int);
		void set_medium_cost(int);
		void set_large_cost(int);
		void set_num_ingredients(int);
		void set_ingredients(string*);

		//void print_ingre();

		void read_pizza(fstream&);
		void print();
		~Pizza();
		Pizza(const Pizza&);
		Pizza& operator = (const Pizza&);
			
};

#endif
