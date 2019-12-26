// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v;

int main(void)
{
    int n;
    scanf("%d",&n);

    ll sum = 0 , odd = 0 , even = 0;

    for(int i=0;i<n;i++){

        ll in;
        scanf("%lld",&in);
        v.push_back(in);
        sum+=in;
        
        if(in%2==1)odd++;
        else even++;
    }
    
    if(odd==0)cout << "Second" << endl;
    else cout << "First" << endl;
    

    return 0;
}