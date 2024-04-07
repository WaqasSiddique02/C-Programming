#include<iostream>
using namespace std;

class Complex_Number {
public:
    double real;
    double imag;

    Complex_Number(double r, double i) {
        real = r;
        imag = i;
    }
};

int main() {
    double n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;

    Complex_Number c1(n1, n2);

    Complex_Number c2(n3, n4);

    double real_sum = n1+n3;

    double imag_sum = n2+n4;

    if(imag_sum>=0){
    cout << real_sum << " + " << imag_sum << "i" << endl;
    }
    else {
        cout << real_sum << imag_sum << "i" << endl;
    }

    return 0;
}
