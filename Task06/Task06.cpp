#include <iomanip>
#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };

constexpr int BASE_PAISE[] = {1000, 2000, 3000};
constexpr long long MIN_BALANCE_PAISE = 5000;

long long fare(Zone zone, bool peak)
{
long long base = 0;

switch (zone)
{
    case Zone::Inner:
        base = BASE_PAISE[0];
        break;

    case Zone::Middle:
        base = BASE_PAISE[1];
        break;

    case Zone::Outer:
        base = BASE_PAISE[2];
        break;
}

if (peak)
{
    base += base * 20 / 100;
}

return base;

}

bool canTravel(long long balance, long long tripFare)
{
return balance - tripFare >= MIN_BALANCE_PAISE;
}

int main()
{
long long balance = 10000;

struct Trip
{
    Zone zone;
    bool peak;
};

Trip trips[] = {
    {Zone::Inner, false},
    {Zone::Outer, true},
    {Zone::Middle, false}
};

for (const Trip& trip : trips)
{
    long long tripFare = fare(trip.zone, trip.peak);

    if (canTravel(balance, tripFare))
    {
        balance -= tripFare;

        std::cout << "Fare Rs. "
                  << tripFare / 100 << '.'
                  << std::setw(2) << std::setfill('0')
                  << tripFare % 100
                  << std::setfill(' ');
    }
    else
    {
        std::cout << "Journey denied (low balance)";
    }

    std::cout << " | Balance Rs. "
              << balance / 100 << '.'
              << std::setw(2) << std::setfill('0')
              << balance % 100 << std::setfill(' ')
              << '\n';
}

return 0;

}
