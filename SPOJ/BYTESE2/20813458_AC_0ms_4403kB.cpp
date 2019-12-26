// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1000 + 9;
int ar[MAX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n , c = 1;
        cin >> n;
        map<int , int>mp;
        set<int>st;
        vector<pair<int , int> > v;
        memset(ar , 0 , sizeof(ar));
        for(int i=0;i<n;i++){
            int in1 , in2;
            cin >> in1 >> in2;
            st.insert(in1);
            st.insert(in2);
            v.push_back(make_pair(in1 , in2));
        }
        for(set<int>::iterator it = st.begin();it!=st.end();it++){
            mp[*it] = c;
            c++;
        }
        for(int i=0;i<v.size();i++){
            ar[mp[v[i].first]]++;
            ar[mp[v[i].second]+1]--;
        }
        int mx = 0;
        for(int i=1;i<=c;i++){
            ar[i]+=ar[i-1];
            mx = max(mx , ar[i]);
        }
        cout << mx << endl;
    }

    return 0;
}
