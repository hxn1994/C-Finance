#include "TriModel01.h"
#include <cmath>
#include <iostream>

void TriModel::Set_dtdx(double T, int N)
{
    dt = T / N;
    dx = sigma * sqrt(2*dt);
}

double TriModel::RiskNeutProb_up()
{
    return 0.5*(pow(sigma,2)*dt + pow(nu,2)*pow(dt,2) + (nu*dt*dx))/pow(dx,2);
}

double TriModel::RiskNeutProb_down()
{
    return 0.5*(pow(sigma,2)*dt + pow(nu,2)*pow(dt,2) - (nu*dt*dx))/pow(dx,2);
}

double TriModel::S(int n,int i)
{
    double prod = dx * i;
    return S0*exp(prod);
}
