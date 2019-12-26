#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);

        vector<pair<int , int> > v;
        map<int , int>mp1 , mp2;

        for(int i=0;i<n;i++){

            int in1 , in2;
            scanf("%d %d",&in1 , &in2);
            v.push_back(make_pair(in1 , in2));
            mp2[in2]++;
            mp1[in1]++;
        }

        ll counter = 0;

        for(int i=0;i<n;i++){

            mp1[v[i].first]--;
            mp2[v[i].second]--;

            counter+=mp2[v[i].first];
            counter+=mp1[v[i].second];
        }

        printf("%lld\n",counter);
    }
    return 0;
}
