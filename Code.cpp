#include <iostream>
using namespace std;

class Product {
private:
    string name;
    double price;
    static double discountRate; // Static discount rate for all products

public:
    Product(string n, double p) : name(n), price(p) {}

    static void setDiscountRate(double rate) {
        discountRate = rate;
    }

    double calculateFinalPrice() const {
        return price * (1 - discountRate / 100);
    }

    void display() const {
        cout << "Product: " << name << " | Original Price: $" << price
             << " | Discounted Price: $" << calculateFinalPrice() << endl;
    }
};

// Initialize static member
double Product::discountRate = 0.0;

int main() {
    Product::setDiscountRate(10); // Set global discount rate to 10%

    Product p1("Laptop", 1000);
    Product p2("Phone", 500);

    p1.display();
    p2.display();

    Product::setDiscountRate(20); // Change discount rate to 20%

    cout << "\nAfter changing discount rate:\n";
    p1.display();
    p2.display();

    return 0;
}
