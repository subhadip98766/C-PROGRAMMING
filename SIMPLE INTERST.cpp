#include <iostream>
using namespace std;


float calculateSimpleInterest(float principal, float time, float rate = 15.0) {
    return (principal * time * rate) / 100;
}

int main() {
    float principal, time, interest;

    cout << "Enter the principal amount: ";
    cin >> principal;
    cout << "Enter the time (in years): ";
    cin >> time;

    
    interest = calculateSimpleInterest(principal, time);

    
    cout << "Simple Interest at default rate of 15% is: " << interest << endl;

    return 0;
}

