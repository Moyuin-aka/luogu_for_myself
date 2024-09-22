#include<iostream>
#include<math.h>
int main(){
    float a,b,c;
    double p,s,cen;
    scanf("%f %f %f",&a,&b,&c);
    p=(a+b+c)*0.5;
    cen=(p-a)*(p-b)*(p-c);
    s=sqrt(p*cen);
    printf("%.1f",s);
    return 0;

}