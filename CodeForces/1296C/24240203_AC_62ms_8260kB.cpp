// In the name of Allah the Most Merciful.

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
        map<pair<int , int> , int>mp;
        int n , mx = 1e9 , l , r , x = 0 , y = 0;
        mp[{0 , 0}] = 0;
        cin >> n;
        string ar;
        cin >> ar;
        for(int i=0;i<n;i++){
            if(ar[i]=='U')x++;
            else if(ar[i]=='D')x--;
            else if(ar[i]=='L')y++;
            else y--;
            if(mp.find({x , y})!=mp.end()){
                int last = mp[{x , y}];
                int tot = i-last+2;
                if(tot<mx){
                    mx = tot;
                    l = last+1;
                    r = i+1;
                }
            }
            mp[{x , y}] = i+1;
        }
        if(mx==1e9)cout << -1 << endl;
        else cout << l << " " << r << endl;
    }

    return 0;
}
