#include <iostream>
#include <iomanip>
using namespace std;

constexpr long long MIN_BALANCE = 5000;

enum class Zone
{
    Inner = 1,
    Middle,
    Outer
};

class SmartCard
{
private:
    long long balancePaise;

public:
    SmartCard(long long balance)
    {
        balancePaise = balance;
    }

    long long getBalance()
    {
        return balancePaise;
    }

    bool canTravel(long long fare)
    {
        return fare >= 0 && balancePaise - fare >= MIN_BALANCE;
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

long long calculateFare(Zone zone, bool peak)
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

        default:
            return -1;
    }

    if (peak)
    {
        fare = fare * 120 / 100;
    }

    return fare;
}

int main()
{
    SmartCard card(10000);

    cout << "METRO SMART-CARD - FINAL DESIGN\n\n";

    cout << "Initial balance: Rs. "
         << fixed << setprecision(2)
         << static_cast<double>(card.getBalance()) / 100 << '\n';

    Zone zone = Zone::Outer;
    bool peak = true;

    long long fare = calculateFare(zone, peak);

    cout << "Selected zone: Outer\n";
    cout << "Peak hour: Yes\n";
    cout << "Calculated fare: Rs. "
         << static_cast<double>(fare) / 100 << '\n';

    if (card.deductFare(fare))
    {
        cout << "Journey approved\n";
    }
    else
    {
        cout << "Journey denied: minimum balance rule\n";
    }

    cout << "Remaining balance: Rs. "
         << static_cast<double>(card.getBalance()) / 100 << '\n';

    cout << "\nDESIGN RECOMMENDATIONS\n";
    cout << "1. Store money as integer paise.\n";
    cout << "2. Use enum class for metro zones.\n";
    cout << "3. Keep card balance private.\n";
    cout << "4. Use constants for fare rules.\n";
    cout << "5. Validate all user inputs.\n";
    cout << "6. Use configuration files for future fare revisions.\n";

    return 0;
}