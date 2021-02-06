#include <iostream>
#include <math.h>

using namespace std;

int pth(int x, int y) {
    return sqrt(pow(x, 2) + pow(y, 2));
}

int main() {

    int r = 10;

    const int length = r;
    const int width = r;

    for (int y = length; y >= -length; y--) {
        for (int x = -width; x <= width; x++) {

            if (pth(x, y) >= r) cout << "**";
            else cout << "  ";

        }
        cout << "\n";
    }
    cin.get();

    return 0;
}