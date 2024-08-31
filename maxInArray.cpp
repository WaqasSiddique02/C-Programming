#include <iostream>
using namespace std;

int findMax(int no[]) {
	int maxInt = 0;
	for (int i = 0; i <=5; i++) {
		int Int = no[i];
		if (Int>maxInt) {
			maxInt = Int;
		}
	}

	return maxInt;
}

int main() {
	int array[5] = { 8,3,1,4,2 };
	cout<<findMax(array);
	return 0;
}
