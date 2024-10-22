#include <iostream>
using namespace std;
long long judge(long long n){
    long long reversed=0;
    while (n > 0)
        {
            reversed = reversed * 10 + n % 10;
            n /= 10;
        }
        return reversed;
}
int main()
{
    long long n;
    cin >> n;
    long long reversed = 0;
    if (n < 0)
    {
        n =-n;
        reversed-=judge(n);
    }
    else
    {
        reversed=judge(n);
    }
    cout << reversed;
}