// In the name the Allah the Most Merciful.
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , c = 0 , tot = 0;
    while(cin >> n){
        if(!n)break;
        vector<int>v(n);
        for(auto &x:v)cin >> x;
        tot = 0;
        for(int i=0;i<v.size();i++){
            tot+=v[i];
        }
        tot/=n;
        int ans = 0;
        for(int i=0;i<v.size();i++){
            if(v[i]>tot)ans+=v[i]-tot;
        }
        cout << "Set #" << ++c << endl;
        cout << "The minimum number of moves is " << ans << "." << endl;
        cout << endl;
    }
    return 0;
}
