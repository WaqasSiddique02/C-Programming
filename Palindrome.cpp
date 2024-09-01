#include <iostream>
using namespace std;

string isPalindrome(string word) {
	bool var= false;
	for (int i = 0; i < word.length();i++) {
		for (int j = word.length()-1;j>=0; j--) {
			if (word[i]==word[j]) {
				var = true;
			}
			else {
				var= false;
			}
		}
	}
	if (var == true) {
		return "String is palindrome";
	}
	else if (var==false){
		return "String is not palindrome";
	}
}

int main() {
	string word;
	cout << "Enter the string you want to check" << endl;
	cin >> word;
	cout<<isPalindrome(word);
	return 0;
}
