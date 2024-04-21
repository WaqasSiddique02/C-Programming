#include <iostream>
using namespace std;

class Container {
private:
	int* values;
	int capacity;
	int counter;
public:
	Container(int c) {
		capacity = c;
		counter = 0;
		values = new int[capacity];
	}

	~Container() {
		delete[] values;
	}

	bool isfull() {
		if (counter==capacity) {
			cout << "Cotainer full" << endl;
			return true;
		}

		else {
			return false;
		}
	}

	void insertval(int val) {
		if (!isfull()) {
			values[counter++] = val;
		}
		else {
			cout << "Container is full cannot add more vales" << endl;
		}
	}

	bool search(int val) {
		for (int i = 0; i < counter; i++) {
			if (values[i] == val) {
				cout << "Value found at index " << i << endl;
				return true;
			}
		}
		cout << "Value not found" << endl;
		return false;
	}


	void remove(int val) {
		for (int i = 0; i < counter;i++) {
			if (values[i]==val) {
				for (int j = i; j < counter - 1;++j) {
					values[j] = values[j + 1];
				}
				counter--;
				break;
			}
		}
	}

	void Print() {
		cout << "Container elements:" << endl;
		for (int i = 0; i < counter; ++i) {
			cout << values[i] << " ";
		}
		cout << endl;
	}

};

int main() {
	Container container(5); 

	container.insertval(10);
	container.insertval(20);
	container.insertval(30);
	container.insertval(40);
	container.insertval(50);

	container.Print();

	(container.search(30));

	int valueToRemove = 30;
	container.remove(valueToRemove);

	container.Print();

	return 0;
}
