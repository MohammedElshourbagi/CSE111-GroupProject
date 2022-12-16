#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

double UserValidation(string message, double value) {					
	bool cond;
	cout << message; cin >> value;
	cond = cin.fail(); cin.clear(); cin.ignore(INT_MAX, '\n');
	while (cond) {
		cout << (" *INVALID: DATA TYPE* ") << "\t: Try Again = ";
		cin >> value; cond = cin.fail(); cin.clear(); cin.ignore(INT_MAX, '\n');
	};
	return value;
}

struct info {
	string username;
	string password;
	string address;
	int nationalID;
	int phonenumber;
};
struct history {
	float balance;
	float transiction;
};

struct user_node : public info {
	float balance;
	user_node* next_user_acc;
	history* hist;
	user_node() {
		nationalID = 0;
		phonenumber = 0;
		next_user_acc = NULL;
		hist = NULL;
	}
};
struct admin_node :private info {
	admin_node* next_admin_acc;
};

struct user : public info {
	user_node* head;
	user()
	{
		head = NULL;
	}
	bool isempty() {
		return (head == NULL);
	}
	bool Is_national_id_already_exist(int id)
	{
		bool exist = false;
		user_node* temp = head;
		user_node user;
		while (temp != NULL)
		{

			if (temp->nationalID == id)
				exist = true;
			temp = temp->next_user_acc;
		}
		return exist;
	}
	void signup() {
		string user1;
		string pass;
		string address1;
		double ID = 0;
		double number = 0;
		cout << "enter your username ";
		cin >> user1;
		cout << "enter your password ";
		cin >> pass;
		cout << "enter your address ";
		cin >> address1;
		/*cout << "enter your nationalid ";
		cin >> ID;
		cout << "enter your phonenumber ";
		cin >> number;
		*/
		/*UserVAlidation<string>("enter your username ", user1);
		UserVAlidation<string>("enter your password ", pass);
		UserVAlidation<string>("enter your address ", address1);*/
		ID = UserValidation("enter your nationalid ", ID);
		UserValidation("enter your phonenumber ", number);

		if (Is_national_id_already_exist(ID) == false)
		{
			user_node* user = new user_node();
			user->username = user1;
			user->password = pass;
			user->address = address1;
			user->nationalID = ID;
			user->phonenumber = number;
			if (isempty())
			{
				user->next_user_acc = NULL;
				user->hist = NULL;
				head = user;
			}
			else
			{
				user->next_user_acc = head;
				user->hist = NULL;
				head = user;
			}
		}
		else {
			cout << "this national ID is already exist";
		}
	}
	void display() {
		user_node* temp = head;
		while (temp != NULL)
		{
			cout << temp->username << " ";
			cout << temp->password << " ";
			cout << temp->address << " ";
			cout << temp->nationalID << " ";
			cout << temp->phonenumber << " ";
			temp = temp->next_user_acc;
		}
	}
	//once we creat a new account we have to make a new user_node
};
struct admin
{

	user_node* head;
	admin()
	{
		head = NULL;
	}
	//once we creat a new account we have to make a new admin_node
};
// for accessing the history we will need a temp1 to look at the specific account once the user loged in and a temp 2 to go deep in the history of the account
int main() {
	user u1;
	u1.signup();
	u1.display();
}
