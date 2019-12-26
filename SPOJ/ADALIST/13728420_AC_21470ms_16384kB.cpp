// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n , m;
    scanf("%d %d",&n , &m);
    vector<int>v;

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
    }

    for(int i=0;i<m;i++){

        int in;
        scanf("%d",&in);

        if(in==1){

            int k , x;
            scanf("%d %d",&k , &x);
            v.insert(v.begin()+k-1 , x);
        }
        if(in==2){

            int k;
            scanf("%d",&k);
            v.erase(v.begin()+k-1);
        }
        if(in==3){

            int n;
            scanf("%d",&n);
            printf("%d\n",v[n-1]);
        }
    }

    return 0;
}
