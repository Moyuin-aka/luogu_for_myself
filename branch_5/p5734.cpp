#include <bits/stdc++.h>
//STL好！！
using namespace std;
int main()
{
    int q;
    cin >> q;
    string deal;
    string original;
    cin >> original;
    for (int i = 0; i < q; i++)
    {
        char a;
        cin >> a;
        switch (a)
        {
        case ('1'):
            cin >> deal;
            //original = original + deal;
            cout << original.append(deal) << endl;
            break;
        case ('2'):
            int begin, end;
            cin >> begin >> end;
            original=original.substr(begin,end);
            cout<<original<<endl;
            break;
        case('3'):
                int point;
                cin >> point;
                cin >> deal;
                original.insert(point,deal);
                cout<<original<<endl;
            break;
        case('4'):
                cin>>deal;
                if(original.find(deal)<original.length())
                cout<<original.find(deal)<<endl;
                else
                cout<<-1<<endl;
            break; 
        }
    }
    return 0;
}