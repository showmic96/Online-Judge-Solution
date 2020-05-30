// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>v[27];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    string ar;
    cin >> ar;
    for(int i=0;i<ar.size();i++){
        if(ar[i]=='#')v[26].push_back(i);
        else v[ar[i]-'a'].push_back(i);
    }
    for(int i=0;i<=26;i++){
        v[i].push_back(1000000);
    }
    int t;
    cin >> t;
    while(t--){
        cin >> ar;
        int now = -1;
        for(int i=0;i<ar.size();i++){
            int t1 = *upper_bound(v[ar[i]-'a'].begin() ,v[ar[i]-'a'].end() , now);
            int t2 = *upper_bound(v[26].begin() , v[26].end() , now);
            now = min(t1 , t2);
            if(now==1000000)break;
        }
        if(now==1000000)cout << "Plan should be changed" << endl;
        else cout << "Plan will be successful" << endl;
    }

    return 0;
}