#include <iostream>
using namespace std;

class Box {
private:
    float length, breadth, height, vol;

public:
    Box() {
        length = 0;
        breadth = 0;
        height = 0;
        vol = 0;
    }

    void setlength(float len) {
        length = len;
    }

    void setbreadth(float bred) {
        breadth = bred;
    }

    void setheight(float hei) {
        height = hei;
    }

    float getlength() {
        return length;
    }

    float getbreadth() {
        return breadth;
    }

    float getheight() {
        return height;
    }

    float volume() {
        vol = length * breadth * height;
        return vol;
    }

    void input() {
        cout << "Enter Height: " << endl;
        cin >> height;
        cout << "Enter Breadth: " << endl;
        cin >> breadth;
        cout << "Enter Length: " << endl;
        cin >> length;
    }

    void display() {
        cout << "Height : " << height << endl;
        cout << "Breadth: " << breadth << endl;
        cout << "Length: " << length << endl;
    }

    void displayvolume() {
        cout << "Volume= " << volume() << endl;
    }

    Box operator+(const Box& p) const {
        Box temp;
        temp.length = p.length + length;
        temp.breadth = p.breadth + breadth;
        temp.height = p.height + height;
        return temp;
    }

    Box operator-(const Box& p) const {
        Box temp;
        temp.length = p.length - length;
        temp.breadth = p.breadth - breadth;
        temp.height = p.height - height;
        return temp;
    }

    Box operator*(const Box& p) const {
        Box temp;
        temp.length = p.length * length;
        temp.breadth = p.breadth * breadth;
        temp.height = p.height * height;
        return temp;
    }

    Box& operator=(const Box& p) {
        if (this == &p)
            return *this;
        length = p.length;
        breadth = p.breadth;
        height = p.height;
        vol = p.vol;
        return *this;
    }

    bool operator >(const Box& p) {
        if (length>p.length) {
            return true;
        }

        if (length = p.length) {
            return true;
        }
        return false;
    }

    bool operator <(const Box& p) {
        if (length < p.length) {
            return true;
        }

        if (length = p.length) {
            return true;
        }
        return false;
    }
};

int main() {
    char x;

    Box obj1, obj2, obj3;
    obj1.input();
    obj2.input();

    obj1.display();
    obj2.display();

    obj1.displayvolume();
    obj2.displayvolume();

    cout << "1. ADD" << endl;
    cout << "2. Subtract " << endl;
    cout << "3. Multiply" << endl;
    cout << "4. > " << endl;
    cout << "5. < " << endl;
    cout << "6. = " << endl;
    cin >> x;

    switch (x) {
    case '1':
        obj3 = obj1 + obj2;
        obj3.display();
        break;
    case '2':
        obj3 = obj1 - obj2;
        obj3.display();
        break;
    case '3':
        obj3 = obj1 * obj2;
        obj3.display();
        break;
    case '4':
        if (obj1>obj2) {
            cout << "Obj-1 > obj-2" << endl;
        }
        else {
            cout << "false" << endl;
        }
        break;
    case '5':
        if (obj1 < obj2) {
            cout << "Obj-1 < obj-2" << endl;
        }
        else {
            cout << "False" << endl;
        }

        break;
 
    case '6':
        obj3 = obj1;
        cout << "Copied obj1 to obj3" << endl;
        obj3.display();
        break;
    default:
        cout << "Invalid option" << endl;
    }
    return 0;
}
