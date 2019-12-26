// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n;
    scanf("%d",&n);

    map<int , int>mp;
    map<int , int>idx;
    vector<int>v;

    int mx = 1 , ans = 0;

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);

        if(mp.find(in-1)!=mp.end()){

            mp[in] = 0;

            mp[in]++;
            mp[in]+=mp[in-1];
            idx[in] = idx[in-1];

            if(mp[in]>mx){

                mx = mp[in];
                ans = idx[in];
            }
        }
        else {
            mp[in] = 1;
            idx[in] = i;
        }
    }

    printf("%d\n",mx);
    int last = v[ans]-1;

    for(int i=ans;i<n;i++){

        if(v[i]==last+1){

            printf("%d ",i+1);
            last = last+1;
        }
    }

    return 0;
}