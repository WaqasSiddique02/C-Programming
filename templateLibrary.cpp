#include <iostream>
#include <string>
using namespace std;

template<typename T, typename U>
class Inventory {
private:
    T itemNo, quantity;
    U cost, totalCost;
public:
    Inventory() {
        itemNo = T();
        quantity = T();
        cost = U();
        totalCost = U();
    }

    Inventory(T itNo, T quan, U cost) {
        itemNo = itNo;
        quantity = quan;
        this->cost = cost;
        setTotalCost();
    }

    void setItemNo(T itmNo) {
        itemNo = itmNo;
    }

    void setQuantity(T qua) {
        quantity = qua;
    }

    void setCost(U price) {
        cost = price;
    }

    void setTotalCost() {
        totalCost = quantity * cost;
    }

    T getItemNo() {
        return itemNo;
    }

    T getQuantity() {
        return quantity;
    }

    U getCost() {
        return cost;
    }

    U getTotalCost() {
        return totalCost;
    }

    ~Inventory() {}
};

int main() {
    int itemNo, quantity;
    double cost;

    cout << "Enter item No: ";
    cin >> itemNo;

    cout << "Enter quantity of product: ";
    cin >> quantity;

    cout << "Enter price of the product: ";
    cin >> cost;

    Inventory<int, double> obj(itemNo, quantity, cost);
    cout << "Item No: " << obj.getItemNo() << endl;
    cout << "Quantity: " << obj.getQuantity() << endl;
    cout << "Cost: " << obj.getCost() << endl;
    cout << "Total Cost: " << obj.getTotalCost() << endl;

    return 0;
}
