// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 26;

vector<int>edges[MAX];
bool awake[MAX];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , m;
    while(cin >> n >> m){
        for(int i=0;i<26;i++)edges[i].clear() , awake[i] = false;
        string ar;
        cin >> ar;
        for(int i=0;i<ar.size();i++){
            awake[ar[i]-'A'] = true;
        }
        for(int i=0;i<m;i++){
            string ar;
            cin >> ar;
            edges[ar[0]-'A'].push_back(ar[1]-'A');
            edges[ar[1]-'A'].push_back(ar[0]-'A');
        }
        int counter = 0 , done = 0;
        while(true){
            bool change = false;
            vector<int>v;
            for(int i=0;i<26;i++){
                if(awake[i]==false){
                    int cnt = 0;
                    for(int j=0;j<edges[i].size();j++){
                        if(awake[edges[i][j]])cnt++;
                    }
                    if(cnt>=3)v.push_back(i);
                }
            }
            for(int i=0;i<v.size();i++){
                change = true;
                awake[v[i]] = true;
            }
            if(change==false)break;
            counter++;
        }
        for(int i=0;i<26;i++){
            if(awake[i]==true)done++;
        }
        if(done==n)cout << "WAKE UP IN, " << counter << ", YEARS" << endl;
        else cout << "THIS BRAIN NEVER WAKES UP" << endl;
    }
    return 0;
}
