// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX =  205;
int dp[MAX][MAX][2*MAX];
string s , t;

int f(int i , int j , int tot)
{
    //cout << i << " " << j << " " << tot << endl;
    if(tot<0||tot>=2*MAX-10)return 1e7;
    if(i==s.size()&&j==t.size()){
        return tot;
    }
    if(dp[i][j][tot]!=-1)return dp[i][j][tot];
    int value = 1e7;
    if(i==s.size()){
        value = min(value , f(i , j+(t[j]=='(') , tot+1) + 1);
        value = min(value , f(i , j+(t[j]==')') , tot-1) + 1);
    }
    else if(j==t.size()){
        value = min(value , f(i+(s[i]=='(') , j , tot+1) + 1);
        value = min(value , f(i+(s[i]==')') , j , tot-1) + 1);
    }
    else {
        value = min(value , f(i+(s[i]=='(') , j+(t[j]=='(') , tot+1)+1);
        value = min(value , f(i+(s[i]==')') , j+(t[j]==')') , tot-1)+1);
    }
    return dp[i][j][tot] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> s >> t;
    memset(dp , -1 , sizeof(dp));
    int ans = f(0 , 0 , 0) , l = 0 , r = 0 , now = 0 , tot = 0;
    while(true){
        if(l==s.size()&&r==t.size())break;
        if(l==s.size()){
            int tt = (t[r]=='(');
            if(now+1+f(l, r+tt , tot+1)==ans){
                cout << '(';
                now++;
                r+=tt;
                tot++;
            }
            else{
                tt^=1;
                cout << ')';
                now++;
                r+=tt;
                tot--;
            }
        }
        else if(r==t.size()){
            int tt = (s[l]=='(');
            if(now+1+f(l+tt, r , tot+1)==ans){
                cout << '(';
                now++;
                l+=tt;
                tot++;
            }
            else{
                tt^=1;
                cout << ')';
                now++;
                l+=tt;
                tot--;
            }
        }
        else{
            int t1 = 0 , t2 = 0;
            if(s[l]=='(')t1++;
            if(t[r]=='(')t2++;
            if(now+1+f(l+t1 , r+t2 , tot+1)==ans){
                now++;
                cout << '(';
                l+=t1;
                r+=t2;
                tot++;
            }
            else{
                t1^=1;
                t2^=1;
                now++;
                cout << ')';
                l+=t1;
                r+=t2;
                tot--;
            }
        }
    }
    for(int i=0;i<tot;i++)cout << ')';
    cout << endl;
    return 0;
}
