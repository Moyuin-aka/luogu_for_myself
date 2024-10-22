#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> ans(n);
    unordered_set<int> num;
    for (int i = 0; i < n; i++)
    {
        cin >> ans[i];
        num.insert(ans[i]);
    }
    int count = 0;
    unordered_set<int> result;
    for (int a = 0; a < ans.size(); ++a)
    {
        for (int b = 0; b < ans.size(); ++b)    
        {
            if (a != b)
            {
                int sum = ans[a] + ans[b];
                if (num.count(sum) && result.find(sum) == result.end())
                {
                    result.insert(sum);
                    count++;
                }
            }
        }
    }
    cout << count;
    return 0;
}
