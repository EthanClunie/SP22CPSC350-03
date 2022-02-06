/*
Asks the user for the ages of 3 people, then prints the youngest and oldest ages.
*/
#include <iostream>
using namespace std;

int main()
{
    int temp;
    int ages[3];
    
    for (int i = 0; i < 3; i++) /// Populates the array with the ages of three people from the user
    {
        cout << "Provide the age of one person: ";
        cin >> ages[i];
    }

    for (int i = 0; i < 3; i++) /// Orders the array of integers in ascending order
    {
        for (int j = i+1; j < 3; j++)
        {
            if (ages[i] > ages[j])
            {
                temp = ages[i];
                ages[i] = ages[j];
                ages[j] = temp;
            }
        }
    }
    
    cout << "The youngest and oldest are: " << ages[0] << " and " << ages[2] <<", respectively." << endl;

    return 0;
}