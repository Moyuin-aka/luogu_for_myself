#include <iostream>
using namespace std;
bool prime(int i)
{
    if (i <= 2)
    {
        return true;
    }
    for (int j = 2; j < i; j++)
    {
        if (i % j == 0)
        {
            return false;
        }
        return true;
    }
}
int main()
{
    long long n;
    cin >> n;
    for (long long i = 2; i < n; i++)
    {
        if (prime(i))
        {
            if (n % i == 0)
            {
                if(prime(n/i)){
                    cout<<(n/i>i?n/i:i);
                    return 0;
                }
            }
        }
    }
    return 0;
}