#include <iostream>
#include <string>

#define LEGACY_PEAK_PERCENT 20

constexpr int PEAK_SURCHARGE_PERCENT = 20;
constexpr long long MIN_BALANCE_PAISE = 5000;

enum LegacyZone {
    LEGACY_INNER,
    LEGACY_MIDDLE,
    LEGACY_OUTER
};

enum class Zone {
    Inner,
    Middle,
    Outer
};

long long getBaseFare(Zone zone) {
    switch (zone) {
        case Zone::Inner:
            return 1000;

        case Zone::Middle:
            return 2000;

        case Zone::Outer:
            return 3000;
    }

    return 0;
}

int main() {
    const std::string projectName = "Metro Smart-Card System";

    Zone selectedZone = Zone::Outer;
    auto baseFarePaise = getBaseFare(selectedZone);

    long long peakFarePaise =
        baseFarePaise +
        baseFarePaise * PEAK_SURCHARGE_PERCENT / 100;

    LegacyZone oldZone = LEGACY_OUTER;

    std::cout << "Project: " << projectName << '\n';

    std::cout << "Base fare: Rs. "
              << baseFarePaise / 100 << '\n';

    std::cout << "Peak fare: Rs. "
              << peakFarePaise / 100 << '\n';

    std::cout << "Minimum balance: Rs. "
              << MIN_BALANCE_PAISE / 100 << '\n';

    std::cout << "Macro peak percentage: "
              << LEGACY_PEAK_PERCENT << "%\n";

    std::cout << "constexpr peak percentage: "
              << PEAK_SURCHARGE_PERCENT << "%\n";

    std::cout << "Legacy enum value: "
              << oldZone << '\n';

    std::cout << "Fare constants match: "
              << std::boolalpha
              << (LEGACY_PEAK_PERCENT ==
                  PEAK_SURCHARGE_PERCENT)
              << '\n';

    return 0;
}