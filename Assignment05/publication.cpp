#include <iostream>
#include "publication.h"
using namespace std;

// only pages
double calculateCost (int pages)
{
    if (pages <= 0)
    {
        return -1;
    }

    return calculateCost(pages, false, 0);
}

// pages and hardcover
double calculateCost (int pages, bool hardcover)
{
    if (pages <= 0)
    {
        return -1;
    }

    return calculateCost(pages, hardcover, 0);
}

// pages, hardcover and color pages
double calculateCost (int pages, bool hardcover, int colorPages)
{
    if (pages <= 0)
    {
        return -1;
    }
    if (colorPages < 0 || colorPages > pages)
    {
        return -1;
    }

    double cost = pages * 0.05;

    if (hardcover)
    {
        cost += 7.50;
    }
    
    cost += colorPages *0.20;
    
    return cost;
}

//discount
double calculateCost (int pages, double discountPercent)
{
    if (pages <= 0)
    {
        return -1;
    }
    if (discountPercent < 0 || discountPercent > 50)
    {
        return -1;
    }
    else
    {
        double cost = calculateCost(pages);
        cost -= cost * (discountPercent / 100);
        return cost;
    }
}

//receipt
void printReceipt (int pages, bool hardcover, int colorPages, double cost, double discountPercent)
{
    cout << "===================" << endl;
    cout << "Receipt" << endl;
    cout << "===================" << endl;
    cout << "Pages: " << pages << endl;
    cout << "Hardcover: " << (hardcover ? "Yes" : "No") << endl;
    cout << "Color Pages: " << colorPages << endl;
    cout << "Discount: " << cost * (discountPercent / 100) << endl;
    cout << "Total Cost: $" << cost << endl;
}

