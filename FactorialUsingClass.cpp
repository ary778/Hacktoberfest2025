#include <iostream>
using namespace std;
class FactorialCalculator {
private:
    int number;
public:
    FactorialCalculator(int n) {
        number = n;
    }
    // Method to calculate factorial
    long long calculate() {
        if (number < 0) {
            cout << "Factorial not defined for negative numbers" << endl;
            return -1;
        }
        long long result = 1;
        for (int i = 1; i <= number; i++) {
            result *= i;
        }
        return result;
    }
};
int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    FactorialCalculator calculator(num);
    long long fact = calculator.calculate();
    if (fact != -1)
        cout << "Factorial of " << num << " is " << fact << endl;

    return 0;
}
