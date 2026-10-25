#include <iostream>
using namespace std;

// Procedural approach
long long calculateFare(int zone, bool peak)
{
long long fare = 0;

if (zone == 1)
    fare = 1000;
else if (zone == 2)
    fare = 2000;
else if (zone == 3)
    fare = 3000;

if (peak)
    fare += fare * 20 / 100;

return fare;

}

// Object-oriented approach
class SmartCard
{
private:
long long balance;

public:
SmartCard(long long initialBalance)
{
balance = initialBalance;
}

bool canTravel(long long fare)
{
    return fare >= 0 && balance - fare >= 5000;
}

bool deductFare(long long fare)
{
    if (!canTravel(fare))
        return false;

    balance -= fare;
    return true;
}

long long getBalance()
{
    return balance;
}

};

int main()
{
cout << "PROCEDURAL APPROACH\n";

long long fare1 = calculateFare(3, true);

cout << "Outer peak fare: Rs. "
     << fare1 / 100 << '\n';

cout << "\nOBJECT-ORIENTED APPROACH\n";

SmartCard card(10000);

long long fare2 = calculateFare(1, false);

if (card.deductFare(fare2))
    cout << "Journey approved\n";
else
    cout << "Journey denied\n";

cout << "Fare: Rs. " << fare2 / 100 << '\n';
cout << "Remaining balance: Rs. "
     << card.getBalance() / 100 << '\n';

long long expensiveFare = calculateFare(3, true);

if (card.deductFare(expensiveFare))
    cout << "Second journey approved\n";
else
    cout << "Second journey denied\n";

cout << "Final balance: Rs. "
     << card.getBalance() / 100 << '\n';

return 0;

}