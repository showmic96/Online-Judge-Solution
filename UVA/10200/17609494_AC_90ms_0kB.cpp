// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>ans;

bool prime(ll x)
{
    if(x==1)return 0;
    if(x==2)return true;
    if(x%2==0)return false;

    for(ll i=3;i*i<=x;i+=2){

        if(x%i==0)return false;
    }
    return true;
}

int main(void)
{
    for(ll i=0;i<=10000;i++){

        if(prime(i*i+i+41)==true)ans.emplace_back(i);
    }
    int a , b;
    while(scanf("%d %d",&a , &b)==2){

        int counter = upper_bound(ans.begin() , ans.end() , b) - lower_bound(ans.begin() , ans.end() , a);
        double t1 = counter;
        double t2 = (b-a)+1;

        printf("%.2f\n",0.0000001+100.00*t1/t2);
    }

    return 0;
}
