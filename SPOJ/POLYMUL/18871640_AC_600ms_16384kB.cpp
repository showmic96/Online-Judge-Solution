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
        n++;
        vector<ll>v1(n) , v2(n) , v(2*n , 0);
        for(auto &x:v1)cin >> x;
        for(auto &x:v2)cin >> x;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                v[i+j] += v1[i]*v2[j];
            }
        }
        for(int i=0;i<2*n-1;i++){
            if(i)cout << " ";
            cout << v[i];
        }
        cout << endl;
    }
    return 0;
}
