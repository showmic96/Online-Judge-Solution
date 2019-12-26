// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int tt;
    cin >> tt;
    while(tt--){
        string s , t , p;
        cin >> s >> t >> p;
        int ar[26];
        memset(ar , 0 , sizeof(ar));
        for(int i=0;i<p.size();i++){
            ar[p[i]-'a']++;
        }
        int j = 0;bool check = true;
        for(int i=0;i<t.size();i++){
            if(j<s.size()&&t[i]==s[j]){
                j++;
            }
            else{
                if(ar[t[i]-'a']>0){
                    ar[t[i]-'a']--;
                }
                else check = false;
            }
        }
        if(j!=s.size())check = false;
        if(check)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
