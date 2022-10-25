#include "cyclic.h"

#include <iostream>
using namespace std;

int main() {
    int n, shift;
    string left;
    cin >> n >> shift >> left;
    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    CyclicShift(a, n, shift, left == "left");

    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    delete[] a;
    return 0;
}
