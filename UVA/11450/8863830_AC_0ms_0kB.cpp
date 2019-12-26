// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int dp[23][234];
int n , m;

vector<int>ar[23];

int f(int i , int value)
{
    if(i==n){

        if(value>m)return -12345;
        else return value;
    }

    if(dp[i][value]!=-1)return dp[i][value];

    int v = 0;

    int si = ar[i].size();

    for(int j=0;j<si;j++){

        v = max(v , f(i+1 , value+ar[i][j]));
    }

    return dp[i][value] = v;
}

void setUp()
{
    for(int i=0;i<23;i++)ar[i].clear();
}

int main(void)
{
    int t;
    cin >> t;

    while(t--){

        memset(dp , -1 , sizeof(dp));
        cin >> m >> n;

        setUp();

        for(int i=0;i<n;i++){

            int lim;
            cin >> lim;

            for(int j=0;j<lim;j++){

                int in;
                cin >> in;
                ar[i].push_back(in);
            }

        }

        int temp = f(0 , 0);

        if(temp!=0)cout << temp << endl;
        else cout << "no solution" << endl;
    }
    return 0;
}
