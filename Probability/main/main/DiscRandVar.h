#ifndef DiscRandVar_H_
#define DiscRandVar_H_
#include <iostream>

using namespace std;

class DiscRV
{
    private:
        int M;

    public:
        //Constructor. Sets value of M when initialising the class.
        DiscRV(int _M) : M (_M) {};

        //Changes value of M
        void SetM (int _M) { M = _M;};

        //Accesses value of M
        int GetM () { return M; };

        //computes value of probability mass function at point k
        //this is the function "p" in the practical
        virtual double PMF (int k) = 0;

        //computes expected value
        double Exp();
};

class Uniform
	:public DiscRV
{
public:
	//Constructor
	Uniform(int _M) :DiscRV(_M) {}
	~Uniform() {}

	double PMF(int k);
	double Exp();
	
};

class Binomial
	:public DiscRV
{
private:
	double p;
public:
	Binomial(int _M)
		:DiscRV(_M){}
	~Binomial() {}

	double Exp();
	double PMF(int k);
	double combinotorial(int k);
	int factorial(int k);

	friend istream &operator>>(istream &is, Binomial &bi);
};

class Degenerate
	:public DiscRV
{
private:
	int k_;
public:
	Degenerate(int _M) :DiscRV(_M) {};
	~Degenerate() {};

	double PMF(int k);
	double Exp() { return DiscRV::Exp(); }

	friend istream &operator>>(istream &is, Degenerate &de);
};

#endif
