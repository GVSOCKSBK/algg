#include <iostream>
using namespace std;

int main() {
    int a = 0;
    int b = 1;
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++) {
        cout <<a<<"\t";
        int c = a+b;
        a = b;
        b = c;
    }
    return 0;
}