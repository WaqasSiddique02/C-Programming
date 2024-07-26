#include <iostream>
using namespace std;

template<typename T>
class circle {
private:
	T radius;
	T pi = 3.14159;
	T area, diameter, circumference;

public:
	circle() { radius = T(); }
	circle(T r) {
		radius = r;
	}

	~circle() {}

	void setRadius(T radius) {
		this->radius = radius;
	}

	T getRadius() {
		return radius;
	}

	T getArea() {
		area = pi * radius * radius;
		return area;
	}

	T getDiameter() {
		diameter = radius * 2;
		return diameter;
	}

	T getCircumference() {
		circumference = 2 * pi * radius;
		return circumference;
	}
};

int main()
{
	circle<double> obj;
	double rad;
	cout << "Enter Radius of the circle " << endl;
	cin >> rad;
	obj.setRadius(rad);
	double radius = obj.getRadius();
	double area = obj.getArea();
	double diameter = obj.getDiameter();
	double circumference = obj.getCircumference();

	cout << "Radius of Circle : " << radius << endl;
	cout << "Area : " << area << endl;
	cout << "Diameter: " << diameter << endl;
	cout << "Circumference: " << circumference << endl;
	return 0;
}
