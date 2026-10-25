#include <iostream>

int main()
{
int x = 5, y = 3;

std::cout << x + y * 2 << ' '
          << (x + y) * 2 << '\n';

int z = x++ + ++y;
std::cout << z << ' ' << x << ' ' << y << '\n';

std::cout << (x > y ? x : y) << ' '
          << x % 4 * 2 << '\n';

std::cout << 10 / 3 << ' '
          << 10 % 3 << ' '
          << -10 / 3 << ' '
          << -10 % 3 << '\n';

int k = 0;

for (int i = 0; i < 10; i += 3)
{
    k += i;
}

std::cout << k << '\n';

int hour = 18;
int baseFarePaise = 3000;
int farePaise = baseFarePaise;

bool peak = (hour >= 8 && hour < 10) ||
            (hour >= 17 && hour < 20);

farePaise += peak ? farePaise * 20 / 100 : 0;

std::cout << "Peak hour: "
          << (peak ? "Yes" : "No") << '\n';

std::cout << "Final fare: Rs."
          << farePaise / 100 << '.';

if (farePaise % 100 < 10)
    std::cout << '0';

std::cout << farePaise % 100 << '\n';

return 0;

}
