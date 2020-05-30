// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string n;
int m , dp[105][100005];

int f(int i , int mod)
{
    if(i==n.size()){
        if(mod==0)return 0;
        return 1e7;
    }
    if(dp[i][mod]!=-1)return dp[i][mod];
    int value = f(i+1 , (mod*10+n[i]-'0')%m);
    for(int j=0+(i==0);j<10;j++){
        value = min(value , f(i+1 , (mod*10+j)%m)+1);
    }
    return dp[i][mod] = value;
}

int main(void)
{
    cin >> n >> m;
    bool done = false;
    string temp = "";
    for(int i=0;i<n.size();i++){
        if(n[i]>'0')done = true;
        if(n[i]=='0'&&done==false)continue;
        temp+=n[i];
    }
    n = temp;
    memset(dp , -1 , sizeof(dp));
    int ans = f(0 , 0);
    int now = 0 , mod = 0;
    bool zero = true;
    for(int i=0;i<n.size();i++){
        bool done = false;
        for(int j=(0+zero);j<10;j++){
            if(n[i]-'0'==j){
                if(now+f(i+1 , (mod*10+n[i]-'0')%m)==ans){
                    cout << n[i];
                    mod = mod*10+n[i]-'0';
                    mod%=m;
                    break;
                }
            }
            else if(now+1+f(i+1 , (mod*10+j)%m)==ans){
                cout << j;
                mod = mod*10+j;
                mod%=m;
                now++;
                done = true;
                break;
            }
        }
        zero = false;
    }
    cout << endl;
    return 0;
}