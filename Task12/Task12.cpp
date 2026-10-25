#include <iostream>
#include <iomanip>
using namespace std;

constexpr long long MIN_BALANCE = 5000;

enum class Zone
{
    Inner = 1,
    Middle,
    Outer,
    Airport
};

class SmartCard
{
private:
    long long balancePaise;
    bool hasMonthlyPass;
    Zone passZone1;
    Zone passZone2;

public:
    SmartCard(long long balance, bool monthlyPass,
              Zone zone1, Zone zone2)
    {
        balancePaise = balance;
        hasMonthlyPass = monthlyPass;
        passZone1 = zone1;
        passZone2 = zone2;
    }

    long long getBalance()
    {
        return balancePaise;
    }

    bool isCoveredByPass(Zone zone)
    {
        return hasMonthlyPass &&
               (zone == passZone1 || zone == passZone2);
    }

    bool canTravel(long long fare)
    {
        return fare >= 0 &&
               balancePaise - fare >= MIN_BALANCE;
    }

    bool deductFare(long long fare)
    {
        if (canTravel(fare))
        {
            balancePaise -= fare;
            return true;
        }

        return false;
    }
};

long long calculateFare(Zone zone, bool peak, bool weekend)
{
    long long fare;

    switch (zone)
    {
        case Zone::Inner:
            fare = 1000;
            break;

        case Zone::Middle:
            fare = 2000;
            break;

        case Zone::Outer:
            fare = 3000;
            break;

        case Zone::Airport:
            fare = 6000;
            break;

        default:
            return -1;
    }

    if (weekend)
    {
        fare = fare * 90 / 100;
    }
    else if (peak)
    {
        fare = fare * 120 / 100;
    }

    return fare;
}

string zoneName(Zone zone)
{
    switch (zone)
    {
        case Zone::Inner: return "Inner";
        case Zone::Middle: return "Middle";
        case Zone::Outer: return "Outer";
        case Zone::Airport: return "Airport";
        default: return "Invalid";
    }
}

int main()
{
    SmartCard card(20000, true, Zone::Inner, Zone::Middle);

    cout << "ADVANCED METRO SMART-CARD SYSTEM\n\n";
    cout << fixed << setprecision(2);

    cout << "Initial balance: Rs. "
         << static_cast<double>(card.getBalance()) / 100 << "\n\n";

    Zone selectedZone = Zone::Airport;
    bool peak = true;
    bool weekend = false;

    cout << "Selected zone: " << zoneName(selectedZone) << '\n';

    long long fare = calculateFare(selectedZone, peak, weekend);

    cout << "Airport base fare: Rs. 60.00\n";
    cout << "Peak hour: Yes\n";
    cout << "Weekend: No\n";
    cout << "Calculated fare: Rs. "
         << static_cast<double>(fare) / 100 << '\n';

    if (card.isCoveredByPass(selectedZone))
    {
        cout << "Monthly pass covers this journey. No fare deducted.\n";
    }
    else if (card.deductFare(fare))
    {
        cout << "Journey approved.\n";
    }
    else
    {
        cout << "Journey denied: minimum balance rule.\n";
    }

    cout << "Remaining balance: Rs. "
         << static_cast<double>(card.getBalance()) / 100 << "\n\n";

    cout << "WEEKEND DISCOUNT TEST\n";
    long long weekendFare = calculateFare(Zone::Airport, true, true);

    cout << "Airport weekend fare: Rs. "
         << static_cast<double>(weekendFare) / 100 << '\n';
    cout << "Weekend discount and peak surcharge are not combined.\n\n";

    cout << "MONTHLY PASS TEST\n";
    cout << "Inner zone covered: "
         << (card.isCoveredByPass(Zone::Inner) ? "Yes" : "No") << '\n';
    cout << "Middle zone covered: "
         << (card.isCoveredByPass(Zone::Middle) ? "Yes" : "No") << '\n';
    cout << "Outer zone covered: "
         << (card.isCoveredByPass(Zone::Outer) ? "Yes" : "No") << '\n';

    return 0;
}