#ifndef TriModel01_h
#define TriModel01_h

class TriModel
{
    private:
        double S0;      /// initial stock price
        double sigma;   /// volatility
        double r;       /// continuously compounded interest rate
        double nu;      /// constant used in calculations
        double dt;      /// time interval
        double dx;      /// price change

    public:
        /// constructor to initialise data members
        TriModel(double S0_, double sigma_,double r_): S0(S0_), sigma(sigma_),r(r_)
        {
            nu = r-sigma*sigma/2;

            dt = 0.0;
            dx = 0.0;
        }

        /// member function to set values of dt and dx
        /// T maturity of the option, N number of time steps
        void Set_dtdx(double T, int N);

        /// calculate the risk neutral probability of going up
        double RiskNeutProb_up();

        /// calculate the risk neutral probability of going down
        double RiskNeutProb_down();

        /// calculate the stock price at time step n and node i
        double S(int n, int i);

        /// return the risk free interest rate R
        double Get_r() { return r;}

        /// return time interval dt
        double Get_dt() { return dt;}
};


#endif
