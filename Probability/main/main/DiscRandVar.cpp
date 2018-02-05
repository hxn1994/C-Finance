#include "DiscRandVar.h"
#include <iostream>
#include <cmath>

using namespace std;

double DiscRV::Exp()
{
	double exp = 0.0;

	for (int i = 0; i < M; i++)
		exp += i*PMF(i);

	return exp;
}

///Uniform methods

double Uniform::PMF(int k)
{
	double pmf = 0.0;

	for (int i = 0; i <= k; i++)
		pmf += 1.0/(1.0+GetM());

	return pmf;
}

///Binomial methods
istream & operator>>(istream & is,Binomial &bi)
{
	is >> bi.p;
	while (is && bi.p >= 1)
	{
		cout << "p cannot be greater than 1.Please try again.\n";
		is >> bi.p;
	}

	return is;// TODO: 在此处插入 return 语句
}

double Binomial::PMF(int k)
{
	double pmf = 0.0;
	for (int i = 0; i <= k; i++)
		pmf += combinotorial(i) * pow(p, i)*pow(1-p, GetM() - i);

	return pmf;
}

int Binomial::factorial(int k)
{
	if (k == 1 || k == 0)
		return 1;
	else
		return k * factorial(k - 1);

}

double Binomial::combinotorial(int k)
{
	if(k > GetM() || k < 0)
		return 0.0;
	
	double com = 0.0;
	com = factorial(GetM()) / (factorial(k)*factorial(GetM() - k));
	return com;
}

double Binomial::Exp()
{
	return DiscRV::Exp();
}

/// Degenerate methods
double Degenerate::PMF(int k)
{
	k = k_;
	if (k_ <= GetM() || k_ >= 0)
		return 1.0;
	else
		return 0.0;
}

istream &operator>>(istream &is, Degenerate &de)
{
	is >> de.k_;
	while (is && de.k_ > de.GetM() && de.k_ <0)
	{
		cout << "k_ is out of range.Please try again.\n";
		is >> de.k_;
	}
	return is;
}
