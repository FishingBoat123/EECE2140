#include <iostream>
#include "publication.h"
using namespace std;

int main ()
{
    int option = 0;
    cout << "Publication Cost Calculator" << endl;
    cout << "============================" << endl;
    cout << "Please select an option:" << endl;
    cout << "1. Cost by pages only" << endl;
    cout << "2. Cost by pages and hardcover" << endl;
    cout << "3. Cost by pages, hardcover and color pages" << endl;
    cout << "0, Exit" << endl;
    cout << " ===========================" << endl;
    cout << "Option => ";
    cin >> option;

    switch (option)
    {
        case 1:
        {
            //inout pages
            int pages;
            cout << "Enter the number of pages: ";
            cin >> pages;
            
            //discount?
            char discount_option;
            double discountPercent = 0;
            cout << "Discount? (y/n) ";
            cin >> discount_option;
            
            if (discount_option == 'y' || discount_option == 'Y')
            {
                cout << "Enter the discount percentage: ";
                cin >> discountPercent;
                double cost = calculateCost(pages, discountPercent);
                if (cost >= 0)
                {
                    printReceipt(pages, false, 0, cost, discountPercent);
                }
                else
                {
                    cout << "Invalid input for pages or discount. Please enter valid inputs." << endl;
                }
            }
            
            else
            {
                double cost = calculateCost(pages);
                printReceipt(pages, false, 0, cost, discountPercent);
            }
            

            break;
        }
        case 2:
        {
            int pages;
            char hardcover_option;
            bool hardcover;
            cout << "Enter the number of pages: ";
            cin >> pages;
            cout << "Is it hardcover (y/n)? ";
            cin >> hardcover_option;

            if (hardcover_option == 'y' || hardcover_option == 'Y')
            {
                hardcover = true;
            }
            else
            {
                hardcover = false;
            }

            double cost = calculateCost(pages, hardcover);

            if (cost >= 0)
            {
                printReceipt(pages, hardcover, 0, cost, 0);
            }
            else
            {
                cout << "Invalid input for pages or hardcover. Please enter valid inputs." << endl;
            }
            printReceipt(pages, hardcover, 0, cost, 0);
            break;
        }
        case 3: 
        {
            int pages;
            char hardcover_option;
            bool hardcover;
            int colorPages;
            cout << "Enter the number of pages: ";
            cin >> pages;
            cout << "Is it hardcover (y/n)? ";
            cin >> hardcover_option;

            if (hardcover_option == 'y' || hardcover_option == 'Y')
                {
                    hardcover = true;
                }
                else
                {
                    hardcover = false;
                }

            cout << "Enter the number of color pages: ";
            cin >> colorPages;
            double cost = calculateCost(pages, hardcover, colorPages);

            if (cost >= 0)
            {
                printReceipt(pages, hardcover, colorPages, cost, 0);
            }
            else
            {
                cout << "Invalid input for pages or hardcover or color pages. Please enter valid inputs." << endl;
            }
            break;
        }

        case 0:
        {
            return 0;
        }
        default:
        {
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }
}
