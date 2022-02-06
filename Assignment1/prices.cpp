/*
Asks the user for the price values of some items as ###.##
Continues prompting for item prices until the user enters a negative value
Sums all positive prices and prints the result
*/
#include <iostream>
using namespace std;

int main()
{
    float individualPrice;
    float sumOfPrices = 0.0;

    cout << "Provide the price of some item in standard format (###.##): ";
    cin >> individualPrice;

    while (individualPrice >= 0)
    {
        sumOfPrices += individualPrice;
        cout << "Provide the price of some item in standard format (###.##): ";
        cin >> individualPrice;
    }

    cout << "The total sum is: $" << sumOfPrices << endl;

    return 0;
}