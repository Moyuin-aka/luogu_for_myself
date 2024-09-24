#include<iostream>
using namespace std;
int main(){
    float e,charge;
    cin>>e;
    if(e<=150){
        charge=e*0.4463;
    }
    else if(e>=151&&e<=400){
        charge=(e-150)*0.4663+150*0.4463;
    }
    else{
        charge=(e-400)*0.5663+150*0.4463+250*0.4663;
    }
    printf("%.1f",charge);
    return 0;
}