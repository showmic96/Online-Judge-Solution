// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int dp[123][123456];
int ar[123];
int n , v;
string mx;

int f(int i , int value , string s)
{
    if(i==n){

        if(value==v)mx = s;
        return 1;
    }

    int temp = 0;
    string st = to_string(ar[i]);
    if(dp[i][value]!=-1)return dp[i][value];

    if(value+ar[i]<32000)temp = f(i+1 , value+ar[i] , s+"+"+st);
    
    if(value-ar[i]>-32000)temp = f(i+1 , value-ar[i] , s+"-"+st);
    
    if(value*ar[i]<32000&&value*ar[i]>-32000)temp = f(i+1 , value*ar[i] , s+"*"+st);
    
    if(value%ar[i]==0&&value!=0)temp = f(i+1 , value/ar[i] , s+"/"+st);

    return dp[i][value] = v;
}

int main(void)
{
    int t;
    cin >> t;

    while(t--){

        memset(dp , -1 , sizeof(dp));
        cin >> n;
        for(int i=0;i<n;i++)cin >> ar[i];
        cin >> v;
        mx = "NO EXPRESSION";
        f(1 , ar[0] , to_string(ar[0]));

        if(mx!="NO EXPRESSION")cout << mx << "=" << v <<  endl;
        else cout << mx << endl;
    }

    return 0;
}
