// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll sq(ll x)
{
    return x*x;
}

double dis(pair<int , int>p1 , pair<int , int>p2)
{
    double dis = sq(p1.first-p2.first) + sq(p1.second-p2.second);
    return dis;
}

double area(pair<int , int>p1 , pair<int, int>p2 , pair<int ,int>p3)
{
    double a = p1.first*(p2.second-p3.second)
        + p2.first*(p3.second-p1.second)
        + p3.first*(p1.second-p2.second);
    return a;
}

int main(void)
{
    int n , ans = 0;
    scanf("%d",&n);
    vector<pair<int , int> > v(n);
    for(auto &x:v)scanf("%d %d",&x.first , &x.second);
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                double now = area(v[i], v[j] , v[k]);
                if(now!=0)ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
