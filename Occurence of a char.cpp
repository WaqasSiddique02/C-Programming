#include <iostream>
using namespace std;

int checkChar(string longString, char singleChar) {
	int var=0;
	for (int i = 0; i < longString.length();i++) {
		if (longString[i]==singleChar) {
			var++;
		}
	}
	return var;
}

int main() {
	string longString = "Hello this is my world";
	char singleChar;
	cout << "Enter the character you want to find occurance of " << endl;
	cin >> singleChar;
	cout<<checkChar(longString,singleChar);
	return 0;
}
