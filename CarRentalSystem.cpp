#include <iostream>
#include <string>
using namespace std;

class Cars {
private:
	string make[10];
	string model[10];
	int year[10];
public:
	int count=0;
	int id=0;
	Cars() {
		for (int i = 0; i < 10; i++) {
			make[i] = "";
			model[i] = "";
			year[i] = 0;
		}
	}

	void addCar() {
		int no;
		cout << "How many cars you want to insert";
		cin >> no;
		count = no + count;
		cout << "Enter Cars make model and year" << endl;
		for (int i = 0; i < no;i++) {
			cout << "Make: ";
			cin >> this->make[i];

			cout << "Model: ";
			cin >> this->model[i];

			cout << "Year: ";
			cin >> this->year[i];
		}
	}

	void displayCar() {
		if (count == 0) {
			cout << "No record found " << endl;
		}
		else{
		for (int i = 0; i < count;i++) {
			cout << "Make: " << make[i] << " Model:" << model[i] << " Year:" << year[i] << endl;
		}
		}
	}

	void updateCar() {
		cout << "Enter car ID number" << endl;
		cin >> id;
		cout << "Make = ";
		cin >>this->make[id-1];

		cout << "Model = ";
		cin >> this->model[id-1];

		cout << "Year = ";
		cin >> this->year[id-1];
	}

	void deleteCar() {
		cout << "Enter Car id Number" << endl;
		cin >> id;
		this->make[id-1] = "N/A";
		this->model[id-1] = "N/A";
		this->year[id-1] = 0;
		if (id<count) {
			cout << "Car Deleted Successfully" << endl;
		}
		else {
			cout << "Record Not found" << endl;
		}
	}

	~Cars() {}
};

int main() {
	Cars car;
	int menuOption;
	char switchOption;

	do {
		cout << "Welcome to Car Management System" << endl;
		cout << "1.Display Record Set" << endl;
		cout << "2.Insert in to Records" << endl;
		cout << "3.Update a Record" << endl;
		cout << "4.Delete a Record" << endl;
		cout << "0.Exit" << endl;
		cin >> menuOption;

		switch (menuOption) {
		case 1:
			car.displayCar();
			break;

		case 2:
			car.addCar();
			break;

		case 3:
			car.updateCar();
			break;
		case 4:
			car.deleteCar();
			break;
		case 0:
			return 0;
		default:
			cout << "Option not in the list " << endl;
		}
		cout << "Go Back to the main menu <y/n>";
		cin >> switchOption;
	} while (switchOption=='y'|| switchOption=='Y');

	return 0;
}