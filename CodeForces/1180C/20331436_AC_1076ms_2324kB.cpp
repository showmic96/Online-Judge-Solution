// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<int , int> ans[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , q;
    cin >> n >> q;
    deque<int>dq;
    for(int i=0;i<n;i++){
        int in;
        cin >> in;
        dq.push_back(in);
    }
    for(int i=1;i<=n-1;i++){
        int t1 = dq.front();
        dq.pop_front();
        int t2 = dq.front();
        dq.pop_front();
        ans[i] = {t1 , t2};
        if(t1>t2)swap(t1 , t2);
        dq.push_back(t1);
        dq.push_front(t2);
    }
    vector<int>v;
    int first = dq.front();
    dq.pop_front();
    for(int i=1;i<n;i++){
        v.push_back(dq.front());
        dq.pop_front();
    }
    while(q--){
        ll in;
        cin >> in;
        if(in<=n-1)cout << ans[in].first << " " << ans[in].second << endl;
        else{
            ll temp = in-n;
            ll mod = n-1;
            cout << first << " " << v[temp%mod] << endl;
        }
    }

    return 0;
}
