/******************************************************
** Program: order.h
** Author: Youli Zhao
** Date: 10/13/2018
** Description:
** Input:
** Output:
******************************************************/
#ifndef order_h
#define order_h

#include<string>

using namespace std;

struct order{
	int order_num;
	string first_name;
	string last_name;
	string card_number;
	string address;
	string phone_number;
	string pizza_name;
	string size;
	string pizza_amount;
};

#endif
