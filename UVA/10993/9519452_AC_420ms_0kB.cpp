// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MAX = 100000+9;

ll n , mi , si;
string ar , ans = "";
bool visited[MAX+9];

struct data{

    ll modValue;
    string value;

    data(ll m , string v){

        modValue = m;
        value = v;
    }
};

vector<data>v;


void bfs()
{

    queue<data>q;
    for(int i=0;i<si;i++){
        string temp = "";
        temp+=ar[i];
        if(ar[i]!='0')q.push(data((ar[i]-'0')%n , temp));
    }

    while(!q.empty()){

        int u = q.front().modValue;
        string s = q.front().value;
        q.pop();

        if(u==0){ans = s;break;}

        if(visited[u]==true)continue;
        visited[u] = true;

        for(int i=0;i<si;i++){
            string temp = s;
            temp= s + ar[i];
            ll t = u*10 + (ar[i]-'0');
            t%=n;
            if(visited[t]==false)q.push(data(t , temp));
        }
    }

    return ;
}

int main(void)
{
    //freopen("input.txt","r",stdin);
    while(cin >> ar >> n){

        if(ar=="0"&&n==0)break;

        v.clear();

        for(int i=0;i<=n;i++)visited[i] = false;
        ans = "0";

        si = ar.size();
        sort(ar.begin() , ar.end());

        bfs();

        if(ans=="0")ans = "impossible";

        cout << ans << endl;
    }

    return 0;
}
