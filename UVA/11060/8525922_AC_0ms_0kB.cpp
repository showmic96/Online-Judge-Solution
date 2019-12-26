// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e3;

vector<int>edges[MAX+9];
vector<int>ans;
int in_degree[MAX+9];
bool isVisited[MAX+9];

map<string , int> mp;
map<int, string > mp2;
priority_queue<int>current;

void setUp(int n)
{

    for(int i=0;i<=n;i++){

        edges[i].clear();
    }
}

void bfs()
{
    int i;

    while(!current.empty()){

        i = current.top();
        current.pop();
        //cout << i << endl;


        ans.push_back(i);


        int si = edges[i].size();

        for(int j=0;j<si;j++){

            int temp = edges[i][j];

            in_degree[temp]--;

            if(in_degree[temp]==0){

                current.push(temp);
            }
        }

    }
}

int main(void)
{
    int n , m , cc = 0;

    while(cin >> n){

        int c = n;

        mp.clear();
        mp2.clear();

        setUp(n);
        memset(in_degree , 0 , sizeof(in_degree));
        memset(isVisited , false , sizeof(isVisited));

        for(int i=0;i<n;i++){

            string ar;
            cin >> ar;

            mp[ar] = c;
            mp2[c] = ar;
            c--;
        }

        cin >> m;

        while(m--){

            string ar , br;
            cin >> ar >> br;

            int t1 = mp[ar] , t2 = mp[br];

            edges[t1].push_back(t2);
            in_degree[t2]++;
        }

        ans.clear();

        for(int i=1;i<=n;i++){

            if(isVisited[i]==false&&in_degree[i]==0){
                //cout << "Debug : " << mp2[i] << endl;
                current.push(i);
            }
        }

        bfs();

        printf("Case #%d: ",++cc);

        cout << "Dilbert should drink beverages in this order: ";

        cout << mp2[ans[0]];

        for(int i=1;i<ans.size();i++){

            cout << " " << mp2[ans[i]];
        }

        cout << "." << endl << endl;
    }
    return 0;
}
