#include <iostream>
using namespace std;

class SectionB; 

class SectionA {
private:
    int marksA;
public:
    SectionA(int m) : marksA(m) {}
    friend float calculateAverage(SectionA, SectionB);
};

class SectionB {
private:
    int marksB;
public:
    SectionB(int m) : marksB(m) {}
    friend float calculateAverage(SectionA, SectionB);
};

float calculateAverage(SectionA a, SectionB b) {
    return (a.marksA + b.marksB) / 2.0;
}

int main() {
    int marksA, marksB;
    cout << "Enter marks for Section A: ";
    cin >> marksA;
    cout << "Enter marks for Section B: ";
    cin >> marksB;

    SectionA sectionA(marksA);
    SectionB sectionB(marksB);

    cout << "Average Marks: " << calculateAverage(sectionA, sectionB) << endl;

    return 0;
}
