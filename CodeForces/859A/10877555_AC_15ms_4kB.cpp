// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int>v;
    int n;
    cin >> n;

    for(int i=0;i<n;i++){

        int in;
        cin >> in;
        v.push_back(in);
    }

    sort(v.begin() , v.end());

    cout << max(0 , v[n-1] - 25) << endl;

    return 0;
}
