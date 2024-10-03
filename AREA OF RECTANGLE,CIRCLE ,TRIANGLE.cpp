#include <iostream>
#include <cmath>

using namespace std;

class Area {
public:
    double triangle(double base, double height) {
        return 0.5 * base * height;
    }

    double rectangle(double length, double breadth) {
        return length * breadth;
    }

    double circle(double radius) {
        return M_PI * radius * radius;
    }
};

int main() {
    Area area;

    double base_triangle, height_triangle;
    cout << "Enter base and height of the triangle: ";
    cin >> base_triangle >> height_triangle;
    double area_triangle = area.triangle(base_triangle, height_triangle);
    cout << "Area of triangle: " << area_triangle << endl;

    double length_rectangle, breadth_rectangle;
    cout << "Enter length and breadth of the rectangle: ";
    cin >> length_rectangle >> breadth_rectangle;
    double area_rectangle = area.rectangle(length_rectangle, breadth_rectangle);
    cout << "Area of rectangle: " << area_rectangle << endl;

    double radius_circle;
    cout << "Enter radius of the circle: ";
    cin >> radius_circle;
    double area_circle = area.circle(radius_circle);
    cout << "Area of circle: " << area_circle << endl;

    return 0;
}
