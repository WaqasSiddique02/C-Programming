#include <iostream>
using namespace std;

int arr[3][3];

void array_print()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> arr[i][j];
		}
	}
}

void rowhighest()
{
	int highest;
	int* point = &highest;

	for (int i=0;i<3;i++)
	{
		highest = arr[i][0];
		for (int j = 0; j < 3; j++)
		{
			if (highest < arr[i][j])
			{
				highest = arr[i][j];
			}
		}
		cout << "Highest in row " << i+1 << "=" << *point <<endl;
		cout << "Address of Highest in row " << i + 1 << "=" << &highest << endl;
	}
}

void rowlowest() 
{
	int lowest;
	int* point2 = &lowest;

	for (int i = 0; i < 3; i++)
	{
		lowest = arr[i][0];
		for (int j = 0; j < 3; j++)
		{
			if (lowest> arr[i][j])
			{
				lowest = arr[i][j];
			}
		}
		cout << "Lowest in row " << i + 1 << "=" << *point2<< endl;
		cout << "Address of lowest in row " << i + 1 << "=" << &lowest << endl;
	}
}

void colhighest()
{
	int colhighest;
	int* colpoint = &colhighest;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			colhighest = arr[0][j];

			if (colhighest < arr[j][i])
			{
				colhighest = arr[j][i];
			}
		}
		cout << "Highest in col " << i + 1 << "= " << *colpoint << endl;
		cout << "Address of Highest in col " << i + 1 << "= " << &colhighest << endl;
	}
}

void collowest()
{
	int collowest;
	int* colpoint = &collowest;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			collowest = arr[0][i];

			if (collowest > arr[j][i])
			{
				collowest = arr[j][i];
			}
		}
		cout << "Lowest in col " << i + 1 << "= " << *colpoint << endl;
		cout << "Address of Lowest in col " << i + 1 << "= " << &colhighest << endl;
	}
}

void leftdiagnol()
{
	int sum;
	 sum = 0;
	 int *point4 = &sum;

	for (int i=0,j=0;i<3;i++,j++)
	{
		sum += arr[i][j];
	}
	cout << "The sum of left diagnol is : " << *point4 << endl;
	cout << "The address of sum of left diagnol is : " << &sum << endl;

}

void rightdiagnol()
{
	int sum = 0;
	int* pointer5 = &sum;

	for (int i = 0,j=2;i<3;i++,j--)
	{
			sum += arr[i][j];
	}
	cout << "The sum of Right diagnol is : " << *pointer5 << endl;
	cout << "The address of sum of right diagnol is : " << &sum << endl;
}

void rowsum()
{
	int sum = 0;
	int* pointer6 = &sum;

	for (int i=0;i<3;i++)
	{
		sum = 0;

		for (int j=0;j<3;j++)
		{
			sum += arr[i][j];
		}
		cout << "Sum of row " << i+1 << " is " << *pointer6 << endl;
		cout << "Address Sum of row " << &sum << endl;
	}
}

void colsum()
{
	int sum = 0;
	int* pointer7 = &sum;

	for (int i = 0; i < 3; i++)
	{
		int sum = 0;
		for (int j = 0; j < 3; j++)
		{
			sum += arr[j][i];
		}
		cout << "Sum of row " << i+1 << "is " << *pointer7 << endl;
		cout << "Address of Sum of row " << i + 1 << "is " << &sum << endl;
	}
}

int main()
{
	char option;
	char choice;

	cout << "Enter elements of a 3x3 array" << endl;
	array_print();
	cout << endl;
	do {
		cout << "==================Main Menu===================" << endl;
		cout << "1. Rows Highest " << endl;
		cout << "2. Rows Lowest " << endl;
		cout << "3. Cols Highest " << endl;
		cout << "4. Cols Lowest " << endl;
		cout << "5. Left Diagnol Sum " << endl;
		cout << "6. Right Diagnol Sum " << endl;
		cout << "7. Row Sum " << endl;
		cout << "8. Column Sum " << endl;
		cout << "9. Exit" << endl;
		cin >> option;

		switch (option)
		{
		case '1':
			rowhighest();
			cout << endl;
			break;

		case '2':
			rowlowest();
			cout << endl;
			break;

		case '3':
			colhighest();
			cout << endl;
			break;

		case '4':
			collowest();
			cout << endl;
			break;

		case '5':
			leftdiagnol();
			cout << endl;
			break;

		case '6':
			rightdiagnol();
			cout << endl;
			break;

		case '7':
			rowsum();
			cout << endl;
			break;

		case '8':
			colsum();
			cout << endl;
			break;
		case '9':
			return 0;
			break;
		default:
			cout << "option not in the list " << endl;
			break;
		}

		cout << "Do you again want enter an option (Y/press any key) " << endl;
		cin >> option;
	}
	while (option == 'Y' || option == 'y');

	return 0;
}
