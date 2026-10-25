#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main()
{
int zone;
int hour;
long long balance;

cout << "METRO SMART-CARD SYSTEM\n";

cout << "Enter zone (1=Inner, 2=Middle, 3=Outer): ";

if (!(cin >> zone) || zone < 1 || zone > 3)
{
    cout << "Invalid zone input\n";
    return 1;
}

cout << "Enter hour (0-23): ";

if (!(cin >> hour) || hour < 0 || hour > 23)
{
    cout << "Invalid hour input\n";
    return 1;
}

cout << "Enter balance in rupees: ";

if (!(cin >> balance) || balance < 0)
{
    cout << "Invalid balance input\n";
    return 1;
}

long long farePaise;

if (zone == 1)
    farePaise = 1000;
else if (zone == 2)
    farePaise = 2000;
else
    farePaise = 3000;

bool peak = (hour >= 8 && hour < 10) ||
            (hour >= 17 && hour < 20);

if (peak)
    farePaise += farePaise * 20 / 100;

long long balancePaise = balance * 100;

cout << fixed << setprecision(2);

cout << "Peak hour: " << (peak ? "Yes" : "No") << '\n';

cout << "Fare: Rs. "
     << static_cast<double>(farePaise) / 100 << '\n';

if (balancePaise - farePaise >= 5000)
{
    balancePaise -= farePaise;

    cout << "Journey approved\n";
}
else
{
    cout << "Journey denied (minimum balance rule)\n";
}

cout << "Remaining balance: Rs. "
     << static_cast<double>(balancePaise) / 100 << '\n';

return 0;

}
