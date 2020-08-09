#include "Options.h"
#include "BinomialModel.h"
#include <iostream>
#include <cmath>
using namespace std;

double EuropeanOption::PriceByCrosRosR(BinomialModel BinMod){

	double* Price = new double[Node + 1];
	double q = BinMod.RiskNeutralProbability();
	for (int i = 0; i <= Node; i++) {
		Price[i] = payoff(BinMod.StockPrice(Node, i));
	}
	for (int n = Node - 1; n >= 0; n--)
	{
	for (int i = 0; i <= n; i++) {
		Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / (1 + BinMod.getRate());
	}

}
	double price = Price[0];
	delete[] Price;
	return price;
}

int Call::getInputData()
{
	cout << "enter call option data" << endl;
	int N;
	cout << "enter steps to expire N" << endl;
	cin >> N;
	SetNode(N);
	cout << "enter the strike price" << endl;
	cin >> K;
	return 0;
}

double Call::payoff(double z)
{
	if (z > K)
		return z - K;
	return 0.0;
}

int Put::getInputData()
{
	cout << "enter put option data" << endl;
	int N;
	cout << "enter steps to expire N" << endl;
	cin >> N;
	SetNode(N);
	cout << "enter the strike price" << endl;
	cin >> K;
	return 0;
}

double Put::payoff(double z)
{
	if (z < K)
		return K-z;
	return 0.0;
}


int DoubleDigit::getInputData()
{
	cout << "enter double digit option data" << endl;
	int N;
	cout << "enter steps to expire N" << endl;
	cin >> N;
	SetNode(N);
	cout << "enter the lower strike price" << endl;
	cin >> K1;
	cout << "enter the upper strike price" << endl;
	cin >> K2;
	return 0;
}

double DoubleDigit::payoff(double z)
{
	if (K1<z && K2 >z)
		return 1.0;
	return 0.0;
}
