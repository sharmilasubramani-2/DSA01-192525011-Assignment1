#include <climits>
#include <iostream>
#include <limits>

using namespace std;

int main() {
    bool peakHour = true;
    char zoneCode = 'O';

    int innerFarePaise = 1000;
    long long dailyTransactions = 3000000LL;

    unsigned int passengerCount = 500000U;

    float approximateFare = 36.5F;
    double measuredFare = 36.50;

    auto outerFarePaise = 3000;

    cout << boolalpha;

    cout << "Peak hour: " << peakHour << '\n';
    cout << "Zone code: " << zoneCode << '\n';

    cout << "Inner fare (paise): "
         << innerFarePaise << '\n';

    cout << "Daily transactions: "
         << dailyTransactions << '\n';

    cout << "Passenger count: "
         << passengerCount << '\n';

    cout << "Approximate fare: "
         << approximateFare << '\n';

    cout << "Measured fare: "
         << measuredFare << '\n';

    cout << "Auto-deduced fare: "
         << outerFarePaise << '\n';

    cout << "\n--- Data Type Sizes ---\n";

    cout << "sizeof(bool): "
         << sizeof(bool) << " byte(s)\n";

    cout << "sizeof(char): "
         << sizeof(char) << " byte(s)\n";

    cout << "sizeof(int): "
         << sizeof(int) << " byte(s)\n";

    cout << "sizeof(long long): "
         << sizeof(long long) << " byte(s)\n";

    cout << "sizeof(unsigned int): "
         << sizeof(unsigned int) << " byte(s)\n";

    cout << "sizeof(float): "
         << sizeof(float) << " byte(s)\n";

    cout << "sizeof(double): "
         << sizeof(double) << " byte(s)\n";

    cout << "\n--- Numeric Limits ---\n";

    cout << "INT_MIN: " << INT_MIN << '\n';
    cout << "INT_MAX: " << INT_MAX << '\n';

    cout << "LLONG_MIN: " << LLONG_MIN << '\n';
    cout << "LLONG_MAX: " << LLONG_MAX << '\n';

    cout << "UINT_MAX: " << UINT_MAX << '\n';

    cout << "\n--- Floating-Point Precision ---\n";

    cout << "float precision digits: "
         << numeric_limits<float>::digits10 << '\n';

    cout << "double precision digits: "
         << numeric_limits<double>::digits10 << '\n';

    cout << "\n--- Money Representation ---\n";

    long long farePaise = 3650;

    cout << "Fare: Rs. "
         << farePaise / 100 << "."
         << (farePaise % 100 < 10 ? "0" : "")
         << farePaise % 100 << '\n';

    return 0;
}