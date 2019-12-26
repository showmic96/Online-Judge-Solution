// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio();
    cin.tie(0);cout.tie(0);

    int n , now = 0;
    string ar , ans;
    cin >> n >> ar;
    ans = ar;
    stack<int> st;
    for(int i=0;i<n;i++){
        if(ar[i]=='('){
            now++;
            st.push(i);
        }
        else{
            if(now%2==0)ans[i] = '0' , ans[st.top()] = '0';
            else ans[i] = '1' , ans[st.top()] = '1';
            now--;
            st.pop();
        }
    }
    cout << ans << endl;
    return 0;
}
