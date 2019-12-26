// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[11][2][90][90];
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

ll f(int i , int smaller , int mod , int sum)
{

    if(i==n){
        //cout << n << " " << mod << endl;
        if(mod==0&&sum==0)return 1;
        return 0;
    }

    if(dp[i][smaller][mod][sum]!=-1)return dp[i][smaller][mod][sum];

    int lim;

    if(smaller==1){

        lim = 9;
    }

    else lim = v[i];

    ll value = 0;

    for(int j=0;j<=lim;j++){

        if(j==lim){

            value+=f(i+1 , smaller , ((mod*10)+j)%k , (sum+j)%k);
        }
        else{

            value+=f(i+1 , 1 , ((mod*10)+j)%k , (sum+j)%k);
        }
    }

    return dp[i][smaller][mod][sum] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        memset(dp , -1 , sizeof(dp));

        scanf("%lld %lld %lld",&a , &b , &k);

        v = make(a-1);
        n = v.size();

        ll ans1 , ans2;

        if(k<90)ans1 = f(0 , 0 , 0 , 0);
        else ans1 = 0;

        memset(dp , -1 , sizeof(dp));

        v = make(b);
        n = v.size();

        if(k<90)ans2 = f(0 , 0 , 0, 0);
        else ans2 = 0;

        printf("Case %d: %lld\n",++c , ans2-ans1);
    }

    return 0;
}
