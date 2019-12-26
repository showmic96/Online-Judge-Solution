// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n;
    scanf("%d",&n);

    vector<int>v;
    v.push_back(1);

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
    }

    v.push_back(1000000);

    sort(v.begin() , v.end());

    int mi = 1e9;

    for(int i=0;i<v.size()-1;i++){

        mi = min(mi , max(v[i]-1 , 1000000-v[i+1]));
    }

    mi = min(mi , v[v.size()-1]-1);

    mi = min(mi ,1000000-v[1]);

    printf("%d\n",mi);

    return 0;
}
