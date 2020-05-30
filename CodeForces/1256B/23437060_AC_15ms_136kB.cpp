// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int>v(n);
        for(auto &x:v)cin >> x;
        int now = -1, pos = 0;
        while(pos<n-1){
            now = 2e9;
            int last = pos;
            for(int i=pos;i<n;i++){
                if(now>v[i]){
                    now = v[i];
                    pos = i;
                }
            }
            v.erase(v.begin()+pos);
            v.insert(v.begin()+last , now);
            if(last==pos)pos++;

        }
        for(auto it:v)cout << it << " ";
        cout << endl;
    }

    return 0;
}
