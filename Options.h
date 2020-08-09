#ifndef Options_h
#define Options_h
#include "BinomialModel.h"
class EuropeanOption
{
private:
	int Node;
public:
	void SetNode(int Node_) { Node = Node_; }
	virtual double  payoff(double z) = 0;
	double PriceByCrosRosR(BinomialModel BinMod);
};

class Put : public EuropeanOption
{
private:
	double K;
public:
	void Setk(double K_) { K = K_; }
	int getInputData();
	double payoff(double z);
};

class Call : public EuropeanOption
{
private:
	double K;
public:
	void Setk(double K_) { K = K_; }
	int getInputData();
	double payoff(double z);
};


class DoubleDigit : public EuropeanOption
{
private:
	double K1;
	double K2;
public:
	int getInputData();
	double payoff(double z);
};

#endif