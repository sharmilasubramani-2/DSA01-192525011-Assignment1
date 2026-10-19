#include <iostream>
#include <string>

using namespace std;

enum class Zone {
    Inner,
    Middle,
    Outer
};

class SmartCard {
private:
    long long balancePaise;

public:
    SmartCard(long long initialBalance)
        : balancePaise(initialBalance) {}

    long long getBalance() const {
        return balancePaise;
    }

    bool canTravel(long long farePaise) const {
        return farePaise >= 0 &&
               balancePaise - farePaise >= 5000;
    }

    bool deductFare(long long farePaise) {
        if (!canTravel(farePaise)) {
            return false;
        }

        balancePaise -= farePaise;
        return true;
    }
};

class FareCalculator {
public:
    static long long calculateFare(Zone zone, bool peak) {
        long long farePaise = 0;

        switch (zone) {
            case Zone::Inner:
                farePaise = 1000;
                break;

            case Zone::Middle:
                farePaise = 2000;
                break;

            case Zone::Outer:
                farePaise = 3000;
                break;
        }

        if (peak) {
            farePaise += farePaise * 20 / 100;
        }

        return farePaise;
    }
};

int main() {
    SmartCard card(10000);

    struct Trip {
        Zone zone;
        bool peak;
        string name;
    };

    Trip trips[] = {
        {Zone::Inner, false, "Inner"},
        {Zone::Outer, true, "Outer"},
        {Zone::Middle, false, "Middle"}
    };

    for (const Trip& trip : trips) {
        long long fare =
            FareCalculator::calculateFare(trip.zone, trip.peak);

        cout << trip.name << " Zone: ";

        if (card.deductFare(fare)) {
            cout << "Fare Rs. " << fare / 100 << "."
                 << (fare % 100 < 10 ? "0" : "")
                 << fare % 100;
        } else {
            cout << "Journey denied";
        }

        cout << ", Balance Rs. "
             << card.getBalance() / 100 << "."
             << (card.getBalance() % 100 < 10 ? "0" : "")
             << card.getBalance() % 100 << '\n';
    }

    return 0;
}
