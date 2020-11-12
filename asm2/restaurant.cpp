/******************************************************
** Program: restaurant.cpp
** Author: Youli Zhao
** Date: 10/13/2018
** Description:
** Input:
** Output:
******************************************************/
#include "./restaurant.h"
#include <cstdlib>
Restaurant::Restaurant(){
	//menu = "";
	employees = NULL;
	week = NULL;
	name = "";
	phone = "";
	address = "";
	orders = NULL;
	
	line_num = 0;
	employees_num = 0;
	order_num = 0;
	menu_num = 0;
}

Restaurant::Restaurant(Menu mu,employee* emp,hours* hour,string rename,string rephone,string readdress,order*){
	menu = mu;
	employees = emp;
	week = hour;
	name = rename;
	phone = rephone;
	address = readdress;

}

Menu Restaurant::get_menu()const{return menu;}
employee* Restaurant::get_employees()const{return employees;}
hours* Restaurant::get_week()const{return week;}
string Restaurant::get_name()const{return name;}
string Restaurant::get_phone()const{return phone;}
string Restaurant::get_address()const{return address;}
order* Restaurant::get_orders()const{return orders;}

void Restaurant::set_menu(Menu me){menu = me;}
void Restaurant::set_employees(employee* emp){employees = emp;}
void Restaurant::set_week(hours* wk){week = wk;}
void Restaurant::set_name(string na){name = na;}
void Restaurant::set_phone(string ph){phone = ph;}
void Restaurant::set_address(string add){address = add;}
void Restaurant::set_orders(order* ord){orders = ord;}


/*********************************************
function: employee_menu
description: it is a menu table that can help employees do some work
parameters: 
pre-conditions: 
post-conditions: 
**********************************************/
void Restaurant::employee_menu(){
	cout<<"1.Change hours"
	<<"\n"<<"2.View orders"<<"\n"
	<<"3.Remove order"<<"\n"
	<<"4.Add item to menu"<<"\n"
	<<"5.Remove item from menu"<<"\n"
	<<"6.View menu"<<"\n"
	<<"7.View hours"<<"\n"
	<<"8.View address"<<"\n"
	<<"9.View phone"<<"\n"
	<<"10.Log out"<<endl;
}

/*********************************************
function:customer_menu
description:it is a menu table that can help customer do some option and order some pizzas
parameters: 
pre-conditions: 
post-conditions: 
**********************************************/
void Restaurant::customer_menu(){
	cout<<"1.View menu"
	<<"\n"<<"2.Search by cost"
	<<"\n"<<"3.Search by ingredients"
	<<"\n"<<"4.Place order"
	<<"\n"<<"5.View hours"
	<<"\n"<<"6.View address"
	<<"\n"<<"7.View phone"
	<<"\n"<<"8.Log out"<<endl;
}

/*********************************************
function: choice_menu
description: user can using this choice menu to do something they want
parameters: 
pre-conditions: 
post-conditions: 
**********************************************/
void Restaurant::choice_menu(){
	string x,c,C,e,E,q,Q;
	// Menu od_menu;
	load_data();
	do {
		do{
			cout<<"Are you a customer(C) or employee(E) or would you like to quit(Q)?"<<endl;
			cin>>x;
		}while(!(x=="c"||x=="C"||x=="e"||x=="E"||x=="q"||x=="Q"));	//error chrcking

		int choice = 0;
		if(x=="c"||x=="C"){	//error checking
			//load_data();	//get all informations of txt file
			
			do{
				customer_menu();
				cout << endl;
				cout<<"Making a choice:"<<endl;
				cin >> choice;
				if(choice==1){menu.print_menu();}	//print all pizzas of this restaurant
				if(choice==2){search_menu_by_price();}	//search pizzas relate with price
				if(choice==3){search_by_ingredients();}	//search ingredients which is user need or doesn't need
				if(choice==4){place_order(menu);}	//enter informations of user's order
				if(choice==5){print_restaurant_hours();}	//check the work hours
				if(choice==6){print_restaurant_address();}	//check the address of restaurant
				if(choice==7){print_restaurant_phone();}	//check the phone number of restaurant
				if(choice==8){cout<<endl;}	//go back
			}while(choice!=8);
		}
		if(x=="e"||x=="E"){	//error checking
			//load_data();
			login_window();
			
			do{
				employee_menu();
				cout<<"Making a choice:"<<endl;
				cin>>choice;
				if(choice==1){change_hours();}	//employees can change work hours
				if(choice==2){print_order_info();}	//view orders' information
				if(choice==3){minus_to_order();}	//delete some orders from order
				if(choice==4){menu = menu.add_item_to_menu();}	//add some pizzas from menu
				if(choice==5){menu.minus_to_menu();}	//delete some pizzas from menu
				if(choice==6){menu.print_menu();}	//view menu
				if(choice==7){print_restaurant_hours();}	//view work hours
				if(choice==8){print_restaurant_address();}	//view restaurant address
				if(choice==9){print_restaurant_phone();}	//niew restaurant phone nuembr
				if(choice==10){cout<<endl;}	//go back
			}while(choice!=10);
		}
	}while (x!="Q" && x!="q");	//error checking
}



/*********************************************
function:output_file
description: print restaurant information
parameters: file
pre-conditions: string a file name
post-conditions: 
**********************************************/
void Restaurant::output_file(string file){
	ofstream outfile_res(file.c_str());	//create a new file, perpare put some info in it
	outfile_res<<name<<"\n"<<phone<<"\n"<<address<<"\n"<<line_num<<"\n";	//read these info
	for(int i=0;i<line_num;i++) 
		outfile_res<<week[i].day<<" "<<week[i].open_hour<<" "<<week[i].close_hour <<"\n";
}

/*********************************************
function: get_employees_info
description: get emloyees information
parameters: file
pre-conditions: string a file name
post-conditions: 
**********************************************/
employee* Restaurant::get_employees_info(string file){
	ifstream emp;
	emp.open("employee.txt");
	emp >> employees_num;	//read employees info
//	employees_num = count_line("employee.txt");
	employees = new employee[employees_num];
	for(int i=0;i<employees_num;i++)
		emp>>employees[i].id>>employees[i].first_name>>employees[i].last_name>>employees[i].password;
	emp.close();
 }

/*int Restaurant::count_line(string name){
	fstream input;
	input.open(name.c_str());
	string str = "";
	int line = 0;
	while(!input.eof()){
		getline(input,str);
		line++;
	}
	input.close();
	return line-1;
}*/

/*********************************************
function: get_menu_info
description: get menu information
parameters: 
pre-conditions: 
post-conditions: 
**********************************************/
void Restaurant::get_menu_info(){
	fstream infile;
	infile.open("menu.txt");
	infile >> menu_num;
	Pizza* pz = new Pizza[menu_num];	//create a new Pizza object named pz, then parpare cin some info in pz.
	string a;
	int b,c,d,e;
	for(int i=0;i<menu_num;i++){
		infile>>a>>b>>c>>d>>e;
		pz[i].set_name(a);	//read name to pz
		pz[i].set_small_cost(b);	//read small cost to pz
		pz[i].set_medium_cost(c);	//read medium cost to pz
		pz[i].set_large_cost(d);	//read large cost to pz
		pz[i].set_num_ingredients(e);	//read ingredients number to pz
		string* ing = new string[e];	//create a new string named ing
		for(int j=0;j<e;j++)	
			infile>>ing[j];
		pz[i].set_ingredients(ing);	//read all ingredients info to pz
	}
	menu.set_num_pizzas(menu_num);
	menu.set_pizzas(pz);	//save pz to a new menu
	infile.close();
}

/*********************************************
function:get_order_info
description: get order information
parameters: 
pre-conditions: 
post-conditions: 
**********************************************/
void Restaurant::get_order_info(){
	ifstream ord;
	ord.open("orders.txt");
	ord >> order_num;
	orders = new order[order_num];	
	for(int i=0;i<order_num;i++){
		ord>>orders[i].order_num
		>>orders[i].first_name
		>>orders[i].last_name
		>>orders[i].card_number   
		>>orders[i].address
		>>orders[i].phone_number
		>>orders[i].pizza_name
		>>orders[i].size
		>>orders[i].pizza_amount;
	}
	ord.close();	
	// ofstream output_order;
	// output_order.open("output_order.txt");
}

/*********************************************
function: get_resraurant_info
description: get restaurant information
parameters: 
pre-conditions: 
post-conditions: 
**********************************************/
void Restaurant::get_restaurant_info(){
	ifstream res;
	res.open("restaurant_info.txt");
	getline(res,name);
	getline(res,phone);
	getline(res,address);
	res>>line_num;
	week = new hours[line_num];
	for(int i =0;i<line_num;i++){
		res>>week[i].day>>week[i].open_hour>>week[i].close_hour;
	}
	res.close();
}


/*********************************************
function:load_data
description: integrate all information to an area
parameters: 
pre-conditions: 
post-conditions: 
**********************************************/
void Restaurant::load_data(){
	get_order_info();
	get_menu_info();
	get_employees_info("employee.txt");
	get_restaurant_info();		
}

/*********************************************
function: login_window
description:giving a login window to user
parameters: 
pre-conditions: 
post-conditions: 
**********************************************/
void Restaurant::login_window(){
	string ID = "";
	string PASSWORD = "";
	string NAME = "";
	do{
		cout<<"Enter your ID numebr: "<<endl;
		cin >> ID;
		cout <<"Enter your password: "<<endl;
		cin >> PASSWORD; 
	}while(login_check(ID,PASSWORD)!=true);

	for(int i=0;i<employees_num;i++){
		if(ID==employees[i].id){	//through employees object to get employees' id 
			NAME=employees[i].first_name + employees[i].last_name;
			cout<<"Welcome "<<NAME<<"to our restaurant, please make a choice: "<<endl;
		}
	}
}

/*********************************************
function:login_check
description:check the login information is correct
parameters: id,password
pre-conditions: id should be a string, password should be an integer
post-conditions: return true or false
**********************************************/
bool Restaurant::login_check(string id,string password){
	for(int i=0;i<employees_num;i++){	//check user's input that id and passwprd is correct 
		if(employees[i].id==id){	
				if(employees[i].password==password)
				return true;
		}
	}
			cout<<"Please enter again." << endl;
			return false;
}




void Restaurant::print_restaurant_name(){
	cout << name << endl;
}
void Restaurant::print_restaurant_phone(){
	cout << phone << endl;
}
void Restaurant::print_restaurant_address(){
	cout << address << endl;
}
void Restaurant::print_restaurant_hours(){
	for(int i=0;i<line_num;i++) cout<<week[i].day<<" "<<week[i].open_hour<<" "<<week[i].close_hour<<endl;
}
void Restaurant::print_employee_info(){
	for(int i=0;i<employees_num;i++) cout<<employees[i].id<<" "<<employees[i].first_name<<" "<<employees[i].last_name<<" "<<employees[i].password<<endl;
}
void Restaurant::print_order_info(){	//through object named orders to get every memory
	cout << "here" << order_num << endl;
	for(int i=0;i<order_num;i++){ 
		cout<<orders[i].order_num
		<<" "<<orders[i].first_name
		<<" "<<orders[i].last_name
		<<" "<<orders[i].card_number
		<<" "<<orders[i].address
		<<" "<<orders[i].phone_number
		<<" "<<orders[i].pizza_name
		<<" "<<orders[i].size
		<<" "<<orders[i].pizza_amount<<endl;
	}
}

/*********************************************
function: search_menu_by_price
description: according to user's giving, get some pizzas that is suirable for user
parameters: 
pre-conditions: 
post-conditions: 
**********************************************/
void Restaurant::search_menu_by_price(){
	string x,s,S,m,M,l,L;
	do{
		cout<<"Please choose S or M or L for your pizza"<<endl;
		cin >> x;
	}while(!(x=="s"||x=="S"||x=="m"||x=="M"||x=="l"||x=="L"));	//error checking
	string upper_bound = "";
	cout << "Please give your upper bound:"<<endl;
	cin >> upper_bound;
	if(atoi(upper_bound.c_str())>0){	//convert string upper_bound to an integer
		Menu m = menu.search_pizza_by_cost(upper_bound,x);	//call realize the equation through Menu object, because this function is exist in menu.cpp
		m.print_menu();
	}
}


/*********************************************
function: I_or_E
description: a choice function, let user choose include ingredients or exclude ingredients
parameters: 
pre-conditions: 
post-conditions: 
**********************************************/
string Restaurant::I_or_E(){
	string option = "" ;
	do{
		cout<<"Would you like to search for ingredients you want include[I] or exclude[E]?"<<endl;
		cin >> option;
	}while(!(option=="i"||option=="I"||option=="e"||option=="E"));	//error checking
	return option;
}

/*********************************************
function: prompt_ig_array_and_num
description: get users input about ingredients num and ingredients
parameters: 
pre-conditions: 
post-conditions: 
**********************************************/
void Restaurant::prompt_ig_array_and_num(string &num_option, string* &ingredient_array){
	//string num_option="";
	do{
		cout<< "How many ingredient do you want?"<<endl;
		cin >> num_option;
	}while(atoi(num_option.c_str()) <= 0);	//convert num_option to a integer.error checking.

	ingredient_array = new string[atoi(num_option.c_str())];	//set an ingredient array that include the user's input(some ingredients).
	for(int i=0;i<atoi(num_option.c_str());i++){
		cout<<"Enter the ingredient "<<i+1<<" :"<<endl;
		cin>>ingredient_array[i];	//giving i different kinds of ingredients
	}
}

/*********************************************
function: yes_or_no
description: check user whether he continue to add something
parameters: 
pre-conditions: 
post-conditions: 
**********************************************/
string Restaurant::yes_or_no(string prompt){
	string yes_no = "";
	do{
		cout<<prompt<<endl;
		cin >> yes_no;
	}while(!(yes_no=="yes"||yes_no=="no"));	//error checking

	return yes_no;
}

/*********************************************
function: search_by_ingredients
description: user search ingredients through input ingredients name
parameters: 
pre-conditions: 
post-conditions: 
**********************************************/
void Restaurant::search_by_ingredients(){
	string option = I_or_E();	//ask user include or exclude
	string num_option="";	
	string* ingredient_array = NULL;
	if (option == "i" || option == "I"){
		prompt_ig_array_and_num(num_option, ingredient_array);	//get user's ingredients
		Menu include_menu= menu.search_pizza_by_ingredients_to_include(ingredient_array, atoi(num_option.c_str()));	//get a new menu that is suitable for the user
		include_menu.print_menu();	//print this suitable menu
		string yes_no=yes_or_no("Would you like to reduce your search by excluding some ingredients(yes/no)?");	//make sure the user is continue or not
		Menu exclude_menu;	//set a new menu named exclude menu
		if(yes_no=="yes"){
			delete [] ingredient_array;		//delete the first ingredients array that is about include ingredients
			prompt_ig_array_and_num(num_option, ingredient_array);	//ask user again, and get his include ingredients
			exclude_menu = include_menu.search_pizza_by_ingredients_to_exclude(ingredient_array, atoi(num_option.c_str()));
			exclude_menu.print_menu();
		}
		delete [] ingredient_array;	//delete the second ingredients that is about the include ingredients
		yes_no = yes_or_no("Do you want to place order based off the searching result? (yes/no)");
		if (yes_no == "yes")
			place_order(exclude_menu);
	}

	else if (option == "e" || option == "E"){
		prompt_ig_array_and_num(num_option, ingredient_array);
		Menu exclude_menu= menu.search_pizza_by_ingredients_to_exclude(ingredient_array, atoi(num_option.c_str()));
		exclude_menu.print_menu();
		string yes_no=yes_or_no("Would you like to reduce your search by including some ingredients(yes/no)?");
		Menu include_menu;
		if(yes_no=="yes"){
			delete [] ingredient_array;
			prompt_ig_array_and_num(num_option, ingredient_array);
			include_menu = exclude_menu.search_pizza_by_ingredients_to_include(ingredient_array, atoi(num_option.c_str()));
			include_menu.print_menu();
		}
		delete [] ingredient_array;
		yes_no = yes_or_no("Do you want to place order based off the searching result? (yes/no)");
		if (yes_no == "yes")
			place_order(include_menu);
	}

}




/*********************************************
function: minues_to_order
description: delete some orders
parameters: 
pre-conditions: 
post-conditions: 
**********************************************/
void Restaurant::minus_to_order(){
	string i="";
	cout<<"Which order you want to move?(giving an index number)"<<endl;
	cin >> i;
	remove_order(atoi(i.c_str()));
}

/*********************************************
function: remove_order
description:delete one order from the order file
parameters: index_of_order
pre-conditions: index_of_order should be an integer
post-conditions: 
**********************************************/
void Restaurant::remove_order(int index_of_order){
	if(order_num!=0 && index_of_order<order_num){	//check the user input is variable
		order* new_order_array = new order[order_num-1];	//set a new order array to parpare to same the add order
		for(int i=0;i<index_of_order;i++){
			new_order_array[i] = orders[i];	//copy the memory which is in the save position
		}
		for(int i=index_of_order+1;i<order_num;i++){
			new_order_array[i-1] = orders[i];	//jump the order which one we want to delete, then let all orders move to the front of index
		}
		delete [] orders;
		orders = new_order_array;	
		order_num--;
	}
	else{
		cout<<"You cannnot remove order!"<<endl;
	}
}

/*********************************************
function: add_to_order
description: add one order to order file
parameters: order_to_add
pre-conditions: order_to_add should be an object
post-conditions: 
**********************************************/
void Restaurant::add_to_order(order order_to_add){
	order* new_order_array=new order[order_num+1];
	for(int i=0;i<order_num;i++){
		new_order_array[i]=orders[i];
	}
	new_order_array[order_num]=order_to_add;
	delete [] orders;
	orders = new_order_array;
	order_num++;
}

/*********************************************
function: place_order
description: user can full their order informatin in here
parameters: od_menu
pre-conditions: od_menu should be an object
post-conditions: 
**********************************************/
void Restaurant::place_order(Menu od_menu){
	ofstream new_order_file("orders.txt");
	order ord;	

	string first_name;
	cout<<"Enter your first name: "<<endl;
	cin >> ord.first_name;

	cout<<"Enter your last name: "<<endl;
	cin >> ord.last_name;

	do{
		string card_number;
		cout << "Enter your card number: "<<endl;
		cin >> ord.card_number;
	}while(!(atoi(ord.card_number.c_str())>0));

	string address;
	cout << "Enter your address: "<<endl;
	cin >> ord.address;

	do{
		string phone_number;
		cout << "Enter your phone numebr: "<< endl;
		cin >> ord.phone_number;
	}while(!(atoi(ord.phone_number.c_str())>0));

	for(int i=0;i<od_menu.get_num_pizzas();i++){
		ord.pizza_name = od_menu.get_pizzas()[i].get_name();
		do{
		cout << "Enter size for " << od_menu.get_pizzas()[i].get_name() << ": ";
		cin >> ord.size;
		}while(!(ord.size=="s"||ord.size=="S"||ord.size=="m"||ord.size=="M"||ord.size=="l"||ord.size=="L"));
		
		do{
		cout << "Enter amount for " << od_menu.get_pizzas()[i].get_name() << ": ";
		cin >> ord.pizza_amount;
		}while(!(atoi(ord.pizza_amount.c_str())>0));

		add_to_order(ord);
	}

	new_order_file << order_num << "\n";
	for(int i=0;i< order_num;i++){
		new_order_file<<i+1<<" "<<orders[i].first_name<<" "<<orders[i].last_name<<" "<<orders[i].card_number<<" "
		<<orders[i].address<<" "<<orders[i].phone_number<<" "<<orders[i].pizza_name << " " << orders[i].size<<" "<<orders[i].pizza_amount<<endl;
	}
	//new_order_file << orders->order_num<<" "<< orders->first_name<<" "<<orders->last_name <<" "<<orders->card_number<<" "<<orders->address <<" "<<orders->phone_number<<" "<<orders->size<<" "<<orders->pizza_amount;
	new_order_file.close();
}

/*********************************************
function: change_hours
description: employees can through this to change the hours that is the open hours for this restaurant
parameters: 
pre-conditions: 
post-conditions: 
**********************************************/
void Restaurant::change_hours(){
	print_restaurant_hours();
	cout<<"What day you want to change hours?"<<endl;
	string day="";
	cin >> day;
	cout<<"Change opening hours or closing hours?(1:open hour/2:close hour)"<<endl;
	int x=0;
	cin >> x;
	for(int i=0;i<line_num;i++){
		if(day==week[i].day){
			if(x==1){
				cout<<"What time you want to change?"<<endl;
				string y="";
				cin >> y;
				week[i].open_hour=y;
				output_file("restaurant_info.txt");
				cout<<"open hour already changed!"<<endl;
			}
			if(x==2){
				cout<<"What time you want to change?"<<endl;
				string y="";
				cin >>y;
				week[i].close_hour=y;
				output_file("restaurant_info.txt");
				cout<<"close hour already changed!"<<endl;
			}
		}
	}
}



/*********************************************
function:Restaurant
description:delete dynamic array of Restaurant
parameters: 
pre-conditions: 
post-conditions: 
**********************************************/
Restaurant::~Restaurant(){
	if(employees !=NULL)
		delete [] employees;
	if(week !=NULL)
		delete [] week;
	if(orders !=NULL)
		delete [] orders;
}

/*********************************************
function: Restaurant
description:copy Restaurant(construct)
parameters: copy
pre-conditions: 
post-conditions: 
**********************************************/
Restaurant::Restaurant(const Restaurant& copy){
	menu = copy.menu;
	employees = new employee[employees_num];
	for(int i=0;i<employees_num;i++){
		employees[i]=copy.employees[i];
	}
	week = new hours[line_num];
	for(int i=0;i<line_num;i++){
		week[i]=copy.week[i];
	}
	name = copy.name;
	phone = copy.phone;
	address = copy.address;
	orders = new order[order_num];
	for(int i=0;i<order_num;i++){
		orders[i]= copy.orders[i];
	}
}

/*********************************************
function: operator
description: assignment operator overload
parameters: copy
pre-conditions: 
post-conditions: 
**********************************************/
Restaurant& Restaurant::operator=(const Restaurant&copy){
	if(employees!=NULL){
		delete [] employees;
	}
	if(week !=NULL){
		delete [] week;
	}
	if(orders!=NULL){
		delete [] orders;
	}
	menu=copy.menu;
	if(employees_num!=0){
		employees = new employee[employees_num];
		for(int i=0;i<employees_num;i++){
			employees[i] = copy.employees[i];
		}
	}
	if(line_num!=0){
		week = new hours[line_num];
		for(int i=0;i<line_num;i++){
			week[i]=copy.week[i];
		}
	}
	name=copy.name;
	phone = copy.phone;
	address = copy.address;
	if(order_num!=0){
		orders = new order[order_num];
		for(int i=0;i<order_num;i++){
			orders[i]= copy.orders[i];
		}
	}
}

