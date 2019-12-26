// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

long long ar[1000005];

int main(void)
{
    memset(ar , 0 , sizeof(ar));

    long long n , x;
    scanf("%lld %lld",&n , &x);

    vector<int>v;

    for(int i=0;i<n;i++){

        long long in;
        scanf("%lld",&in);
        ar[in]++;
        v.push_back(in);
    }

    long long counter = 0;

    for(int i=0;i<n;i++){

        ar[v[i]]--;
        long long temp = x^v[i];
        counter+=ar[temp];
    }

    printf("%lld\n",counter);

    return 0;
}
