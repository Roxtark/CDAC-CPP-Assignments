#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Product
{
private:
    int productId;
    string name;
    double price;
    int quantity;

public:
    void acceptDetails()
    {
        cout << "Enter Product ID: ";
        cin >> productId;

        cout << "Enter Product Name: ";
        cin >> name;

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> quantity;
    }

    void displayDetails() const
    {
        cout << left << setw(8) << productId
             << setw(15) << name
             << right << setw(10) << fixed << setprecision(2) << price
             << setw(8) << quantity
             << setw(15) << totalValue();

        cout << endl;
    }

    double totalValue() const
    {
        return price * quantity;
    }

    bool isLowStock(int threshold) const
    {
        return quantity < threshold;
    }

    string getName() const
    {
        return name;
    }
};

double reorderCost(int qty, double unitPrice)
{
    return qty * unitPrice;
}

double reorderCost(double qty, double unitPrice)
{
    return qty * unitPrice;
}

double reorderCost(int qty, double unitPrice, double taxRate)
{
    double cost = qty * unitPrice;
    return cost + (cost * taxRate / 100);
}

double applyDiscount(double price, double discountPercent = 10.0)
{
    return price - (price * discountPercent / 100);
}

int main()
{
    Product products[5];

    cout << "===== ENTER PRODUCT DETAILS =====" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "\nProduct " << i + 1 << endl;
        products[i].acceptDetails();
    }

    cout << "\n===== INVENTORY REPORT =====" << endl;

    cout << left << setw(8) << "ID"
         << setw(15) << "Name"
         << right << setw(10) << "Price"
         << setw(8) << "Qty"
         << setw(15) << "Total Value" << endl;

    for (int i = 0; i < 5; i++)
    {
        products[i].displayDetails();
    }

    int highestIndex = 0;

    for (int i = 1; i < 5; i++)
    {
        if (products[i].totalValue() > products[highestIndex].totalValue())
        {
            highestIndex = i;
        }
    }

    cout << "\nHighest Value Product : "
         << products[highestIndex].getName()
         << " (Rs. "
         << fixed << setprecision(2)
         << products[highestIndex].totalValue()
         << ")" << endl;

    int threshold;

    cout << "\nEnter low stock threshold: ";
    cin >> threshold;

    cout << "\nLow Stock (threshold: " << threshold << ") : ";

    bool found = false;

    for (int i = 0; i < 5; i++)
    {
        if (products[i].isLowStock(threshold))
        {
            cout << products[i].getName() << " ";
            found = true;
        }
    }

    if (!found)
    {
        cout << "No products";
    }

    cout << endl;

    cout << "\n===== FUNCTION OVERLOADING =====" << endl;

    int intQty = 10;
    double unitPrice = 50.0;
    double fractionalQty = 2.5;
    double taxRate = 18.0;

    cout << "Reorder cost (int quantity): Rs. "
         << reorderCost(intQty, unitPrice) << endl;

    cout << "Reorder cost (double quantity): Rs. "
         << reorderCost(fractionalQty, unitPrice) << endl;

    cout << "Reorder cost with tax: Rs. "
         << reorderCost(intQty, unitPrice, taxRate) << endl;

    cout << "\nDiscounted price with default 10% discount: Rs. "
         << applyDiscount(1000) << endl;

    cout << "Discounted price with 20% discount: Rs. "
         << applyDiscount(1000, 20) << endl;

    return 0;
}