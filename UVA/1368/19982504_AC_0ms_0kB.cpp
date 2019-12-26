// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string ar[1005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n , m;
        cin >> n >> m;
        string ans = "";
        int tot = 0;
        for(int i=0;i<n;i++)cin >> ar[i];
        for(int j=0;j<m;j++){
            set<char>st;
            int fr[26];
            memset(fr , 0 , sizeof(fr));
            for(int i=0;i<n;i++){
                st.insert(ar[i][j]);
                fr[ar[i][j]-'A']++;
            }
            char x;
            int mx = 0;
            for(auto it:st){
                if(fr[it-'A']>mx){
                    mx = fr[it-'A'];
                    x = it;
                }
            }
            ans+=x;
            for(int i=0;i<n;i++){
                if(ar[i][j]!=x)tot++;
            }
        }
        cout << ans << endl;
        cout << tot << endl;
    }

    return 0;
}
