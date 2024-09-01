#include <iostream>
using namespace std;

int find2ndMax(int arr[],int size) {
	int temp=0;
	int secTemp = 0;

	for (int i = 0; i <size-1 ; i++) {
		if (arr[i]>temp) {
			temp = arr[i];
		}
	}
	
	for (int i = 0; i < size-1;i++) {
		if (arr[i]>secTemp && arr[i]<temp) {
			secTemp = arr[i];
		}
	}

	return secTemp;
}

int main() {
	int size = 5;
	int arr[5] = { 7,2,1,4,3 };
	cout<<find2ndMax(arr,size);
	return 0;
}
