#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long a ,b , c , d , e , f;
    cin >> a;
    for(b=0;b<a;b++){
        e=0;
        cin >> c >> d;
        for(;c<=d;c++){
            if(c%2!=0) e+=c;
        }
        printf("Case %lld: %lld\n",b+1,e);
    }

    return 0;
}
