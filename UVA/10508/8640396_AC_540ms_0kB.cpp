// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

vector<int>edges[12345];
bool isVisited[12345];
map<string , int>mp;
map<int , string>ump;
string ar[12345];

void setUp()
{
    for(int i=0;i<12345;i++){

        edges[i].clear();
        isVisited[i] = false;
    }
}

void bfs(int i)
{
    cout << ump[i] << endl;

    queue<int>current;

    current.push(i);

    while(!current.empty()){

        int temp = current.front();
        current.pop();

        isVisited[temp] = true;

        int si = edges[temp].size();

        for(int i=0;i<si;i++){

            if(isVisited[edges[temp][i]]==false){

                cout << ump[edges[temp][i]] << endl;

                current.push(edges[temp][i]);
            }
        }
    }
}

int diff(string a , string b)
{
    int si = a.size() , counter = 0;

    for(int i=0;i<si;i++)if(a[i]!=b[i])counter++;
    return counter;
}

int main(void)
{
    int n , m;

    while(cin >> n >> m){

        mp.clear();
        ump.clear();
        setUp();

        int c = 1;

        for(int i=0;i<n;i++){

            cin >> ar[i];

            mp[ar[i]] = c;
            ump[c] = ar[i];

            c++;
        }

        for(int i=0;i<n;i++){

            for(int j=i+1 ; j<n;j++){

                if(diff(ar[i] , ar[j])==1){

                    edges[mp[ar[i]]].push_back(mp[ar[j]]);
                    edges[mp[ar[j]]].push_back(mp[ar[i]]);
                }
            }
        }

        bfs(1);
    }
}
