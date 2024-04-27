#include <iostream>
#include <string>
using namespace std;

const int max_size=100;

struct Books
{
	string title;
	string authorname;
	string ISBN;
};

void addbook (Books catalog[], int catalogsize)
{
	if (catalogsize<max_size)
	{
		cout << "Enter book details" << endl;
		cout << "Title ";
		cin.ignore();
		getline(cin, catalog[catalogsize].title);
		cout << "Author Name ";
		getline(cin, catalog[catalogsize].authorname);
		cout << "ISBN number";
		getline(cin, catalog[catalogsize].ISBN);

		cout << "Book added to the catalog" << endl;
		catalogsize++;
	}

	else
	{
		cout << "Catalog is full cannot add more books" << endl;
	}
}

void searchbytitle(Books catalog[],int catalogsize)
{
	string searchitem;
	cout << "Enter the title you want to search :" << endl;
	getline(cin, searchitem);

	for (int i=0;i<catalogsize;i++)
	{
		if (catalog[i].title==searchitem)
		{
			cout << "Book found" << endl;
			cout << "Book is at position " << i << endl;
			cout << "Title: " << catalog[i].title<<endl;
			cout << "Author Name" << catalog[i].authorname<<endl;
			cout << "ISBN no" << catalog[i].ISBN << endl;
			return ;
		}
	}

	cout << "Book did not found with the given title" << endl;
}

void displaycatalog(Books catalog[],int catalogsize)
{
	cout << "Library Catalog" << endl;
	for (int i=0;i<catalogsize;i++)
	{
		cout << "Book " << i + 1 << endl;
		cout << "Title " << catalog[i].title << endl;
		cout << "Author Name: " << catalog[i].authorname << endl;
		cout << "ISBN: " << catalog[i].ISBN << endl;
		cout << "______________________________________" << endl;
	}
}

int main()
{
	Books catalog[max_size];
	int catalog_size = 0;
	char opt, choice;

	do {
		cout << "** Welcome to Libary Catalog" << endl;
		cout << "========================================" << endl;
		cout << "Select one of the following" << endl;
		cout << "1. Add a book\n";
		cout << "2. Search by title\n";
		cout << "3. Sort catalog by title \n";
		cout << "4. Display entire library catalog\n";
		cout << "0. Exit\n";
		cin >> opt;

		switch (opt)
		{
		case'1':
			addbook(catalog, catalog_size);
			break;

		case'2':
			searchbytitle(catalog, catalog_size);
			break;

		case'3':
			break;

		case'4':
			displaycatalog(catalog,catalog_size);
			break;

		case'0':
			return 0;
		}

		cout << "Do you want to go main menu (Y/N) " << endl;
		cin >> choice;
	} while (choice =='Y'||choice =='y');

	return 0;
}
