#include "BinomialModel.h"
#include <cmath>
#include <iostream>

using namespace std;

double BinomialModel::RiskNeutralProbability() {

	return (Rate - D) / (U - D);

}

int BinomialModel::GetInputData(){

	cout << "enter the initial stock value, S0" << endl;
	cin >> s0;
	cout << "enter the U facter" << endl;
	cin >> U;
	cout << "enter the the D factor" << endl;
	cin >> D;
	cout << " enter the interest rate" << endl;
	cin >> Rate;
	

	// lets do some checked on the input values

	if (s0 < 0.0 || D <= -1.0 || U <= -1.0 || Rate <= -1.0 || U<=D)
	{
		cout << "Values inputted are out of data range" << endl;
		cout << "This program will now terminate" << endl;
		return 1;
	}
	
	// checking for arbatrage
	if (Rate >=U || Rate <= D) {
		cout << " arbatrage is present. terminating program" << endl;
		return 1;
	}
	cout << "Data is valid" << endl;
	return 0;
}

double BinomialModel::getRate() {
	return Rate;

}

double BinomialModel::StockPrice(int Node, int i)
{
	return s0 * pow(1 + U, i) * pow(1 + D, Node - i);
}