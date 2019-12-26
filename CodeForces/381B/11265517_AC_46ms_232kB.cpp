// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n;
    scanf("%d",&n);

    vector<int>v1 , v2;
    map<int , int>mp;

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);

        if(mp[in]==0){

            v1.push_back(in);
        }

        else if(mp[in]==1){

            v2.push_back(in);
        }

        mp[in]++;
    }

    sort(v1.begin() , v1.end());
    sort(v2.begin() , v2.end());

    reverse(v2.begin() , v2.end());

    int si1 = v1.size() , si2 = v2.size();

    int ans = si1+si2;

    if(v1.empty()==false&&v2.empty()==false)if(v1[si1-1]==v2[0]) ans--;

    printf("%d\n", ans);

    for(int i=0;i<si1;i++){

        printf("%d ",v1[i]);
    }

    for(int i=0;i<si2;i++){

        if(i==0){

            if(v2[i]==v1[si1-1])continue;
        }

        printf("%d ",v2[i]);
    }

    printf("\n");

    return 0;
}
