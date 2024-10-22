#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>scores(n);
    for(int i=0;i<n;i++){
        cin>>scores[i];
    }
    scores.erase(max_element(scores.begin(),scores.end()));
    scores.erase(min_element(scores.begin(),scores.end()));
    double sum;
    for(int i=0;i<n-2;i++){
        sum+=scores[i];
    }
    printf("%.2f",sum/(n-2));
    return 0;
}