// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){
        
        ll in;
        scanf("%lld",&in);
        in/=6;
        cout << sqrt(in) << endl;
    }
    return 0;
}