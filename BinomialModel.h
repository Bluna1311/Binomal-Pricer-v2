#ifndef BinomialModel_h
#define BinomialModel_h


class BinomialModel
{
private :
	double s0;
	double D;
	double U;
	double Rate;

public :
	double RiskNeutralProbability();
	double StockPrice(int node, int i);
	int GetInputData();
	double getRate();

};

#endif