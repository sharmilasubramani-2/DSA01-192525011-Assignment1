#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main()
{
const long long farePaise = 3000;
const long long journeys[] = {20000, 500000, 3000000};

cout << "METRO FARE PRECISION ANALYSIS\n\n";

cout << "Fare per journey: Rs. "
     << fixed << setprecision(2)
     << static_cast<double>(farePaise) / 100 << '\n';

cout << "\nInteger type limits:\n";
cout << "int maximum: " << numeric_limits<int>::max() << '\n';
cout << "long long maximum: "
     << numeric_limits<long long>::max() << '\n';

cout << "\nFare collection analysis:\n";

for (long long count : journeys)
{
    long long totalPaise = count * farePaise;

    cout << "Journeys: " << count << '\n';
    cout << "Total fare: Rs. "
         << static_cast<double>(totalPaise) / 100 << '\n';

    double floatingTotal =
        static_cast<double>(count) * 30.00;

    cout << "Double total: Rs. " << floatingTotal << '\n';
    cout << "Integer paise total: Rs. "
         << static_cast<double>(totalPaise) / 100 << "\n\n";
}

cout << "int can store 3 million journeys: "
     << (3000000 <= numeric_limits<int>::max()
             ? "Yes" : "No")
     << '\n';

cout << "long long is suitable for large fare totals.\n";

return 0;

}