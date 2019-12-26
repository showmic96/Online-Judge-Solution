// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int dp[(1<<17) + 10];
int n , lim;
vector<pair<double , double> > v;

int Set(int n , int pos)
{
    return n|(1<<pos);
}

bool Check(int n , int pos)
{
    return n&(1<<pos);
}

double slope(pair<double , double> p1 , pair<double , double> p2)
{
    if(p1.first - p2.first==0)return 0;
    if(p1.second - p2.second==0)return 1e19;
    return ((p2.second-p1.second)/(p2.first-p1.first));
}

int f(int mask)
{
    if(mask==lim)return 0;

    if(dp[mask]!=-1)return dp[mask];

    int temp = mask;
    int s = mask;
    int value = INT_MAX;

    for(int i=0;i<n;i++){

        if(Check(mask , i)==false){
            bool check = false;

            mask = Set(mask , i);

            for(int j=i+1;j<n;j++){

                if(Check(mask , j)==false){

                    check = true;

                    temp = mask;

                    double s = slope(v[i] , v[j]);

                    for(int k=0;k<n;k++){

                        if(slope(v[k] , v[i])==s)temp = Set(temp , k);
                    }

                    value = min(value , f(temp) + 1);
                }
            }

            if(check==false)value = min(value , f(mask) + 1);
            break;
        }
    }

    return dp[s] = value;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        memset(dp , -1 , sizeof(dp));

        v.clear();

        scanf("%d",&n);

        lim = 1<<n;
        lim--;

        for(int i=0;i<n;i++){

            double in1 , in2;
            scanf("%lf %lf",&in1 , &in2);
            v.push_back(make_pair(in1 , in2));
        }

        printf("Case %d: %d\n",++c , f(0));
    }
    return 0;
}
