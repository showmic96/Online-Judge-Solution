// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll dp[14][2][2][14];
vector<int>v;
void make(ll x)
{
    v.clear();
    while(x){
        v.push_back(x%10);
        x/=10;
    }
    if(v.size()==0)v.push_back(0);
    reverse(v.begin() , v.end());
}
ll f(int i , int smaller , int zero , int tot)
{
    if(i==v.size()){
        return tot;
    }
    if(dp[i][smaller][zero][tot]!=-1)return dp[i][smaller][zero][tot];
    ll value = 0;
    int lim = v[i];
    if(smaller)lim = 9;
    for(int j=0;j<=lim;j++){
        if(j<lim){
            if(j==0){
                if(zero==1)value+=f(i+1 , 1 , 1 , tot+1);
                else value+=f(i+1 , 1 , 0 , tot);
            }
            else{
                value+=f(i+1 , 1 , 1 , tot+1);
            }
        }
        else{
            if(j==0){
                if(zero==1)value+=f(i+1, smaller, 1 , tot+1);
                else value+=f(i+1, smaller , 0 , tot);
            }
            else{
                value+=f(i+1 , smaller , 1 , tot+1);
            }
        }
    }
    return dp[i][smaller][zero][tot] = value;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    ll k;
    cin >> k;
    ll hi = k , low = 0 , mid , t = 100 , ans = -1;
    while(t--){
        mid = (hi+low)/2;
        make(mid);
        memset(dp , -1 , sizeof(dp));
        ll temp = f(0 , 0 , 0 , 0);
        if(temp<k){
            ans = mid;
            low = mid+1;
        }
        else{
            hi = mid-1;
        }
    }
    make(ans);
    memset(dp , -1 , sizeof(dp));
    ll temp = f(0 , 0 , 0 , 0);
    ans++;
    make(ans);
    for(int i=0;i<v.size();i++){
        temp++;
        if(temp==k){
            cout << v[i] << endl;
            break;
        }
    }
    return 0;
}
