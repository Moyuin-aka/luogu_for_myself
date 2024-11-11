#include <iostream>
using namespace std;
int main()
{
    int t, a, b;
    cin >> t >> a >> b;
    int m = a - b;
    int n = a + b;
    if (m >= 0)
    {
        cout << m << " ";
    
    if (n <= t && n != m)
    {
        cout << n;
    }
    }
    else
    {
        if (n <= t)
        {
            cout << n;
        }
        else
        {
            cout << "No solution";
        }
    }
    return 0;
}