#include <iostream>
using namespace std;

class GroceryItem
{
    private:
    int stockNumber;
    double price;
    int quantityInStock;
    double totalValue;

    void enterStock()
    {
        int stock;
        while (true)
        {
            cout << "\nPlease input stock number: " << endl;
            cin >> stock;
            if (stock > 1000 && stock < 9999)
            {
                setStockNumber(stock);
                break;
            }
            else
            {
                cout << "\nPlease enter a valid number between 1000 and 9999";
            };
        }
        
    }

    void enterPrice()
    {
        double price;
        while (true)
        {
            cout << "\nPlease enter the price: " << endl;
            cin >> price;
            if (price > 0)
            {
                setPrice(price);
                break;
            }
            else
            {
                cout << "\nPlease enter a valid non-negative number" << endl;
            };
        }
    }

    void enterQuantity()
    {
        double quantity;
        while (true)
        {
            cout << "\nPlease enter the quantity: " << endl;
            cin >> quantity;
            if (quantity > 0)
            {
                setQuantity(quantity);
                break;
            }
            else
            {
                cout << "\nPlease enter a valid non-negative number" << endl;
            };
        }
    }

    double value()
    {
        totalValue = price * quantityInStock;
        return totalValue;
    }
    
    public:
    GroceryItem(){}

    void setStockNumber(int stockNumber){this->stockNumber = stockNumber;}
    void setPrice(double price){this->price = price;}
    void setQuantity(int quantity){quantityInStock = quantity;}
    void setTotalValue(double totalValue){this->totalValue = totalValue;}

    int const getStockNumber(){return stockNumber;}
    double const getPrice(){return price;}
    int const getQuantityInStock(){return quantityInStock;}
    double const getTotalValue(){return totalValue;}

    void dataEnter()
    {
        enterStock();
        enterPrice();
        enterQuantity();
        value();
    }

    void display()
    {
        cout << "\n===== Grocery Stock Info =====";
        cout << "\nStock Number: " << getStockNumber();
        cout << "\nPrice: " << getPrice();
        cout << "\nQuantity in stock: " << getQuantityInStock();
        cout << "\nTotal Value: " << getTotalValue();
    }
};

int main()
{
    GroceryItem grocery[10];
    for(int i = 0; i < 10; i++)
    {
        int stock;
        double price;
        int quantity;
        double total;

        grocery[i].dataEnter();
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "\n===== Grocery Items" << grocery[i].getStockNumber() << " =====";
        grocery[i].display();
    }
}