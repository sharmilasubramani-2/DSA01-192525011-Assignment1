#include <iomanip>
#include <iostream>
using namespace std;

enum class Zone { Inner, Middle, Outer };

long long calculateFare(Zone zone, int hour)
{
long long fare = 0;

switch (zone)
{
    case Zone::Inner:  fare = 1000; break;
    case Zone::Middle: fare = 2000; break;
    case Zone::Outer:  fare = 3000; break;
}

bool peak = (hour >= 8 && hour < 10) ||
            (hour >= 17 && hour < 20);

if (peak)
    fare += fare * 20 / 100;

return fare;

}

bool canTravel(long long balance, long long fare)
{
return balance - fare >= 5000;
}

void testCase(const char* name, Zone zone, int hour,
long long balance, long long expectedFare)
{
long long fare = calculateFare(zone, hour);
bool approved = canTravel(balance, fare);

cout << name << '\n';
cout << "Fare: Rs. " << fare / 100 << '.'
     << setw(2) << setfill('0') << fare % 100
     << setfill(' ') << '\n';

cout << "Expected fare: Rs. " << expectedFare / 100
     << '\n';

cout << "Travel: " << (approved ? "Approved" : "Denied")
     << '\n';

cout << "Test: "
     << (fare == expectedFare ? "PASS" : "FAIL")
     << "\n\n";

}

int main()
{
cout << "METRO FARE TESTING\n\n";

testCase("1. Inner off-peak", Zone::Inner, 12, 10000, 1000);
testCase("2. Middle off-peak", Zone::Middle, 12, 10000, 2000);
testCase("3. Outer off-peak", Zone::Outer, 12, 10000, 3000);

testCase("4. Inner at 8 AM", Zone::Inner, 8, 10000, 1200);
testCase("5. Inner at 10 AM", Zone::Inner, 10, 10000, 1000);
testCase("6. Inner at 5 PM", Zone::Inner, 17, 10000, 1200);
testCase("7. Inner at 8 PM", Zone::Inner, 20, 10000, 1000);

testCase("8. Outer peak", Zone::Outer, 18, 10000, 3600);

cout << "9. Minimum balance boundary\n";
cout << "Fare Rs. 10, balance Rs. 60: "
     << (canTravel(6000, 1000) ? "Approved" : "Denied")
     << '\n';

cout << "10. Insufficient balance\n";
cout << "Fare Rs. 10, balance Rs. 59: "
     << (canTravel(5900, 1000) ? "Approved" : "Denied")
     << '\n';

return 0;

}