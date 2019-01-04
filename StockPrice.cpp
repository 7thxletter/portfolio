// Name: Gerard Lawrence
// Program: C++
// Summary: This program determines the cost of a stock, the amount of commission to be paid on the stock and the subtotal of everything.
// 09/10/2017

#include <iostream> 
#include <string>
using namespace std;

int main()

{
//declaring variables 
double stocks, price, commission, stock_total, commission_total, final_total;

//amounts variables are equal to
stocks = 750;
price = 35.00;
commission = .02;

//final totals
stock_total = stocks * price;
commission_total = stock_total * commission;
final_total = stock_total + commission_total;

//amounts that will be printed out
cout << stock_total << endl;
cout << commission_total << endl;
cout << final_total << endl;

return 0;

}

