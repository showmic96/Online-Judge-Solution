// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

set<int>st[26];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string ar;
    cin >> ar;
    for(int i=0;i<ar.size();i++){
        st[ar[i]-'a'].insert(i+1);
    }
    int n;
    cin >> n;
    while(n--){
        int in1 , in2 , in3;
        cin >> in1 >> in2;
        if(in1==1){
            for(int i=0;i<26;i++){
                if(st[i].find(in2)!=st[i].end()){
                    st[i].erase(in2);
                }
            }
            char x;
            cin >> x;
            st[x-'a'].insert(in2);
        }
        else{
            cin >> in3;
            int ans = 0;
            for(int i=0;i<26;i++){
                int val = *st[i].upper_bound(in2-1);
                if(val>=in2&&val<=in3)ans++;
            }
            cout << ans << endl;
        }
    }

    return 0;
}
