#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int arr[3] = {a, b, c};
    sort(arr, arr + 3);
    cout << arr[0] << ' ' << arr[1] << ' ' << arr[2] << endl;
    return 0;
}
