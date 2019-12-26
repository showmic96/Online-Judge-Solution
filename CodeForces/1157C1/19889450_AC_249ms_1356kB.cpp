// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio();
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    deque<int>dq;
    for(int i=0;i<n;i++){
        int in;
        cin >> in;
        dq.push_back(in);
    }
    string ans = "";
    int cur = 0;
    for(int i=0;i<n;i++){
        if(cur<dq.front()&&cur<dq.back()){
            if(dq.front()<dq.back()){
                ans+="L";
                cur = dq.front();
                dq.pop_front();
            }
            else{
                ans+="R";
                cur = dq.back();
                dq.pop_back();
            }
        }
        else if(cur<dq.front()){
            cur = dq.front();
            ans+="L";
            dq.pop_front();
        }
        else if(cur<dq.back()){
            cur = dq.back();
            ans+="R";
            dq.pop_back();
        }
        else break;
    }
    cout << ans.size() << endl << ans << endl;
    return 0;
}
