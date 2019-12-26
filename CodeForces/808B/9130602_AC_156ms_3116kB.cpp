// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<double>v;

int main(void)
{
    int n , k;
    scanf("%d %d",&n, &k);//cin >> n >> k;
    v.push_back(0);

    for(int i=0;i<n;i++){

        double in;
        scanf("%lf",&in);//cin >> in;
        v.push_back(in);
    }

    for(int i=1;i<=n;i++){

        v[i]+=v[i-1];
    }

    double sum = 0 , week = n-k+1;

    for(int i=1;i<=n;i++){

        if(i+k-1>=n+1)break;

        sum+= (v[i+k-1] - v[i-1])/week;
    }

    printf("%.14f\n",sum);

    return 0;
}
