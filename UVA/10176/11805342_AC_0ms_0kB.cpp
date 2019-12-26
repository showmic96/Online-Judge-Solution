// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 131071;

char ar[11000];

int main(void)
{
    ll ans = 0;
    while(scanf("%s",&ar)==1){

        int si = strlen(ar);
        
        if(ar[0]!='#'){
            ans*=2;
            ans+=ar[0]-'0';
            ans%=MOD;
        }

        for(int i=1;i<si-1;i++){

            ans*=2;
            ans+=ar[i]-'0';
            ans%=MOD;
        }

        if(ar[si-1]=='#'){
            if(ans==0)printf("YES\n");
            else printf("NO\n");
            ans = 0;
        }

        else{
            if(si==1)continue;
            ans*=2;
            ans+=ar[si-1]-'0';
            ans%=MOD;
        }

    }
    return 0;
}