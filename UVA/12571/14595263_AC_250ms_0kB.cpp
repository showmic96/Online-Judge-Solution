#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll get(ll x)
{
    vector<int>temp;

    while(x){

        temp.push_back(x%2);
        x/=2;
    }

    while(temp.size()<9)temp.push_back(0);

    reverse(temp.begin() , temp.end());

    ll now = 0;

    for(int i=0;i<9;i++){

        now*=2;
        now+=temp[i];
    }
    return now;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n , m;
        scanf("%d %d",&n , &m);

        vector<int>v;
        map<int ,int>mp;

        for(int i=0;i<n;i++){

            ll in;
            scanf("%lld",&in);

            ll temp = get(in);

            if(mp.find(temp)==mp.end()){

                mp[temp] = 1;
                v.push_back(temp);
            }
        }

        while(m--){

            int in;
            scanf("%d",&in);
            int mx = 0;

            for(int i=0;i<v.size();i++){

                mx = max(mx , (int)(in&v[i]));
            }

            printf("%d\n",mx);
        }
    }
    return 0;
}
