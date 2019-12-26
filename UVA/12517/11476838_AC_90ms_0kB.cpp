// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[11][2][190];
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

ll f(int i , int smaller , int sum)
{

    if(i==n){

        return sum;
    }

    if(dp[i][smaller][sum]!=-1)return dp[i][smaller][sum];

    int lim;

    if(smaller==1){

        lim = 9;
    }

    else lim = v[i];

    ll value = 0;

    for(int j=0;j<=lim;j++){

        if(j==lim){

            value+=f(i+1 , smaller , (sum+j));
        }
        else{

            value+=f(i+1 , 1 , (sum+j));
        }
    }

    return dp[i][smaller][sum] = value;
}

int main(void)
{

    while(scanf("%lld %lld",&a , &b)==2){

        if(a==0&&b==0)break;

        memset(dp , -1 , sizeof(dp));

        v = make(a-1);
        n = v.size();

        ll ans1 , ans2;

        ans1 = f(0 , 0 , 0);

        memset(dp , -1 , sizeof(dp));

        v = make(b);
        n = v.size();

        ans2 = f(0 , 0 , 0);

        printf("%lld\n" , ans2-ans1);
    }

    return 0;
}
