// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    vector<int>v(n);
    for(auto &x:v)cin >> x;
    for(int i=0;i<n;i++){
        if(i==0){
            cout << v[i+1]-v[i] << " " << v[n-1]-v[i] << endl;
        }
        else if(i==n-1){
            cout << v[i]-v[i-1] << " " << v[i]-v[0] << endl;
        }
        else{
            cout << min(abs(v[i]-v[i+1]) , abs(v[i]-v[i-1])) << " " << max(abs(v[0]-v[i]) , abs(v[i]-v[n-1])) << endl;
        }
    }
    return 0;
}
