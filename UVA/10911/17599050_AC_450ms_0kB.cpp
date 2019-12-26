// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

double dp[(1<<16)+5];
bool vis[(1<<16)+5];
vector<pair<double , double> > v;

int n;
char x[1005];

bool Check(int n , int pos)
{
    return n&(1<<pos);
}
int Set(int n , int pos)
{
    return n|(1<<pos);
}

double dis(double x1 , double y1 , double x2 , double y2)
{
    double ans = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    ans = sqrt(ans);
    return ans;
}

double f(int mask)
{
    if(mask==(1<<(2*n))-1){

        return 0;
    }
    if(vis[mask]==true)return dp[mask];
    vis[mask] = true;

    double value = 1e18;

    for(int i=0;i<2*n;i++){

        if(Check(mask , i)==false){

            for(int j=0;j<2*n;j++){

                if(i==j)continue;
                if(Check(mask , j)==false){

                    int temp = Set(mask , i);
                    temp = Set(temp , j);

                    value = min(value , f(temp)+dis(v[i].first , v[i].second , v[j].first , v[j].second));
                }
            }
        }
    }

    return dp[mask] = value;
}

int main(void)
{
    int c = 0;
    while(scanf("%d",&n)==1){

        if(n==0)break;

        memset(vis , false , sizeof(vis));
        v.clear();

        for(int i=0;i<2*n;i++){

            double in1 , in2;
            scanf("%s %lf %lf",&x , &in1 , &in2);
            v.emplace_back(in1 , in2);
        }

        printf("Case %d: %.2f\n",++c , f(0));
    }
    return 0;
}
