#include <iostream>
#include <cmath>
using namespace std;

class Cone {
protected:
    double x, y;    
    double radius;  
    double height;  

public:
    Cone() {
        x = 0;
        y = 0;
        radius = 1;
        height = 1;
    }

    Cone(double r, double h) {
        x = 0;
        y = 0;
        radius = r;
        height = h;
    }

    Cone(double x, double y, double r, double h) {
        this->x = x;
        this->y = y;
        this->radius = r;
        this->height = h;
    }

    
    double surfaceArea() {
        double slantHeight = sqrt(radius * radius + height * height);
        return 3.14 * radius * (radius + slantHeight);
    }

   
    double volume() {
        return (1 / 3) * 3.14 * radius * radius * height;
    }

    friend istream& operator>>(istream& in, Cone& cone) {
        in >> cone.x >> cone.y >> cone.radius >> cone.height;
        return in;
    }

    friend ostream& operator<<(ostream& out, Cone& cone) {
        out << "Центр: (" << cone.x << ", " << cone.y << "), Радиус: " << cone.radius << ", Высота: " << cone.height;
        return out;
    }
};

class Frustum : public Cone {
private:
    double topRadius;

public:
    Frustum() {
        x = 0;
        y = 0;
        radius = 1;
        topRadius = 1;
        height = 1;
    }

    Frustum(double x, double y, double r1, double r2, double h) {
        this->x = x;
        this->y = y;
        this->radius = r1;
        this->topRadius = r2;
        this->height = h;
    }

    double surfaceArea()  {
        double slantHeight = sqrt((radius - topRadius) * (radius - topRadius) + height * height);
        return 3.14 * (radius + topRadius) * slantHeight + 3.14 * (radius * radius + topRadius * topRadius);
    }

    double volume() {
        return (1.0 / 3.0) * 3.14 * height * (radius * radius + topRadius * topRadius + radius * topRadius);
    }

    friend istream& operator>>(istream& in, Frustum& frustum) {
        in >> frustum.x >> frustum.y >> frustum.radius >> frustum.topRadius >> frustum.height;
        return in;
    }

    friend ostream& operator<<(ostream& out,  Frustum& frustum) {
        out << "Центр: (" << frustum.x << ", " << frustum.y << "), Нижний радиус: " << frustum.radius
            << ", Верхний радиус: " << frustum.topRadius << ", Высота: " << frustum.height;
        return out;
    }

    
    bool operator==( Frustum& other)  {
        return x == other.x && y == other.y && radius == other.radius && topRadius == other.topRadius && height == other.height;
    }

    bool operator!=( Frustum& other) {
        return !(*this == other);
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    Frustum frustum1;
    Frustum frustum2(1, 2, 4, 5, 6);

    Cone cone1;
    Cone cone2(3, 4);
    Cone cone3(1, 2, 5, 6);

    cout << "Конус 1: " << cone1 << std::endl;
    cout << "Площадь поверхности: " << cone1.surfaceArea() << ", Объем: " << cone1.volume() << endl;

    cout << "Конус 2: " << cone2 << std::endl;
    cout << "Площадь поверхности: " << cone2.surfaceArea() << ", Объем: " << cone2.volume() << endl;

    cout << "Конус 3: " << cone3 << std::endl;
    cout << "Площадь поверхности: " << cone3.surfaceArea() << ", Объем: " << cone3.volume() << endl;
 
    cout << "Усеченный конус 1: " << frustum1 << endl;
    cout << "Площадь поверхности: " << frustum1.surfaceArea() << ", Объем: " << frustum1.volume() << endl;

    cout << "Усеченный конус 1: " << frustum2 << endl;
    cout << "Площадь поверхности: " << frustum2.surfaceArea() << ", Объем: " << frustum2.volume() << endl;

    
    if (frustum1 == frustum2) {
        cout << "Усеченный конус 1 равно усеченному конусу 2" << endl;
    }
    else {
        cout << "Усеченный конус 1 не равен усеченному конусу 2" << endl;
    }

    return 0;
}


