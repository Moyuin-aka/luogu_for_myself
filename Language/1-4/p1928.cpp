#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<cctype>

using namespace std;

string solve(const string &s, int &pos) {
    string res = "";
    while (pos < (int)s.size() && s[pos] != ']') {
        if (s[pos] == '[') {
            // Format is [D X] : after '[' comes digits D, then the inner expression X, then ']'
            ++pos; // skip '['
            int times = 0;
            while (pos < (int)s.size() && isdigit((unsigned char)s[pos])) {
                times = times * 10 + (s[pos] - '0');
                ++pos;
            }
            // Decode inner substring until the matching ']'
            string inner = solve(s, pos); // returns with s[pos] == ']' or pos==size
            if (pos < (int)s.size() && s[pos] == ']') ++pos; // skip ']'
            for (int t = 0; t < times; ++t) res += inner;
        } else { 
            // Normal character (letter) just append
            res += s[pos++];
        }
    }
    return res;
}

int main(){
    string s;
    cin>>s;
    int pos=0;
    
    cout<<solve(s,pos)<<"\n";
    return 0;

}