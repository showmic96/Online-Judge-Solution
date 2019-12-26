// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[11][2][2][2];
ll a , b , k , n;
vector<int>v;

vector<int> make(ll value)
{
    v.clear();

    vector<int>temp;

    while(value!=0){

        temp.push_back(value%10);
        value/=10;
    }

    if(temp.empty()==true)temp.push_back(0);

    reverse(temp.begin() , temp.end());

    return temp;
}

ll f(int i , int smaller , int mod , int zero)
{

    if(i==n){
        if(mod==0&&zero==1)return 1;
        return 0;
    }

    if(dp[i][smaller][mod][zero]!=-1)return dp[i][smaller][mod][zero];

    int lim;

    if(smaller==1){

        lim = 9;
    }

    else lim = v[i];

    ll value = 0;

    for(int j=0;j<=lim;j++){

        if(j==lim){

            if(j!=0){
                if(zero==0)value+=f(i+1 , smaller , j%2 , 1);
                else value+=f(i+1 , smaller , (mod*j)%2 , 1);
            }
            else{
                if(zero==0)value+=f(i+1 , smaller , j , zero);
                else value+=f(i+1, smaller , (mod*j)%2 , zero);
            }
        }
        else{

            if(j!=0){
                if(zero==0)value+=f(i+1 , 1 , j%2 , 1);
                else value+=f(i+1 , 1 , (mod*j)%2 , 1);
            }
            else{

                if(zero==0)value+=f(i+1 , 1 , j , zero);
                else value+=f(i+1 , 1 , (mod*j)%2 , zero);
            }
        }
    }

    return dp[i][smaller][mod][zero] = value;
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%lld %lld",&a , &b);

        memset(dp , -1 , sizeof(dp));

        v = make(a-1);
        n = v.size();

        ll ans1 , ans2;

        ans1 = f(0 , 0 , 0 , 0);

        memset(dp , -1 , sizeof(dp));

        v = make(b);
        n = v.size();

        ans2 = f(0 , 0 , 0 , 0);

        printf("%lld\n",ans2-ans1);
    }

    return 0;
}
