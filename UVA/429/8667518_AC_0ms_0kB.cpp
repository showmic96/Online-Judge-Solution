// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 222;
string data[MAX];
vector<int>edges[MAX+9];
int level[MAX+9];

void setUp()
{
    for(int i=0;i<=MAX;i++){

        level[i]=0;
        edges[i].clear();
    }
}

void bfs(int in)
{
    queue<int>current;

    level[in] = 1;

    current.push(in);

    while(!current.empty()){

        int u = current.front();

        current.pop();

        int si = edges[u].size();

        for(int i=0;i<si;i++){

            if(level[edges[u][i]]==0){

                level[edges[u][i]] = level[u] + 1;

                current.push(edges[u][i]);
            }
        }
    }
}

int diff(string ar , string br)
{
    if(ar.size()!=br.size())return 111;

    int si = ar.size();

    int d = 0;

    for(int i=0;i<si;i++){

        if(ar[i]!=br[i])d++;
    }

    return d;
}

int main(void)
{
    int t;
    cin >> t;
    bool space = false;
    while(t--){
        
        if(space)cout << endl;space = true;
        setUp();
        int d = 0;
        string temp;

        map<string , int>mp;
        map<int , string>ump;

        while(cin >> temp){

            if(temp=="*")break;

            data[d++] = temp;

            mp[temp] = d;
            ump[d] = temp;
        }

        for(int i=0;i<d;i++){

            for(int j=i+1;j<d;j++){

                if(diff(data[i] , data[j])==1){

                    edges[mp[data[i]]].push_back(mp[data[j]]);
                    edges[mp[data[j]]].push_back(mp[data[i]]);
                }
            }
        }

        scanf("\n");

        while(getline(cin, temp)){

            if(temp=="")break;

            stringstream ss(temp);

            string st , des;

            ss >> st;
            ss >> des;

            bfs(mp[st]);

            cout << st << " " << des << " " << level[mp[des]]-1 << endl;
            memset(level , 0 , sizeof(level));
        }

    }
    return 0;
}
