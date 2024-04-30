#include<iostream>
using namespace std;

int main()
{
	int rows;
	cout << "Enter the number of rows" << endl;
	cin >> rows;

	for (int i =rows;i>=1;i--)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << (char)(64 + j);
		}
		cout << endl;
	}
}
