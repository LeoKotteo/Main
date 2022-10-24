#include "binpow.h"

#include <iostream>
using namespace std;

int main() {
    int base, mod;
    int64_t power;
    cin >> base >> power >> mod;
    cout << PowerBinary(base, power, mod) << endl;
    return 0;
}
