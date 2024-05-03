#include <iostream>
#include <string>
using namespace std;

template<typename T, typename U, typename V>
class Product {
protected:
    T name;
    U quantity;
    V price;

public:
    Product() {
        name = T();
        quantity = U();
        price = V();
    }

    Product(T n, U q, V p) {
        name = n;
        quantity = q;
        price = p;
    }

    virtual void display() {
        cout << "Name: " << name << ", Quantity: " << quantity << ", Price: $" << price << endl;
    }

    virtual ~Product() {}
};

template<typename T, typename U, typename V, typename W, typename X, typename Y>
class Electronics : public Product<T, U, V> {
private:
    W manufacturer;
    X modelNumber;
    Y warrantyMonths;

public:
    Electronics(T n, U q, V p, W m, X mn, Y w) : Product<T, U, V>(n, q, p) {
        manufacturer = m;
        modelNumber = mn;
        warrantyMonths = w;
    }

    void display() {
        cout << "Type: Electronics, ";
        Product<T, U, V>::display();
        cout << "Manufacturer: " << manufacturer << ", Model Number: " << modelNumber << ", Warranty (months): " << warrantyMonths << endl;
    }
};

template<typename T, typename U, typename V, typename W, typename X, typename Y>
class Clothing : public Product<T, U, V> {
private:
    W size;
    X color;
    Y material;

public:
    Clothing(T n, U q, V p, W s, X c, Y m) : Product<T, U, V>(n, q, p) {
        size = s;
        color = c;
        material = m;
    }

    void display() {
        cout << "Type: Clothing, ";
        Product<T, U, V>::display();
        cout << "Size: " << size << ", Color: " << color << ", Material: " << material << endl;
    }
};

template<typename T, typename U, typename V, typename W>
class Books : public Product<T, U, V> {
private:
    W author;
    string genre;

public:
    Books(T n, U q, V p, W a, string g) : Product<T, U, V>(n, q, p) {
        author = a;
        genre = g;
    }

    void display() {
        cout << "Type: Book, ";
        Product<T, U, V>::display();
        cout << "Author: " << author << ", Genre: " << genre << endl;
    }
};

int main() {
    Electronics<string, int, float, string, string, int> laptop("Laptop", 10, 999.99, "Waqasr", "123XYZ", 12);
    Clothing<string, int, float, string, string, string> shirt("Shirt", 20, 29.99, "M", "Blue", "Cotton");
    Books<string, int, float, string> novel("Novel", 5, 15.99, "Waqas", "Fiction");

    laptop.display();
    shirt.display();
    novel.display();

    return 0;
}
