/******************************************************
** Program: restaurant.h
** Author: Youli Zhao
** Date: 10/13/2018
** Description:
** Input:
** Output:
******************************************************/
#ifndef restaurant_h
#define restaurant_h

#include "pizza.h"
#include "menu.h"
#include "employee.h"
#include "hours.h"
#include "order.h"

using namespace std;

class Restaurant{
	private:
		Menu menu;
		employee* employees;
		hours* week;
		string name;
		string phone;
		string address;
		order* orders;

		int line_num;
		int employees_num;
		int order_num;
		int menu_num;


	public:
		Restaurant();
		Restaurant(Menu,employee*,hours*,string,string,string,order*);
		
		Menu get_menu()const;
		employee* get_employees()const;
		hours* get_week()const;
		string get_name()const;
		string get_phone()const;
		string get_address()const;
		order* get_orders()const;

		void set_menu(Menu);
		void set_employees(employee*);
		void set_week(hours*);
		void set_name(string);
		void set_phone(string);
		void set_address(string);
		void set_orders(order*);


		void employee_menu();
		void customer_menu();
		void choice_menu();

		void output_file(string file);
		employee* get_employees_info(string file);
//		int count_line(string name);
		void get_menu_info();
		void get_order_info();
		void get_restaurant_info();

		void load_data();
		void login_window();
		bool login_check(string id, string password);

		void print_restaurant_name();
		void print_restaurant_phone();
		void print_restaurant_address();
		void print_restaurant_hours();
		void print_employee_info();
		void print_order_info();





		void search_menu_by_price();



		string I_or_E();
		void prompt_ig_array_and_num(string&, string*&);
		string yes_or_no(string);
		void search_by_ingredients();

		void minus_to_order();
		void remove_order(int index_of_order);

		void add_to_order(order order_to_add);
		void place_order(Menu od_menu);
		void change_hours();


		~Restaurant();
		Restaurant(const Restaurant&);
		Restaurant& operator=(const Restaurant&);

};

#endif
