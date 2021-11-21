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


