#include <iostream>
using namespace std;
bool prime(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
bool palindrome(int n)
{
    int original = n, reversed = 0;
    while (n>0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed==original;
    
}
int main()
{
    int a, b;
    cin >> a >> b;
    if (a % 2 == 0)
        a += 1;
    if (b > 9999999)
        b = 9999999;
    for (int i = a; i <= b; i += 2)
    {
        if (palindrome(i))
        {
            if (prime(i))
            {
                printf("%d\n", i);
            }
        }
    }
    return 0;
}