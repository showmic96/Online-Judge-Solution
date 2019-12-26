#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<int>edges[123456];
bool isVisited[123456];
int p[123456];
int level[123456];

int counter = 0;

void setUp()
{
    for(int i=0;i<123456;i++){p[i] = i;level[i] = 1;}
}

int Find(int x)
{
    if(p[x]==x)return x;
    return p[x] = Find(p[x]);
}

void Union(int a , int b)
{
    int px = Find(a);
    int py = Find(b);

    if(px==py)return;
    //p[py] = px;

    if (level [px] < level [py]) swap (px, py);
    p [py] = px;
    level [px] += level [py];
}

int main(void)
{
    int t;
    cin >> t;
    int c = 0;

    while(t--){

        setUp();
        map<string , int>mp;
        c = 1;

        int n;
        cin >> n;

        while(n--){

            string ar , br;
            cin >> ar >> br;

            if(mp[ar]==0){

                mp[ar]= c++;
            }

            if(mp[br]==0){
                mp[br]=c++;
            }

            counter = 0;
            Union(mp[br], mp[ar]);

            int t1 = Find(mp[br]);
            int t2 = Find(mp[ar]);

            cout << max(level[t1] , level[t2]) << endl;
        }

    }
    return 0;
}
