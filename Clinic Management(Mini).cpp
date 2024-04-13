#include <iostream>
#include <string>
using namespace std;

class Pet {
protected:   //used protected members cz protected members are also usable in sub class
    string name;
    int age;
    string issue;
public:
    // Default constructor
    Pet() {
        name = " ";
        age = 0;
        issue = " ";
    }

    // Parameterized constructor
    Pet(string n, int a, string i)  {
        name = n;
        age = a;
        issue = i;
    }

    // Getter methods
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    string getIssue() {
        return issue;
    }

    // Display method
    void displayPet() const {
        cout << "Name: " << name << "\tAge: " << age << "\tIssue: " << issue << endl;
    }

    // Overloaded comparison operators
    bool operator >( Pet& p) {
        return age > p.age;
    }

    bool operator <( Pet& p) {
        return age < p.age;
    }

    bool operator ==(Pet& p) {
        return age == p.age;
    }
};

class Dog : public Pet {
private:
    string breed;
public:
    // Default constructor
    Dog(){
        breed = " ";
    }

    // Parameterized constructor
    Dog(string n, int a, string i, string b) : Pet(n, a, i), breed(b) {}

    // Getter method for breed
    string getBreed() {
        return breed;
    }

    // Display method
    void display() {
        displayPet();
        cout << "Breed of dog: " << breed << endl;
    }
};

class Cat : public Pet {
private:
    string breed;
public:
    // Default constructor
    Cat() {
        breed = " ";
    }

    // Parameterized constructor
    Cat(string n, int a, string i, string b) : Pet(n, a, i), breed(b) {}

    // Getter method for breed
    string getBreed() {
        return breed;
    }

    // Display method
    void display() {
        displayPet();
        cout << "Breed of cat: " << breed << endl;
    }
};

class Owner {
private:
    string name;
    int cellno;
    int age;
public:
    // Default constructor
    Owner() {
        name = " ";
        cellno = 0;
        age = 0;
    }

    // Parameterized constructor
    Owner(string n, int cell, int a)  {
        name = n;
        cellno = cell;
        age = a;
    }

    // Getter methods
    string getName() {
        return name;
    }

    int getAge()  {
        return age;
    }

    int getCell()  {
        return cellno;
    }

    // Display method
    void displayOwner() const {
        cout << "Name: " << name << "\tAge: " << age << "\tCell: " << cellno << endl;
    }
};

class Appointment {
private:
    Pet pet;
    Owner owner;
    int hr;
    int min;
    string day;
public:
    // Default constructor
    Appointment()  {
        hr = 0;
        min = 0;
        day = " ";
    }

    // Parameterized constructor
    Appointment(Pet p, Owner o, int h, int m, string d)  {
        min = m;
        hr = h;
        day = d;
        pet = p;
        owner = o;
    }

    // Getter methods
    int getHr() {
        return hr;
    }

    int getMin() {
        return min;
    }

    string getDay() {
        return day;
    }

    // Display method
    void displayAppointment() {
        owner.displayOwner();
        cout << "Appointment Time" << endl;
        cout << "Hours: " << hr << " Minutes: " << min << " Day: " << day << endl;
    }
};

int main() {
    Dog dog("Buddy", 3, "Fever", "Labrador");
    Owner owner("Awais", 1234567890, 23);
    cout << endl;
    Appointment appointment(dog, owner, 10, 30, "2024-04-01");
    Cat cat("smoky", 5, "Cough", "persian");
    Owner owner2("Waqas", 1234567890, 19);
    Appointment appointment2(dog, owner, 10, 30, "2024-04-01");

    dog.display();
    appointment.displayAppointment();
    cout << endl;
    cat.display();
    appointment2.displayAppointment();

    Pet pet1("Sam",2,"Headache"), pet2("Rose",3,"Backpain");
    cout << endl;

    cout << "Comparing age using operator overlaoding " << endl;
    if (pet1>pet2) {
        cout << "Pet1 Age is greater" << endl;
    }
    else if(pet1==pet2) {
        cout << "Pet1 age is equal to pet2" << endl;
    }
    else {
        cout << "Pet2 age is greater" << endl;
    }

    return 0;
}
