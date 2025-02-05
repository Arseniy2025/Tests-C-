#include <iostream>
#include <cmath>
using namespace std;

class Distance {
private:
    int kilometers;
    int meters;

public:
    Distance(int km, int m) {
       this->kilometers = km;
       this->meters = m;
       this->kilometers += meters / 1000;
       this->meters %= 1000;
    }

    Distance() { 
        this->kilometers = 0;
        this->meters = 0;
    }

    Distance operator+(Distance other) {
        return Distance(kilometers + other.kilometers, meters + other.meters);
    }

    Distance operator-(Distance other) {
        return Distance(kilometers - other.kilometers, meters - other.meters);
    }

    Distance operator*(int factor) {
        int totalMeters = kilometers * 1000 + meters;
        totalMeters *= factor;
        return Distance(totalMeters / 1000, totalMeters % 1000);
    }

    Distance operator/(int divisor) {
        int totalMeters = kilometers * 1000 + meters;
        return Distance(totalMeters / divisor / 1000, (totalMeters / divisor) % 1000);
    }


    friend ostream& operator<<(ostream& os, Distance& d) {
        os << d.kilometers << " km " << d.meters << " m";
        return os;

    }
    bool operator==(const Distance& other) {
        return kilometers == other.kilometers && meters == other.meters;
    }

    bool operator!=(const Distance& other) {
        return !(*this == other);
    }

};

int main() {
    Distance d1(1, 1500);
    Distance d2(2, 700);

    Distance d3 = d1 + d2;
    cout << "d1 + d2: " << d3 << endl;

    Distance d4 = d2 - d1;
    cout << "d2 - d1: " << d4 << endl;

    Distance d5 = d1 * 2;
    cout << "d1 * 2: " << d5 << endl;

    Distance d6 = d2 / 2;
    cout << "d2 / 2: " << d6 << endl;

    cout << "d1 == d2: " << (d1 == d2) << endl;
    cout << "d1 != d2: " << (d1 != d2) << endl;

    return 0;
}
