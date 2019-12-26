// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

vector<pair<double, int> > v;
int n;
double dp[1025];

double f(int i)
{
    //cout << i << endl;
    if(i<=0)return 0;

    if(dp[i]!=-1)return dp[i];

    double value = 123456789;
//cout << "yes" << endl;
    for(int j=0;j<=n;j++){

        value = min(value , f(i-v[j].second)+v[j].first);
    }

    return dp[i] = value;
}

int main(void)
{
    int c = 0;
    double in1;

    while(scanf("%lf %d",&in1 , &n)==2){
        v.clear();
        for(int i=0;i<1025;i++)dp[i] = -1;
        v.push_back(make_pair(in1 , 1));

        for(int i=0;i<n;i++){

            double value;
            int q;

            scanf("%d %lf",&q , &value);
            v.push_back(make_pair(value , q));
        }

        //memset(dp , -1 , sizeof(dp));

        scanf("\n");
        string ar;
        getline(cin , ar);
        int temp;
        stringstream ss(ar);
        printf("Case %d:\n",++c);

        while(ss >> temp){

            printf("Buy %d for $%.2f\n",temp , f(temp));
        }
    }

    return 0;
}
