#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>

using namespace std;

string global_name;

void logo();

void temp_main();

int start_menu();
int login_menu();

bool login_function();

void order_function();

void signup_admin();
void view_admin();
void check_sales();

void add_item();
void view_menu();

void logo(){
    cout << "********************************************\n";
    cout << "*   ,____       _       ,______ ,______    *\n";
    cout << "*  /           / \\      |       |          *\n";
    cout << "* /           /   \\     |       |          *\n";
    cout << "*|           /_____\\    |-----  |-----     *\n";
    cout << "*|          /       \\   |       |          *\n";
    cout << "* \\        /         \\  |       |          *\n";
    cout << "*  \\_____ /           \\ |       |______    *\n";
    cout << "********************************************\n";
}

void temp_main(){
    bool a=0;
	int i=0;
	int switch_first;
	do
	{
		system("cls");
		if (i==0)
		{
			switch_first=start_menu();
			switch (switch_first)
			{
				case 1:
					{
						a=login_function();
						if(a==1)
							i=1;
						break;
					}
				case 2:
					{
						order_function();
						break;
				 	}
				case 3:
					{
						cout << "thank you for your time see you soon!!!!!!!!!!!!!";
						return;
					}
			}
			system("cls");
			if (a==0)
				continue;
		}
		if(i==1)
		{
			switch_first=login_menu();
			switch (switch_first)
			{
			    case 1:
					{
						view_menu();
						break;
					}
				case 2:
					{
						add_item();
						break;
					}
				case 3:
					{
						check_sales();
						break;
					}
				case 4:
					{
						signup_admin();
						break;
					}
				case 5:
					{
						view_admin();
						break;
					}
				case 6:
					{
						a=0;
						i=0;
						continue;
					}
			}
			if(a==1 && i==1)
				continue;
		}
	}while(true);
}

int start_menu(){
    int A;
	do
	{
		logo();
		cout << "welcome!!!!!!!!!!!\n"
		     << "Note --> If you signup your account will be saved you don't have to signup again.\n"
		     << "Note --> You cannot login without an account\n"
			 << "1. Login (as admin)\n"
			 << "2. Order (as customer)\n"
			 << "3. Exit\n"
			 << "\t\t\tENTER YOUR COMMAND: ";
		cin >> A;
		system("cls");
	}while(A>3 && A<1);
	return A;
}

int login_menu(){
	int A;
	do
	{
		logo();
		cout << "USER_NAME: " << global_name << endl
			 << "1. View Menu\n"
			 << "2. add item\n"
			 << "3. checks sales\n"
			 << "4. ADD admin\n"
			 << "5. VIEW ALL admin\n"
			 << "6. LOG OUT\n"
			 << "ENTER YOUR COMMAND:";
		cin >> A;
		system("cls");
	}while(A>6 && A<1);
	return A;
}

bool login_function(){
    bool check=0;
	char answer='n';
	string read_id , read_pass;
	do
	{
		logo();
		string id , pass;
		cout << "ENTER ADMIN ID: ";
		cin >> id;
		cout << "ENTER PASSWORD: ";
		cin >> pass;
		
		ifstream login_data("admin_details.txt");
		while (login_data >> read_id >> read_pass)
		{
			if(id==read_id && pass==read_pass)
				check=1;
		}
		if(check==0)
		{
			cout << "INVALID DEYAILS DO YOU WANT TO TRY AGAIN!!!!(Y/N)";
			cin >> answer;
		}
		system("cls");
	}while(check==0 && (answer=='y' || answer=='Y'));
	return check;
}

void view_menu(){
    logo();
	string A,B;
	int id = 1;
	cout << "ID\t\t\t\tPRICE\t\t\t\tITEM\n";
	ifstream data("menu_details.txt");
	while(data >> A >> B)
		cout << id++ << "\t\t\t\t" << A << "\t\t\t\t" << B << endl;
	system("pause");
	system("cls");
}

void view_admin(){
    logo();
	string A,B;
	int id = 1;
	cout << "NO.\t\t\t\tID\t\t\t\tPASSWORD\n";
	ifstream data("admin_details.txt");
	while(data >> A >> B)
		cout << id++ << "\t\t\t\t" << A << "\t\t\t\t" << B << endl;
	system("pause");
	system("cls");
}

void add_item(){
    do
	{
		logo();
		bool try_again=0;
		string item, price;
		cout << "ENTER ITEM NAME: ";
		cin >> item;
		cout << "ENTER PRICE: ";
		cin >> price;
		string read_item ,read_price;
		ifstream data("menu_details.txt");
		while(data >> read_price >> read_item)
		{
			if (read_item == item)
			{
				cout << "we have this item in menu !!!!!!!!!!!!!!!!!!!!! try again........\n";
				system("pause");
				data.close();
				try_again=1;
				break;
			}
		}
		system("cls");
		if (try_again)
			continue;
		else{
			cout << "Do you want to save this data(y/n): ";
			char a;
			cin >> a;
			if (a == 'n' || a == 'N'){
				break;
			}
		}
		ofstream signup_data("menu_details.txt", ios::app);
		signup_data << price << "\t" << item << endl;
		break;
	}while(true);
}

void signup_admin(){
	do
	{
		logo();
		bool try_again=0;
		string id, pass;
		cout << "ENTER YOUR ID: ";
		cin >> id;
		cout << "ENTER PASSWORD: ";
		cin >> pass;
		string read_id, read_pass;
		ifstream login_data("admin_details.txt");
		while(login_data >> read_id >> read_pass)
		{
			if (read_id == id)
			{
				cout << "we have this id registered !!!!!!!!!!!!!!!!!!!!! try again........\n";
				system("pause");
				login_data.close();
				try_again=1;
				break;
			}
		}
		system("cls");
		if (try_again)
			continue;
		else{
			cout << "Do you want to save this data(y/n): ";
			char a;
			cin >> a;
			if (a == 'n' || a == 'N'){
				break;
			}
		}
		ofstream signup_data("admin_details.txt", ios::app);
		signup_data << id << "\t" << pass << endl;
		break;
	}while(true);
}

void check_sales(){
    logo();
	string A,B,C,D,E,F,G,H;
	int id = 1;
	cout << "NO.\t\t\t\tTime\t\t\t\tPrice\t\t\t\tItem\t\t\t\tCusomer\n";
	ifstream data("order_details.txt");
	while(data >> A >> B >> C >> D >> E >> F >> G >> H){
		cout << id++ << "\t\t\t\t" << D << " " << E << " " << F << " " << G << " " << H << "\t" << A << "\t\t\t\t" << B << "\t\t\t\t" << C << endl;
	}
	system("pause");
	system("cls");
}

int customer_menu(){
    int A;
	do
	{
		logo();
		cout << "welcome!!!!!!!!!!!\n"
		     << "1. Buy Item\n"
			 << "2. Return\n"
			 << "\t\t\tENTER YOUR COMMAND: ";
		cin >> A;
		system("cls");
	}while(A>2 && A<1);
	return A;
}

void buy_menu(){
    logo();
	string A,B;
	int id = 1;
	cout << "ID\t\t\t\tPRICE\t\t\t\tITEM\n";
	ifstream data("menu_details.txt");
	while(data >> A >> B)
		cout << id++ << "\t\t\t\t" << A << "\t\t\t\t" << B << endl;
}


void order_function(){
	string Name;
	cout << "Enter your Name: ";
	cin >> Name;
	int choice;
	do{
		system("cls");
		choice = customer_menu();
		switch(choice){
			case 1:
				{
					bool try_again = 1;
					buy_menu();
					ifstream file("menu_details.txt");
					string A,B,a;
					cout << "Enter which item you would like to buy: ";
					cin >> a;
					while (file >> A >> B)
					{
						if(a==B)
						{
							ofstream order("order_details.txt", ios::app);
							time_t now = time(NULL);
							order << A << "\t" << B << "\t" << Name << "\t" << ctime(&now) << endl;
							system("pause");
							try_again = 0;
							break;
						}
					}
					if(try_again){
						cout << "Try again\n";
						system("pause");
					}
					break;
				}
			case 2:
				{
					cout << "THANKS FOR SHOPPING WITH US.\n";
					system("pause");
					return;	
				}
		}
	}while(true);
}

int main(){
    temp_main();
}

