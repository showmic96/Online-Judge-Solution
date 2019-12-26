// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[16][(1<<16)+10];
vector<pair<int , int> > v;
int si;

int Set(int n , int pos)
{
    return n|(1<<pos);
}

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

ll f(int i , int mask)
{
    if(mask==(1<<si)-1){

        return max(abs(v[i].first-v[0].first), abs(v[i].second-v[0].second));
    }

    if(dp[i][mask]!=-1)return dp[i][mask];

    ll value = 1234567891011121314;
    bool check = false;

    for(int j=0;j<si;j++){

        if(Check(mask , j)==false){

            value = min(value , f(j , Set(mask , j))+ max(abs(v[i].first-v[j].first), abs(v[i].second-v[j].second)));
            check = true;
        }
    }

    if(check==false)value = 0;

    return dp[i][mask] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        v.clear();
        memset(dp , -1 , sizeof(dp));

        string ar[20];

        int n , m;
        scanf("%d %d",&n , &m);

        for(int i=0;i<n;i++)cin >> ar[i];

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(ar[i][j]=='x'){

                    v.push_back(make_pair(i , j));
                }
            }
        }

        for(int i=0;i<n;i++){

            for(int j=0;j<m;j++){

                if(ar[i][j]=='g'){

                    v.push_back(make_pair(i , j));
                }
            }
        }

        si = v.size();

        printf("Case %d: %lld\n", ++c , f(0 , Set(0,0)));
    }

    return 0;
}
