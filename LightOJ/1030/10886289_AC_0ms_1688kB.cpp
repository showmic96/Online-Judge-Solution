// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

double dp[110];
bool visited[110];

vector<double>v;
int n;

double f(int i)
{
    if(i==n-1){

        return v[i];
    }

    if(visited[i])return dp[i];
    visited[i] = true;

    dp[i] = 0;

    double value = 0 , counter = 0;

    for(int j=1;j<=6;j++){

        if(i+j==n)break;

        counter++;
        value+= f(i+j) + v[i];
    }

    return dp[i] = value/counter;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        v.clear();
        scanf("%d",&n);
        memset(visited , false , sizeof(visited));
        for(int i=0;i<n;i++){

            double in;
            scanf("%lf",&in);
            v.push_back(in);
        }

        printf("Case %d: %.14f\n", ++c , f(0));
    }

    return 0;
}
