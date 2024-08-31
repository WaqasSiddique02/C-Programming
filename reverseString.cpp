//Program to reverse a string with out allocating any extra memory
#include <iostream>
using namespace std;

void reverseString(const string &input) {
	for (int i = input.length()-1; i >= 0; --i) {
		cout << input[i];
	}
}

int main() {
	string OldString = "Hello World";
	reverseString(OldString);
	return 0;
}
