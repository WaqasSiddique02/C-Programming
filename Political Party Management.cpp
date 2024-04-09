#include <iostream>
using namespace std;

struct politics {
	string name;
	string leader;
	int nom;
};

void addParty(politics p[], int n=10)
{
	cout << "Enter name of party: ";
	cin >> p[n].name;
	cout << "Enter name of leader: ";
	cin >> p[n].leader;
	cout << "Enter number of members: ";
	cin >> p[n].nom;
	n++;
}

void addMember(politics p[], int n)
{
	string name;
	cout << "Enter name of party: ";
	cin >> name;
	for (int i = 0; i < n; i++)
	{
		if (p[i].name == name)
		{
			p[i].nom++;
			return;
		}
	}
	cout << "Party not found" << endl;
}

void searchLeader(politics p[], int n)
{
	string leader;
	cout << "Enter name of leader: ";
	cin >> leader;
	for (int i = 0; i < n; i++)
	{
		if (p[i].leader == leader)
		{
			cout << "Party name: " << p[i].name << endl;
			cout << "Number of members: " << p[i].nom << endl;
			return;
		}
	}
	cout << "Leader not found" << endl;
}

void searchParty(politics p[], int n)
{
	string name;
	cout << "Enter name of party: ";
	cin >> name;
	for (int i = 0; i < n; i++)
	{
		if (p[i].name == name)
		{
			cout << "Leader: " << p[i].leader << endl;
			cout << "Number of members: " << p[i].nom << endl;
			return;
		}
	}
	cout << "Party not found" << endl;
}


int main()
{
	const int size = 100;
	politics p[size];
	char choice;

	do {
		char op;
		cout << "***Manage political parties***\n";
		cout << "Enter your choice : " << endl;
		cout << "1. Add a party" << endl;
		cout << "2. Add a member to a party" << endl;
		cout << "3. Search by leader" << endl;
		cout << "4.Seach by party name" << endl;
		cout << "0. Exit" << endl;
		cin >> op;

		switch (op)
		{
		case'1':
			cout << "Add a political party" << endl;
			addParty(p);
			break;

		case'2':
			cout << "Add member to a party" << endl;
			addMember(p, size);
			break;

		case'3':
			cout << "Search by leader" << endl;
			searchLeader(p, size);
			break;

		case'4':
			cout << "Search by party name" << endl;
			searchParty(p,size);
			break;
		case'0':
			cout << "Exiting..." << endl;

			return 0;
		}
		cout << "Go to the main menu (Y/Any key) " << endl;
		cin >> choice;
	} while (choice=='Y'|| choice=='y');
}
