// In the name of Allah the Lord of the worlds .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 2000+7;

bool isVisited[MAX];
int level[MAX];
vector<int>edges[MAX];

void setUp(int a)
{
    for(int i=0;i<=a;i++){

        isVisited[i] = false;
        level[i] = 0;
    }
}

int bfs(int a)
{
    int ans = 0;

    level[a] = 1;

    isVisited[a] = true;

    queue<int>current;

    current.push(a);

    while(!current.empty()){

        int temp = current.front();
        current.pop();

        int si = edges[temp].size();

        for(int i=0;i<si;i++){

            if(isVisited[edges[temp][i]]==false){

                level[edges[temp][i]]  = level[temp] + 1;

                if(level[edges[temp][i]]>ans) ans = level[edges[temp][i]];

                current.push(edges[temp][i]);

                isVisited[edges[temp][i]] = true;
            }
        }
    }

    return ans;
}

int main(void)
{
    int n , in;
    cin >> n;

    setUp(n);

    int ar[2100]  , d = 0;

    for(int i=1;i<=n;i++){

        cin >> in;

        if(in!=-1){

            edges[in].push_back(i);

        }

        else{
            ar[d] = i;
            d++;
        }
    }

    int ans = 1 , temp;

    for(int i=0;i<d;i++){

        temp=bfs(ar[i]);

        if(temp>ans)ans=temp;
    }

    cout << ans << endl;

    return 0;
}
