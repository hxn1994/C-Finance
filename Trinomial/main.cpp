#include <iostream>
#include "TriModel01.h"
#include "Option.h"
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    ofstream fileout;
    fileout.open("EurPrices.txt");

   TriModel Model(100,0.2,0.03);

   fileout << "Test the program:\n";
   Call Option1(100.0,1);
   fileout << "European call option price = "
        << Option1.PriceByTrinomial(Model,1)
        << endl << endl;

   Put Option2(100.0,1);
   fileout << "European put option price = "
        << Option2.PriceByTrinomial(Model,1)
        << endl << endl;

    Call Options[5] =
    {
        Call(100.0,100),
        Call(100.0,200),
        Call(100.0,300),
        Call(100.0,400),
        Call(100.0,500)
    };

    Put Options0[5] =
    {
        Put(100.0,100),
        Put(100.0,200),
        Put(100.0,300),
        Put(100.0,400),
        Put(100.0,500)
    };

    fileout << "There are a series of option prices following:\n";

    for (int i = 0; i < 5;i++)
    {
        fileout << "N = " << 100*(i+1) << " and T = 1" << endl;
        fileout << endl;
        fileout << "Call Option: "<< Options[i].PriceByTrinomial(Model,1) << endl;
        fileout << endl;
        fileout << "Put Option: "<< Options0[i].PriceByTrinomial(Model,1) << endl;
        fileout << endl << endl;
    }

    fileout.close();

    return 0;
}
