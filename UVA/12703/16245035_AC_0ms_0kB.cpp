// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll fib[50];

int main(void)
{
    fib[1] = 1;
    fib[2] = 1;

    for(int i=3;i<=44;i++)fib[i] = fib[i-1] + fib[i-2];

    int t;
    bool check = false;

    scanf("%d",&t);

    while(t--){

        ll n , a , b;
        scanf("%lld %lld %lld",&n , &a , &b);

        vector<ll>v;
        map<ll, ll>mp;

        for(int i=2;i*i<=a;i++){

            if(a%i==0){

                ll counter = 0;

                while(a%i==0){

                    counter++;
                    a/=i;
                }

                v.push_back(i);
                mp[i]+=counter;
            }
        }

        if(a>1){

            v.push_back(a);
            mp[a]++;
        }

        map<ll , ll>ans;

        for(int i=0;i<v.size();i++){

            ans[v[i]] = mp[v[i]]*fib[n-1];
        }

        mp.clear();
        v.clear();

        for(int i=2;i*i<=b;i++){

            if(b%i==0){

                ll counter = 0;

                while(b%i==0){

                    counter++;
                    b/=i;
                }

                v.push_back(i);
                mp[i]+=counter;
            }
        }

        if(b>1){

            v.push_back(b);
            mp[b]++;
        }

        for(int i=0;i<v.size();i++){

            ans[v[i]] += mp[v[i]]*fib[n];
        }

        for(auto it = ans.begin();it!=ans.end();it++){

            printf("%lld %lld\n",it->first , it->second);
        }
        printf("\n");
    }
    return 0;
}
