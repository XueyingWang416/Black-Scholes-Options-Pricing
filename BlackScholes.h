//
// Created by Xueying Wang on 11/21/21.
//

#ifndef BLACK_SCHOLES_OPTIONS_PRICING_BLACKSCHOLES_H
#define BLACK_SCHOLES_OPTIONS_PRICING_BLACKSCHOLES_H


class BlackScholes {
public:
    BlackScholes();

    /**
     * Conditional probability, a gain for the call buyer occurs on two fwo factors occurring at maturity:
     * 1. The spot has to be above strike CallPrice. (Direction)
     * 2. The difference between spot and strike prices at maturity. (Momentum)
     * @param assetPrice the underlying asset CallPrice
     * @param strikePrice the strike CallPrice
     * @param rate risk-free rate
     * @param maturity time to maturity (in years)
     * @param volatility volatility of the underlying asset
     * @return d1 value in double
     */
    double D1(double assetPrice, double strikePrice, double rate, double maturity, double volatility);
    // probability that the option will expire in the money, i.e., spot above strike for a call.
    double D2(double d1, double volatility, double maturity);
    BlackScholes(double strikePrice, double assetPrice, double rate, double maturity, double volatility);
    double CDF(double x);
    double CallPrice(double assetPrice, double strikePrice, double rate, double maturity, double d1, double d2);
    double PutPrice(double assetPrice, double strikePrice, double rate, double maturity, double d1, double d2, double callPrice);

private:
    double strikePrice;
    double assetPrice;
    double rate; // risk-free rate
    double maturity; // time to maturity
    double volatility;
};


#endif //BLACK_SCHOLES_OPTIONS_PRICING_BLACKSCHOLES_H
