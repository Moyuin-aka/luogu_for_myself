#include<iostream>
#include<string>
using namespace std;

int main() {
    int T;
    string S;
    cin >> T >> S;
    
    int rounds = 0;
    size_t pos;
    
    while ((pos = S.find("not")) != string::npos) {
        while ((pos = S.find("not")) != string::npos) {
            S.erase(pos, 3);
        }
        rounds++;
    }

    cout << S << endl;
    cout << rounds << endl;
    
    return 0;
}
