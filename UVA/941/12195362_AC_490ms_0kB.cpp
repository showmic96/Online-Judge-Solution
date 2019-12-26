// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char ar[28];
ll n;
ll fact[33] , fre[26];

void pre()
{
    fact[0] = 1;

    for(ll i=1;i<33;i++){

        fact[i] = fact[i-1]*i;
    }
}

ll per(ll l)
{
    ll temp = fact[l];

    for(int i=0;i<26;i++){

        temp/=fact[fre[i]];
    }

    return temp;
}

int main(void)
{
    pre();
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        scanf("%s %lld",&ar , &n);
        n++;
        memset(fre , 0 , sizeof(fre));

        for(int i=0;i<strlen(ar);i++){

            fre[ar[i]-'a']++;
        }

        ll ans = per(strlen(ar));

        int l = strlen(ar);

        while(l>0){


            ll temp = 0 , now = 0;
            bool check = false;

            for(int i=0;i<26;i++){

                if(fre[i]==0)continue;

                fre[i]--;
                now = per(l-1);

                if(temp+now>=n){

                    n-=temp;
                    printf("%c",'a'+i);
                    l--;
                    check = true;
                    break;
                }

                else{

                    temp+=now;
                    fre[i]++;
                }
            }

            if(check==false)break;
        }

        printf("\n");

    }

    return 0;
}
