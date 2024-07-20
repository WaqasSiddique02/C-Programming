#include <iostream>
#include <string>
#include <fstream>
#include <typeinfo>

using namespace std;

class Vehicle
{
protected:
    string licensePlate;
    int entryTime;

public:
    Vehicle()
    {
        licensePlate = "";
        entryTime = 0;
    }

    Vehicle(string licensePlate, int entryTime)
    {
        this->licensePlate = licensePlate;
        this->entryTime = entryTime;
    }

    virtual ~Vehicle() {}

    virtual double calculateFee() const = 0;
    virtual void display()
    {
        cout << "LicensePlate of Vehicle: " << licensePlate << endl;
        cout << "EntryTime of Vehicle: " << entryTime << endl;
    }

    string getLicensePlate()
    {
        return licensePlate;
    }

    int getEntryTime()
    {
        return entryTime;
    }
};

class Car : public Vehicle
{
protected:
    string name;
    string type;
    string model;

public:
    Car()
    {
        name = "";
        type = "";
        model = "";
    }

    Car(string name, string type, string model, string licensePlate, int entryTime) : Vehicle(licensePlate, entryTime)
    {
        this->name = name;
        this->type = type;
        this->model = model;
    }

    ~Car() {}

    double calculateFee() const override
    {
        return 50.0;
    }

    void display()
    {
        cout << "----------------Showing Info----------------------" << endl;
        cout << "Name of Car: " << name << endl;
        cout << "Type of Car: " << type << endl;
        cout << "Model of Car: " << model << endl;
        cout << "LicensePlate of Car: " << licensePlate << endl;
        cout << "EntryTime of Car: " << entryTime << endl;
    }
};

class Bike : public Vehicle
{
protected:
    string name;
    string type;
    string model;

public:
    Bike()
    {
        name = "";
        type = "";
        model = "";
    }

    Bike(string name, string type, string model, string licensePlate, int entryTime) : Vehicle(licensePlate, entryTime)
    {
        this->name = name;
        this->type = type;
        this->model = model;
    }

    ~Bike() {}

    double calculateFee() const override
    {
        return 20.0;
    }

    void display()
    {
        cout << "----------------Showing Info----------------------" << endl;
        cout << "Name of Bike: " << name << endl;
        cout << "Type of Bike: " << type << endl;
        cout << "Model of Bike: " << model << endl;
        cout << "LicensePlate of Bike: " << licensePlate << endl;
        cout << "EntryTime of Bike: " << entryTime << endl;
    }
};

class Truck : public Vehicle
{
protected:
    string name;
    string type;
    string model;

public:
    Truck()
    {
        name = "";
        type = "";
        model = "";
    }

    Truck(string name, string type, string model, string licensePlate, int entryTime) : Vehicle(licensePlate, entryTime)
    {
        this->name = name;
        this->type = type;
        this->model = model;
    }

    double calculateFee() const override
    {
        return 70.0;
    }

    void display()
    {
        cout << "----------------Showing Info----------------------" << endl;
        cout << "Name of Truck: " << name << endl;
        cout << "Type of Truck: " << type << endl;
        cout << "Model of Truck: " << model << endl;
        cout << "LicensePlate of Truck: " << licensePlate << endl;
        cout << "EntryTime of Truck: " << entryTime << endl;
    }
};

template <typename T>
class ParkingLot
{
    Vehicle* parkedVehicles[100];
    int parkedCount;
    static int totalVehicles;

public:
    ParkingLot()
    {
        parkedCount = 0;
        totalVehicles = 3;
    }

    void parkVehicle(Vehicle* vehicle)
    {
        if (parkedCount >= 100)
        {
            cerr << "Error: Parking lot is full." << endl;
            return;
        }
        parkedVehicles[parkedCount++] = vehicle;
        totalVehicles++;
    }

    void retrieveVehicle(const string& license)
    {
        for (int i = 0; i < parkedCount; ++i)
        {
            if (parkedVehicles[i]->getLicensePlate() == license)
            {
                for (int j = i; j < parkedCount - 1; ++j)
                {
                    parkedVehicles[j] = parkedVehicles[j + 1];
                }
                parkedVehicles[--parkedCount] = nullptr;
                totalVehicles--;
                return;
            }
        }
        cerr << "Error: Vehicle not found." << endl;
    }

    static int getTotalVehicles()
    {
        return totalVehicles;
    }

    void saveRecords(const string& filename)
    {
        ofstream file(filename);
        for (int i = 0; i < parkedCount; ++i)
        {
            file << parkedVehicles[i]->getLicensePlate() << ","
                << typeid(*parkedVehicles[i]).name() << ","
                << parkedVehicles[i]->getEntryTime() << "\n";
        }
        file.close();
    }

    void loadRecords(const string& filename)
    {
        ifstream file(filename);
        string line;
        while (getline(file, line))
        {
            string license;
            string type;
            int entryTime;
            size_t pos1 = line.find(',');
            size_t pos2 = line.find(',', pos1 + 1);

            license = line.substr(0, pos1);
            type = line.substr(pos1 + 1, pos2 - pos1 - 1);
            entryTime = stoi(line.substr(pos2 + 1));

            Vehicle* vehicle = nullptr;
            if (type == typeid(Car).name())
            {
                vehicle = new Car("", "", "", license, entryTime);
            }
            else if (type == typeid(Bike).name())
            {
                vehicle = new Bike("", "", "", license, entryTime);
            }
            else if (type == typeid(Truck).name())
            {
                vehicle = new Truck("", "", "", license, entryTime);
            }
            parkVehicle(vehicle);
        }
        file.close();
    }

    void displayParkedVehicles() const
    {
        for (int i = 0; i < parkedCount; ++i)
        {
            parkedVehicles[i]->display();
        }
    }
};

template <typename T>
int ParkingLot<T>::totalVehicles = 3;

int main()
{
    cout << "Name: Muhammad Waqas Siddiue" << endl;
    ParkingLot<Vehicle> lot;
    char op;
    Vehicle* obj1 = new Car("MyCar", "Electric", "17", "ABC123", 800);
    Vehicle* obj2 = new Bike("MyBike", "Normal", "19", "XYZ789", 900);
    Vehicle* obj3 = new Truck("MyTruck", "Normal", "21", "LMN456", 1000);

    cout << "__________________WELCOME TO PARKING MANAGEMENT SYSTEM_______________________" << endl;

    while (true)
    {

        cout << "-----------------------Menu:--------------------------------" << endl;
        cout << "Press 1)  To Display Information of Parked Vehicles" << endl;
        cout << "Press 2)  To check total Parked Vehicles" << endl;
        cout << "Press 3)  To Park a Vehicle" << endl;
        cout << "Press 4)  To Retrieve a Vehicle" << endl;
        cout << "Press 5)  To Save Records to File" << endl;
        cout << "Press 6)  To Load Records from File" << endl;
        cout << "Press 7)  To Exit" << endl;
        cout << "Enter your choice: ";
        cin >> op;

        switch (op)
        {
        case '1':
        {
            obj1->display();
            obj2->display();
            obj3->display();
            break;
        }
        case '2':
            cout << "Total vehicles parked: " << ParkingLot<Vehicle>::getTotalVehicles() << endl;
            break;
        case '3':
        {
            string name, type, model, licensePlate;
            int entryTime;
            cout << "Enter vehicle details (name type model licensePlate entryTime): ";
            cin >> name >> type >> model >> licensePlate >> entryTime;

            Vehicle* vehicle = nullptr;
            if (type == "Car")
            {
                vehicle = new Car(name, type, model, licensePlate, entryTime);
            }
            else if (type == "Bike")
            {
                vehicle = new Bike(name, type, model, licensePlate, entryTime);
            }
            else if (type == "Truck")
            {
                vehicle = new Truck(name, type, model, licensePlate, entryTime);
            }

            if (vehicle)
            {
                lot.parkVehicle(vehicle);
                cout << "Vehicle parked successfully." << endl;
            }
            else
            {
                cout << "Invalid vehicle type!" << endl;
            }
            break;
        }
        case '4':
        {
            string license;
            cout << "Enter license plate of the vehicle to retrieve: ";
            cin >> license;
            lot.retrieveVehicle(license);
            break;
        }
        case '5':
        {
            string filename;
            cout << "Enter filename to save records: ";
            cin >> filename;
            lot.saveRecords(filename);
            cout << "Records saved successfully." << endl;
            break;
        }
        case '6':
        {
            string filename;
            cout << "Enter filename to load records: ";
            cin >> filename;
            lot.loadRecords(filename);
            cout << "Records loaded successfully." << endl;
            break;
        }
        case '7':
        {
            cout << "Exiting" << endl;
            return 0;
        }
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }

    cout << "232441" << endl;

    return 0;
}
