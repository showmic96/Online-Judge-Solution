// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>v;
ll dp[32][2][2][32];
int n;

vector<int> bin(ll x)
{
    v.clear();
    vector<int>temp;

    while(x!=0){

        temp.push_back(x%2);
        x/=2;
    }

    reverse(temp.begin() , temp.end());

    return temp;
}

ll f(int i , int smaller , int pre , int counter)
{
    if(i==n){

        return counter;
    }

    if(dp[i][smaller][pre][counter]!=-1)return dp[i][smaller][pre][counter];

    ll value = 0;

    int lim;

    if(smaller==1)lim = 1;
    else lim = v[i];

    for(int j=0;j<=lim;j++){

        if(j==lim){

            if(j==1&&pre==1)value+=f(i+1 , smaller , 1 , counter+1);
            else if(j==1)value+=f(i+1 , smaller , 1 , counter);
            else value+=f(i+1 , smaller , 0 , counter);
        }

        else{

            if(j==1&&pre==1)value+=f(i+1 , 1 , 1 , counter+1);
            else if(j==1)value+=f(i+1 , 1 , 1 , counter);
            else value+=f(i+1 , 1 , 0 , counter);
        }
    }

    return dp[i][smaller][pre][counter] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        ll in;
        scanf("%lld",&in);
        v = bin(in);

        n = v.size();

        memset(dp , -1 , sizeof(dp));

        printf("Case %d: %lld\n", ++c , f(0 , 0 , 0 , 0));
    }
    return 0;
}
