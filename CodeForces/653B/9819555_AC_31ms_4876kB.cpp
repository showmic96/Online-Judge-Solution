// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

vector<string>edges[7];
int ans = 0 , n , m;

void bfs()
{
    queue<string>q;

    q.push("a");
    map<string , int>mp;

    while(!q.empty()){

        string t = q.front();
        q.pop();

        int si = t.size();

        if(si==n){if(mp[t]==0)ans++;mp[t] = 1;continue;}

        for(int i=0;i<1;i++){

            string temp = "";

            for(int j=0;j<i;j++){

                temp+=t[j];
            }

            int si2 = edges[t[i]-'a'].size();

            for(int j=0;j<si2;j++){

                string temp2 = temp;

                temp2+=edges[t[i]-'a'][j];

                for(int k=i+1;k<si;k++){

                    temp2+=t[k];
                }

                q.push(temp2);
            }
        }
    }
}

int main(void)
{
    cin >> n >> m;

    for(int i=0;i<m;i++){

        string ar;
        char x;
        cin >> ar >> x;

        edges[x-'a'].push_back(ar);
    }

    bfs();

    cout << ans << endl;

    return 0;
}
