#include <iostream>
#include <string>;
using namespace std;

char op;
float salesamount;
float salepercent;
double salary;

void access()
{
	

	cout << "Select Your Status: " << endl;
	cout << "[1] Full-Time" << endl;
	cout << "[2] Part-Time" << endl;
	cin >> op;

	cout << "Enter your sales amount" << endl;
	cin >> salesamount;

}

void utility()
{
	access();

	salepercent = (salesamount / 100) * 30;
	switch (op)
	{
	case'1':
		if (salesamount>=500)
		{
			salary = 1000.00 + salesamount + salepercent;
		}
		else {
			salary = 1000.00 + salesamount ;
		}

		break;

	case'2':
		if (salesamount >= 500)
		{
			salary = 500.00 + salesamount + salepercent;
		}
		else {
			salary = 500.00 + salesamount;
		}

		break;

	default:
		cout << "Option not in the list enter again" << endl;
	}
}

void display()
{
	utility();
	cout << "Your total salary :" << salary << endl;
}

int main()
{
	string name;

	cout << "*** Welcome to salesman Calculator ***" << endl;
	cout << "Enter your name : ";
	getline(cin, name);
	
	display();

	return 0;
}
