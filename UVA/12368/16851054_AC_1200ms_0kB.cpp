// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
ll ans;
vector<int>store , v[1025];
ll value[1025];

int Set(int n , int pos)
{
    return n|(1<<pos);
}

bool digit_check(ll x , ll y)
{
    bool taken[10];
    memset(taken , false ,sizeof(taken));
    while(x){

        taken[x%10] = true;
        x/=10;
    }

    while(y){

        if(taken[y%10]==true)return false;
        taken[y%10] = true;
        y/=10;
    }

    return true;
}


void f(int i , int mask , vector<int>temp)
{
    if(i==10){

        vector<int>vv;

        for(int i1=0;i1<temp.size();i1++){

            vv.push_back(temp[i1]);
            for(int j1=0;j1<temp.size();j1++){

                if(i1==j1)continue;
                if(temp[i1]==0)continue;
                vv.push_back(temp[i1]*10+temp[j1]);

            }
        }

        sort(vv.begin() , vv.end());

        for(int i1=0;i1<vv.size();i1++)v[mask].push_back(vv[i1]);

        for(int i1=0;i1<vv.size();i1++){

            for(int j1=0;j1<vv.size();j1++){

                if(vv[i1]+vv[j1]<=100&&digit_check(vv[i1] , vv[j1])==true){

                    v[mask].push_back(vv[i1]+vv[j1]);
                }
            }
        }

        sort(v[mask].begin() , v[mask].end());

        reverse(temp.begin() , temp.end());
        ll now = 0;
        for(int i1=0;i1<temp.size();i1++){

            now*=10;
            now+=temp[i1];
        }

        value[mask] = now;

        return ;
    }

    f(i+1 , mask , temp);

    temp.push_back(i);
    f(i+1 , Set(mask , i) , temp);
}

int main(void)
{
    int c = 0;
    vector<int>t;
    f(0 , 0 , t);

    while(scanf("%d",&n)==1){

        if(n==0)break;

        ans = 1e18;

        store.clear();

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            store.push_back(in);
        }

        for(int i=0;i<1024;i++){

            bool check = true;

            for(int j=0;j<n;j++){

                if(binary_search(v[i].begin() , v[i].end() , store[j])==false){

                    check = false;
                    break;
                }
            }
            if(check==true)ans = min(ans , (ll)value[i]);
        }

        printf("Case %d: %lld\n",++c , ans);
    }

    return 0;
}
