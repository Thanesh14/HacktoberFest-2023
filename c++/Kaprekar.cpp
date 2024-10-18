// C++ program to check if a number is a Kaprekar number for a specific base.
#include <iostream>
#include <cmath>
using namespace std;

bool isKaprekar(int number, int base) {
    if (number < 0 || base <= 1) {
        return false;
    }

    long long squared = static_cast<long long>(number) * number;
    long long divisor = 1;

    // Determine the divisor for splitting
    while (squared / divisor >= base) {
        divisor *= base;
    }

    // Check different splits of the squared number
    while (divisor > 0) {
        long long left = squared / divisor;
        long long right = squared % divisor;

        // Check if the sum of left and right parts equals the original number
        if (left + right == number && right > 0) {
            return true;
        }
        divisor /= base;  // Move to the next split
    }
    return false;
}

int main() {
    int number, base;

    cout << "Enter a number: ";
    cin >> number;
    cout << "Enter the base: ";
    cin >> base;

    if (isKaprekar(number, base)) {
        cout << number << " is a Kaprekar number in base " << base << endl;
    } else {
        cout << number << " is not a Kaprekar number in base " << base << endl;
    }

    return 0;
}
