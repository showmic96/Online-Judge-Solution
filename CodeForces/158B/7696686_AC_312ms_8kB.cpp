// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a = 0 , b=0 , c=0 , d=0 , t=0 , in;
    cin >> t;

    while(t--){

        cin >> in;
        if(in==4)d++;
        if(in==3)c++;
        if(in==2)b++;
        if(in==1)a++;

    }

    int ans = d;

    if(b%2==0)ans+=b/2;
    else{
        ans+=b/2 + 1;
        a-=2;
    }

    ans+=c;
    a-=c;
    if(a>0){

        if(a%4==0)ans+=a/4;
        else ans+=(a/4 + 1);
    }

    cout << ans << endl;

    return 0;
}
