#include <iostream>
#include <string>

using namespace std;

class Ship {
protected:
    string name;
    string yearBuilt;
public:
    Ship(string shipName, string buildYear) {
        name = shipName;
        yearBuilt = buildYear;
    }

    string getName() {
        return name;
    }

    void setName(string newName) {
        name = newName;
    }

    string getYearBuilt() {
        return yearBuilt;
    }

    void setYearBuilt(string newYear) {
        yearBuilt = newYear;
    }

    virtual void print() {
        cout << "Ship's Name: " << name << "\nYear Built: " << yearBuilt << endl;
    }
};

class CruiseShip : public Ship {
private:
    int maxPassengers;
public:
    CruiseShip(string shipName, string buildYear, int passengers) : Ship(shipName, buildYear) {
        maxPassengers = passengers;
    }

    int getMaxPassengers() {
        return maxPassengers;
    }

    void setMaxPassengers(int passengers) {
        maxPassengers = passengers;
    }

    void print() {
        cout << "Ship's Name: " << name << "\nMax Passengers: " << maxPassengers << endl;
    }
};

class CargoShip : public Ship {
private:
    int cargoCapacity;
public:
    CargoShip(string shipName, string buildYear, int capacity) : Ship(shipName, buildYear) {
        cargoCapacity = capacity;
    }

    int getCargoCapacity() {
        return cargoCapacity;
    }

    void setCargoCapacity(int capacity) {
        cargoCapacity = capacity;
    }

    void print() {
        cout << "Ship's Name: " << name << "\nCargo Capacity: " << cargoCapacity << " tons" << endl;
    }
};

int main() {
    Ship* ships[3];

    ships[0] = new Ship("Titanic", "1912");
    ships[1] = new CruiseShip("Queen Mary 2", "2004", 2640);
    ships[2] = new CargoShip("Emma Maersk", "2006", 156907);

    for (int i = 0; i < 3; ++i) {
        ships[i]->print();
        cout << endl;
    }

    for (int i = 0; i < 3; ++i) {
        delete ships[i];
    }

    return 0;
}
