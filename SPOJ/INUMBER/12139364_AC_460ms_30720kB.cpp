// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int dp[1005][1005];

struct node{

    int value , sum;

    node(int _value , int _sum){

        value = _value;
        sum = _sum;
    }
};

struct p{

    int x , y , d;
    p(){

        x = -1 , y = -1;
    }

}dir[1005][1005];

void bfs()
{
    queue<node>current;
    current.push(node(0 , 0));

    while(!current.empty()){

        int value = current.front().value;
        int sum = current.front().sum;

        current.pop();

        if(value==0&&sum==n){
            return ;
        }

        for(int i=0;i<=9;i++){

            if(value==0&&sum==0&&i==0)continue;

            if(sum+i>n)break;

            int vl = value*10+i;
            vl%=n;
            int s = sum+i;

            if(dp[vl][s]==1)continue;
            dp[vl][s]=1;

            current.push(node(vl, s));
            dir[vl][s].x = value;
            dir[vl][s].y = sum;
            dir[vl][s].d = i;
        }
    }
}

vector<int>v;

void Find(int x , int y)
{
    if(y==0){

        return ;
    }

    v.push_back(dir[x][y].d);
    Find(dir[x][y].x , dir[x][y].y);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        for(int i=0;i<1005;i++){

            for(int j=0;j<1005;j++){

                dir[i][j].x = -1;
                dir[i][j].y = -1;
            }
        }
        v.clear();
        memset(dp , -1 , sizeof(dp));

        cin >> n;
        bfs();

        Find(0 , n);

        int si = v.size();

        reverse(v.begin() , v.end());

        for(int i=0;i<si;i++){

            cout << v[i];
        }

        cout << endl;

    }

    return 0;
}
