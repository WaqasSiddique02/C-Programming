#include <iostream>
using namespace std;

int inputarr[20];
int n,j;

void input()
{
	
	cout << "Enter size of the array: ";
	cin >> n;

	for (int i=0;i<n;i++)
	{
		cin >> inputarr[i];
	}
}

void insertsort()
{
	int temp;

	cout << "Insertion sort " << endl;
	for (int i = 1; i < n; i++)
	{
		temp = inputarr[i];
		j = i - 1;

		while (inputarr[j] > temp && j >= 0)
		{
			inputarr[j + 1] = inputarr[j];
			j--;
		}
		inputarr[j + 1] = temp;
	}

	for (int i = 0; i < n; i++)
	{
		cout << inputarr[i] << "\t";
	}
}

void bubblesort()
{
	int temp;

	cout << "Bubble sort :" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (inputarr[j] < inputarr[i])
			{
				temp = inputarr[i];
				inputarr[i] = inputarr[j];
				inputarr[j] = temp;
			}
		}
	}
	cout << endl;

	cout << "Sorted elements are :" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << inputarr[i] << "\t";
	}
}

void linear()
{
	int key;
	cout << "Linear Search" << endl;
	cout << "Enter the element you want to search" << endl;
	cin >> key;

	for (int i = 0; i < 8; i++)
	{
		if (inputarr[i] == key)
		{
			cout << i; 
		}
	}
}

void binary()
{
	int temp;
	int mid, key;
	int a,b;
	cout << "Enter number you want to search" << endl;
	cin >> key;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (inputarr[j] < inputarr[i])
			{
				temp = inputarr[i];
				inputarr[i] = inputarr[j];
				inputarr[j] = temp;
			}
		}
	}
	cout << endl;

	cout << "Sorted elements are :" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << inputarr[i] << "\t";
	}
	cout << endl;

	mid = ceil( n / 2);

	if (mid==key)
	{
		cout << mid;
	}

	else if (mid > key)
	{
		for (int i=mid;i<=n;i++)
		{
		    a= inputarr[i];
		}
		cout << "Is at positon : " << a << endl;
	}

	else if (mid < key)
	{
		for (int i=0;i<mid;i++)
		{
			 b= inputarr[i];
		}
		cout << "Is at position : " << b << endl;
	}
}

int main()
{
	char op;

	cout << "Enter an array :" << endl;
	input();

	cout << "select one of the following " << endl;
	cout << "[1] Insertion Sort" << endl;
	cout << "[2] Bubble Sort" << endl;
	cout << "[3] Linear Search" << endl;
	cout << "[4] Binary Search" << endl;
	cout << "[5] Exit" << endl;

	cin >> op;

	switch (op)
	{
	case'1':
		insertsort();
		break;

	case'2':
		bubblesort();
		break;

	case'3':
		linear();
		break;

	case'4':
		binary();
		break;

	case'5':
		return 0;

	default:
		cout << "Option not in the list" << endl;
		break;
	}

	return 0;
}
