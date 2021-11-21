//
// Created by Xueying Wang on 11/21/21.
//

#include <cmath>
#include "BlackScholes.h"

BlackScholes::BlackScholes() {} // default constructor

// Complete constructor.
BlackScholes::BlackScholes(double strikePrice, double assetPrice, double rate, double maturity, double volatility)
        : strikePrice(strikePrice), assetPrice(assetPrice), rate(rate), maturity(maturity), volatility(volatility) {}

double BlackScholes::D1(double assetPrice, double strikePrice, double rate, double maturity, double volatility) {
    double numerator = log(assetPrice / strikePrice) + (rate + pow(volatility, 2.0) / 2) * maturity;
    double denominator = volatility * sqrt(maturity);
    return numerator / denominator;
}

double BlackScholes::D2(double d1, double volatility, double maturity) {
    return d1 - volatility * sqrt(maturity);
}

double BlackScholes::CDF(double x) {
    const double b1 =  0.319381530;
    const double b2 = -0.356563782;
    const double b3 =  1.781477937;
    const double b4 = -1.821255978;
    const double b5 =  1.330274429;
    const double p  =  0.2316419;
    const double c2  =  0.39894228;

    double a = fabs(x);
    double t = 1.0 / (1.0 + a * p);
    double b = c2 * exp((-x) * (x / 2.0));
    double cdf = ((((b5 * t + b4) * t + b3) * t + b2) * t + b1) * t;
    cdf = 1 - b * cdf;
    if (x < 0)
        cdf = 1 - cdf;
    return cdf;
}

double BlackScholes::CallPrice(double assetPrice, double strikePrice, double rate, double maturity, double d1, double d2) {
    return assetPrice * CDF(d1) - strikePrice * exp(- rate * maturity) * CDF(d2);
}

double
BlackScholes::PutPrice(double assetPrice, double strikePrice, double rate, double maturity, double d1, double d2, double callPrice) {
    return strikePrice * exp(- rate * maturity) - assetPrice + callPrice;
}


