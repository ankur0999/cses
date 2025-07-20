#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n; // Input the positive integer

    while (true) {
        cout << n; // Print the current value of n
        if (n == 1) break; // Stop if n becomes 1
        cout << " "; // Add a space between numbers
        if (n % 2 == 0) {
            n /= 2; // If n is even, divide it by 2
        } else {
            n = n * 3 + 1; // If n is odd, multiply by 3 and add 1
        }
    }

    return 0;
}
