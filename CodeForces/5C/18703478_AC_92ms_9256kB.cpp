// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1e6+9;
int dp[MAX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string ar;
    cin >> ar;
    memset(dp , -1 , sizeof(dp));
    stack<int>st;int ans = 0 , cnt = 1;
    for(int i=0;i<ar.size();i++){
        if(ar[i]=='(')st.push(i);
        else{
            if(st.empty()){
                continue;
            }
            int temp = st.top();;
            st.pop();
            dp[i] = temp;
            if(i>0&&dp[temp-1]>=0)dp[i] = dp[temp-1];
            if(i-dp[i]+1>ans)ans = i-dp[i]+1 , cnt = 1;
            else if(i-dp[i]+1==ans)cnt++;
        }
    }
    cout << ans << " " << cnt << endl;
    return 0;
}
