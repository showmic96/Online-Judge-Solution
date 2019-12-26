// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

struct data{

    int mod;
    string value;

    data(int _mod , string _value){

        mod = _mod;
        value = _value;
    }
};

int n , m;
int ar[10];

int dp[10005];

string bfs()
{
    memset(dp , -1 , sizeof(dp));

    queue<data>current;

    current.push(data(0 , ""));

    bool first = false;

    while(!current.empty()){

        struct data temp = current.front();
        current.pop();

        if(dp[temp.mod]!=-1)continue;
        dp[temp.mod] = 1;

        for(int i=0;i<=9;i++){

            if(ar[i]==1)continue;
            if(first==false&&i==0)continue;

            if((temp.mod*10+i)%n==0){

                return temp.value+(char)('0'+i);
            }
            else{

                current.push(data((temp.mod*10+i)%n , temp.value+(char)('0'+i)));
            }
        }

        first = true;
    }

    return "-1";
}

int main(void)
{
    int t = 0;
    while(scanf("%d %d",&n , &m)==2){

        memset(ar , 0 , sizeof(ar));

        for(int i=0;i<m;i++){

            int in;
            scanf("%d",&in);
            ar[in]=1;
        }

        string ans = bfs();

        printf("Case %d: ",++t);
        cout << ans << endl;
    }
    return 0;
}
