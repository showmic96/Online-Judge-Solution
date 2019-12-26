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
    while(n--){
        string ar , br;
        cin >> ar >> br;
        vector<pair<char ,int > > v1 , v2;
        for(int i=0;i<ar.size();){
            int j=i;
            int counter = 0;
            while(j<ar.size()&&ar[i]==ar[j])j++ , counter++;
            v1.push_back({ar[i] , counter});
            i = j;
        }
        for(int i=0;i<br.size();){
            int j=i;
            int counter = 0;
            while(j<br.size()&&br[i]==br[j])j++ , counter++;
            v2.push_back({br[i] , counter});
            i = j;
        }
        bool check = true;
        if(v1.size()!=v2.size())check = false;
        else{
            for(int i=0;i<v1.size();i++){
                if(v1[i].first!=v2[i].first)check = false;
                if(v1[i].second>v2[i].second)check = false;
            }
        }
        if(check)cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
