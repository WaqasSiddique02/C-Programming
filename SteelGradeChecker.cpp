#include <iostream>
using namespace std;

int main()
{
	float hardness, carbon, tstrength;
	char again;

	cout << "=> A certain grade of steel is graded according to the following conditions :" << endl;
	cout << "(i)Hardness must be greater than 50" << endl
		 << "(ii)Carbon content must be less than 0.7" << endl
		 << "(iii)Tensile strength must be greater than 5600" << endl;
	cout << endl;

	do
	{
		cout << "=> Enter the value of hardness" << endl;
		cin >> hardness;

		cout << "=> Enter the value of carbon content" << endl;
		cin >> carbon;

		cout << "=> Enter the value of tensile strength " << endl;
		cin >> tstrength;

		if (hardness > 50 && carbon < 0.7 && tstrength > 5600)
		{
			cout << "The grade of steel is 10" << endl;
		}
		else if (hardness > 50 && carbon < 0.7 && tstrength < 5600)
		{
			cout << "The grade of steel is 9" << endl;
		}
		else if (hardness < 50 && carbon < 0.7 && tstrength > 5600)
		{
			cout << "The grade of steel is 8" << endl;
		}
		else if (hardness > 50 && carbon > 0.7 && tstrength > 5600)
		{
			cout << "The grade of steel is 7" << endl;
		}
		else if (hardness > 50 || carbon < 0.7 || tstrength > 5600)
		{
			cout << "The grade of steel is 6" << endl;
		}
		else
		{
			cout << "The grade of steel is 5" << endl;
		}

		cout << endl;
		cout << "Do you want to enter the values again (Y/y=yes,N/n=No)" << endl;
		cin >> again;

	} 
	while (again == 'Y' || again == 'y');

	return 0;
}
