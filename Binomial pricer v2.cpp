#include "BinomialModel.h"
#include "Options.h"
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    BinomialModel Model;
    if (Model.GetInputData() == 1) return 1;
    
    Put Option1;
    Option1.getInputData();
    cout << " put option price = " << Option1.PriceByCrosRosR(Model)
        << endl;

    Call Option2;
    Option2.getInputData();
    cout << " Call option price = " << Option2.PriceByCrosRosR(Model)
        << endl;

    DoubleDigit Option3;
    Option3.getInputData();
    cout << " DoubleDigit option price = " << Option3.PriceByCrosRosR(Model)
        << endl;

    //delete[] Price;
    return 0;

}
