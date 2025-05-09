#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll T;
    cin >> T;
    while (T--) {
        ll m;
        cin >> m;
        vector<ll> num;

        // 找到最大的2的幂次不超过m
        ll lower = (m == 0) ? 0 : 1LL << (63 - __builtin_clzll(m));
        num.push_back(lower);
        ll sum = lower;

        while (sum != m) {
            ll exponent = __builtin_ctzll(lower) - 1;
            ll new_num = (exponent >= 0) ? (1LL << exponent) : 0;
            lower = new_num;

            if (sum + new_num > m) {
                continue;
            }

            sum += new_num;
            num.push_back(new_num);
        }

        // 调整序列长度使其为2的幂次
        while ((num.size() & (num.size() - 1)) != 0) {
            sort(num.begin(), num.end()); // 升序排序，找最小的可拆分元素
            auto it = find_if(num.begin(), num.end(), [](ll x) { return x > 1; });
            if (it == num.end()) break;

            ll val = *it;
            num.erase(it);
            num.insert(it, val / 2);
            num.insert(it, val / 2);
        }

        // 排序以得到最小字典序
        sort(num.begin(), num.end());
        for (size_t i = 0; i < num.size(); ++i) {
            cout << num[i];
            if (i != num.size() - 1) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}