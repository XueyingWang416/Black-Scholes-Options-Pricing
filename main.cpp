#include <iostream>
#include "BlackScholes.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
    BlackScholes blackScholes;
    cout << "Please enter the asset price:" << endl;
    double assetPrice;
    cin >> assetPrice;
    cout << "Please enter the strike price:" << endl;
    double strikePrice;
    cin >> strikePrice;
    cout << "Please enter risk-free rate:" << endl;
    double rate;
    cin >> rate;
    cout << "Please enter the time to maturity in years:" << endl;
    double maturity;
    cin >> maturity;
    cout << "Please enter the volatility of the stock:" << endl;
    double volatility;
    cin >> volatility;
    cout << "If it is a call option, enter 0, else enter 1:" << endl;
    bool flag;
    cin >> flag;

    double d1 = blackScholes.D1(assetPrice, strikePrice, rate, maturity, volatility);
    double d2 = blackScholes.D2(d1, volatility, maturity);

    double callPrice = blackScholes.CallPrice(assetPrice, strikePrice, rate, maturity, d1, d2);
    double putPrice = blackScholes.PutPrice(assetPrice, strikePrice, rate, maturity, d1, d2, callPrice);

    if (flag)
        cout << "The price of put option is:/t" << putPrice << endl;
    else
        cout << "The price of call option is:/t" << callPrice << endl;
}
