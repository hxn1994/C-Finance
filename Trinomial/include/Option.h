#ifndef OPTION_H
#define OPTION_H

#include "../TriModel01.h"

class EurOption
{
   private:
      int N; //steps to expiry
   public:
      void SetN(int N_){N=N_;}
      //Payoff defined to return 0.0
      //for pedagogical purposes.
      //To use a pure virtual function replace by
      //virtual double Payoff(double z)=0;
      virtual double Payoff(double z){return 0.0;}
      //pricing European option
      double PriceByTrinomial(TriModel Model, double T);
};

class Call: public EurOption
{
   private:
      double K; //strike price
   public:
      Call(double K_,int N_)
      {   EurOption::SetN(N_);
          SetK(K_); }
      void SetK(double K_){ K = K_; }
      double Payoff(double z);
};

class Put: public EurOption
{
   private:
      double K; //strike price
   public:
       Put(double K_,int N_)
       {  EurOption::SetN(N_);
           SetK(K_); }
      void SetK(double K_){ K = K_; }
      double Payoff(double z);
};


#endif // OPTION_H
