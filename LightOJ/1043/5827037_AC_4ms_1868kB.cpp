#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long a;
    cin >> a;
    for(long long b=0;b<a;b++){
        double ac , bc , ab , ra;
        cin >> ab >> ac >> bc >> ra;
        double s = (ab+ac+bc)*0.5;
        double area = sqrt(s*(s-ab)*(s-bc)*(s-ac));
        double areat = area * ra/(ra+1);
        double x = (areat * areat)/(s*(s-ac)*(s-bc)*(s-ab));
        double y =pow(x,(0.25));
        printf("Case %lld: %f\n",b+1,y*ab);


    }
    return 0;
}