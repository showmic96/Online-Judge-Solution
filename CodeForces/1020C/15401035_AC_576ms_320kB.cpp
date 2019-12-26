// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll>v[3005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , m;
    cin >> n >> m;

    for(int i=0;i<n;i++){

        ll in1 , in2;
        cin >> in1 >> in2;
        v[in1].push_back(in2);
    }

    for(int i=0;i<=3000;i++)sort(v[i].begin() , v[i].end());

    ll ans = 1e18;
    vector<ll>temp;

    for(int i=1;i<=n;i++){

        ll counter = 0;
        int tot = v[1].size();
        temp.clear();

        for(int j=2;j<=m;j++){
            int rem = v[j].size() - i ;

            for(int k=0;k<=rem;k++){counter+=v[j][k];tot++;}
            for(int k=max(0 , rem+1);k<v[j].size();k++){temp.push_back(v[j][k]);}
        }

        sort(temp.begin() , temp.end());

        int now = 0;

        while(tot<i){

            tot++;
            counter+=temp[now];
            now++;
        }

        ans = min(ans , counter);
    }

    cout << ans << endl;

    return 0;
}
