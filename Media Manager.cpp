#include <iostream>
using namespace std;

class Media {
private:
	string title;
	string author;
	int identifier;
public:
	Media() {
		title = " ";
		author = " ";
		identifier = 0;
	}

	void setvalues(string title,string author,int ident) {
		this->title = title;
		this->author = author;
		this->identifier = ident;
	}

	string getauthor() {
		return author;
	}

	string gettitle() {
		return title;
	}

	int getident() {
		return identifier;
	}

	void display() {
		cout << "Title: " << title << "\t Author: " << author << "\t Identifier: " << identifier << endl;
	}
};

class Books :public Media {
private:
	int Pages;
public:
	Books() {
		Pages = 0;
	}
};

class Movie :public Media {
private:
	int time;
public:
	Movie() {
		time = 0;
	}

};

class CD :public Media {
	int track;
public:
	CD() {
		track = 0;
	}
};

int main() {
	Books Item;
	Movie M1;
    Item.setvalues("Waqas","Uni Niggaz",567890);
	Item.getauthor();
	Item.gettitle();
	Item.getident();
	Item.display();
	M1.setvalues("JD", "Beast", 1234890);
	M1.getauthor();
	M1.gettitle();
	M1.getident();
	M1.display();

	return 0;
}
