#include "Option.h"
#include "../TriModel01.h"
#include <iostream>
#include <cmath>

using namespace std;

double EurOption::PriceByTrinomial(TriModel Model, double T)
{

   Model.Set_dtdx(T,N);
   double qu = Model.RiskNeutProb_up();
   double qd = Model.RiskNeutProb_down();
   double qm = 1 - qu - qd;
   double Price[2*N-1];

   int j;
   for (int i = 2*N-1, j = 0;j <= 2*N;i--,j++)
   {
       if (j < N-1)
       {
           int a = (-1)*i;
           Price[j] = Payoff(Model.S(N,a));
       }
       else
       {
           Price[j] = Payoff(Model.S(N,i));
       }

   }

   for (int n = 2*N-1; n >= 0; n--)
   {
       for (int i = 0; i < n; i++)
       {
           Price[i] = exp((-1)*Model.Get_r()*Model.Get_dt())*(qu * Price[i] + qm * Price[i+1] + qd * Price[i+2]);
       }
   }

   return Price[0];
}


double Call::Payoff(double z)
{
   if (z>K) return z-K;
   return 0.0;
}


double Put::Payoff(double z)
{
   if (z<K) return K-z;
   return 0.0;
}
