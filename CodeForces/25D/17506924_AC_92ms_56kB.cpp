// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1005;
int par[MAX+9];

int Find(int x)
{
    if(par[x]==x)return x;
    return par[x] = Find(par[x]);
}

void Union(int x , int y)
{
    int px = Find(x);
    int py = Find(y);

    par[py] = px;
}

vector<pair<pair<int , int> , pair<int , int> > > ans;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<=n;i++)par[i] = i;

    for(int i=0;i<n-1;i++){

        int in1 , in2;
        cin >> in1 >> in2;

        if(Find(in1)==Find(in2)){

            ans.push_back(make_pair(make_pair(in1 , in2),make_pair(0 , 0)));
        }
        else{

            Union(in1 , in2);
        }
    }

    int now = 0;

    for(int i=1;i<=n;i++){

        for(int j=i+1;j<=n;j++){

            if(Find(i)!=Find(j)){

                ans[now].second.first = i;
                ans[now].second.second = j;
                now++;

                Union(i , j);
            }
        }
    }

    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++){

        cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second.first << " " << ans[i].second.second << endl;
    }

    return 0;
}
