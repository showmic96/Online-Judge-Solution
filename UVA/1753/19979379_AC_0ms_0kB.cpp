// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<double , double > >v;
int n ; double t;

bool possible(double mid)
{
    double temp = 0;
    for(int i=0;i<v.size();i++){
        double now = v[i].second+mid;
        if(now<=0)return false;
        temp+=v[i].first/now;
    }
    if(temp<=t)return true;
    return false;
}

int main(void)
{
    while(scanf("%d %lf",&n , &t)==2){
        v.clear();
        for(int i=0;i<n;i++){
            double in1 , in2;
            scanf("%lf %lf",&in1 , &in2);
            v.push_back({in1 , in2});
        }
        double hi = 1e9 , low = -1e9 , mid , ans = -1;
        int t = 200;
        while(t--){
            mid = (hi+low)/2;
            if(possible(mid)==true){
                hi = mid;
                ans = mid;
            }
            else{
                low = mid;
            }
        }
        printf("%.14f\n",ans);
    }
    return 0;
}
