// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n , ans = 0;
    string ar;
    set<char>st;

    cin >> n >> ar;

    for(int i=0;i<ar.size();i++){

        if(ar[i]>='a'&&ar[i]<='z')st.insert(ar[i]);
        else st.clear();

        ans = max(ans , (int)st.size());
    }

    cout << ans << endl;

    return 0;
}
