// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main (void)
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);

    vector<int>value;
    vector<int>:: iterator it;

    for(int i=0;i<n;i++){

        int in;

        scanf("%d",&in);
        value.push_back(in);

    }

    sort(value.begin() , value.end());

    int mx = 0;

    for(int i=0;i<n;i++){

        int temp = lower_bound(value.begin() , value.end() , value[i]*2 + 1) - value.begin();

        mx = max(mx , temp - i);
    }

    printf("%d\n",n-mx);

    return 0;
}
