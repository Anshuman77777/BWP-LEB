#include <iostream>
#include <cmath>
using namespace std;

void DDA(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = max(abs(dx), abs(dy));
    float x_inc = dx / (float)steps;
    float y_inc = dy / (float)steps;
    float x = x1;
    float y = y1;

    cout << "Coordinates using DDA algorithm:\n";
    for (int i = 0; i <= steps; i++) {
        cout << "(" << round(x) << ", " << round(y) << ")\n";
        x += x_inc;
        y += y_inc;
    }
}
void bresenham_low_slope(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int x = x1, y = y1;
    int p = 2 * abs(dy) - abs(dx);

    int x_inc = (dx > 0) ? 1 : -1;
    int y_inc = (dy > 0) ? 1 : -1;

    cout << "Bresenham Line (|slope| ≤ 1):\n";
    for (int i = 0; i <= abs(dx); i++) {
        cout << "(" << x << ", " << y << ")\n";
        x += x_inc;
        if (p >= 0) {
            y += y_inc;
            p += 2 * (abs(dy) - abs(dx));
        } else {
            p += 2 * abs(dy);
        }
    }
}
void bresenham_high_slope(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int x = x1, y = y1;
    int p = 2 * abs(dx) - abs(dy);

    int x_inc = (dx > 0) ? 1 : -1;
    int y_inc = (dy > 0) ? 1 : -1;

    cout << "Bresenham Line (|slope| > 1):\n";
    for (int i = 0; i <= abs(dy); i++) {
        cout << "(" << x << ", " << y << ")\n";
        y += y_inc;
        if (p >= 0) {
            x += x_inc;
            p += 2 * (abs(dx) - abs(dy));
        } else {
            p += 2 * abs(dx);
        }
    }
}

int main() {
    int x1, y1, x2, y2;
    cout << "Enter the starting point (x1 y1): ";
    cin >> x1 >> y1;
    cout << "Enter the ending point (x2 y2): ";
    cin >> x2 >> y2;
    DDA(x1, y1, x2, y2);
    bresenham_low_slope(x1,y1,x2,y2);
    bresenham_high_slope(x1,y1,x2,y2);
    return 0;
}
