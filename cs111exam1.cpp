/* What's the output of the following code at each position */
/* What's the output of the following code at each position */
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x = 4, y = 4, z = 11, w = 7;
    string a = "x", b = "y", c = "a";

    cout << a << c << x << z << endl;                           // line (a)
    cout << a << "a" << "x" << a << endl;                       // line (b)
    if (x == y) cout << "x" << "==" << y << endl;               // line (c)
    if ((x == y) || (a == b)) cout << x << "==" << "y" << endl; // line (d)
    while (x <= w) {x++; cout << x;} cout << endl;              // line (e)
}

