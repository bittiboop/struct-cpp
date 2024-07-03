#include <iostream>
using namespace std;

struct Rectangle {
    int x;
    int y;
    int width;
    int height;
};
void moveRectangle(Rectangle& rect, int dX, int dY) {
    rect.x += dX;
    rect.y += dY;
}

void resizeRectangle(Rectangle& rect, int newWidth, int newHeight) {
    rect.width = newWidth;
    rect.height = newHeight;
}

void printRectangle(const Rectangle& rect) {
    cout << "Rectangle (x: " << rect.x << ", y: " << rect.y << ", width: " << rect.width << ", height: " << rect.height << ")" << endl;
}

int main() {
    Rectangle rect = { 10, 20, 30, 40 };

    cout << "Start rect. ";
    printRectangle(rect);

    moveRectangle(rect, 5, -10);
    cout << "After moving ";
    printRectangle(rect);

    resizeRectangle(rect, 50, 60);
    cout << "After resizing ";
    printRectangle(rect);

    return 0;
}
