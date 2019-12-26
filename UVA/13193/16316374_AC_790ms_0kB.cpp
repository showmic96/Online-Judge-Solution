// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>getbit(ll x)
{
    vector<ll>temp;
    while(x){

        temp.push_back(x%2);
        x/=2;
    }

    while(temp.size()<32)temp.push_back(0);
    reverse(temp.begin() , temp.end());
    return temp;
}

ll get(vector<ll>v)
{
    ll now = 0;
    for(int i=0;i<5;i++){

        now*=2;
        now+=v[i];
    }
    return now;
}

int mp[33];

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        ll n;
        scanf("%lld",&n);
        vector<ll>v = getbit(n);

        for(int i=0;i<32;i++)mp[i] = 0;

        for(int i=0;i<38;i++){

            vector<ll>temp;

            for(int j=0;j<5;j++){

                temp.push_back(v[(i+j)%32]);
            }

            mp[get(temp)] = 1;
        }

        bool check = true;
        for(int i=0;i<32;i++)if(mp[i]==0)check = false;

        if(check==true)printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
