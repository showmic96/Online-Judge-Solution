// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    set<int>st;
    for(int i=0;i<4;i++){

        int in;
        cin >> in;
        st.insert(in);
    }

    cout << 4-st.size() << endl;

    return 0;
}
