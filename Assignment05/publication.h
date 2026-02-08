#ifndef PUBLICATION_H
#define PUBLICATION_H
using namespace std;

double calculateCost (int pages);
double calculateCost (int pages, bool hardcover);
double calculateCost (int pages, bool hardcover, int colorPages);
double calculateCost (int pages, double discountPercent);
void printReceipt (int pages, bool hardcover, int colorPages,double cost, double discountPercent);

#endif
