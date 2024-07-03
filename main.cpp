#include <iostream>
#include <cmath>
using namespace std;

struct Point {
    double x;
    double y;
};

double calculateDistance(const Point& p1, const Point& p2) {
    double dX = p1.x - p2.x;
    double dY = p1.y - p2.y;
    return sqrt(dX * dX + dY * dY);
}

int main() {
    Point point1 = { 3.0, 4.0 };
    Point point2 = { 7.0, 1.0 };

    double distance = calculateDistance(point1, point2);

    cout << "Distance between points (" << point1.x << ", " << point1.y << ") ³ (" << point2.x << ", " << point2.y << ") is " << distance << endl;

    return 0;
}

