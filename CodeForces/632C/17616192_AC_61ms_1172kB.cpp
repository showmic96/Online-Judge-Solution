// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(string s1 , string s2)
{
    return s1+s2<s2+s1;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    vector<string>v(n);

    for(int i=0;i<n;i++){

        cin >> v[i];
    }
    sort(v.begin() , v.end() , cmp);
    for(auto ans : v)cout << ans;
    cout << endl;
    return 0;
}
