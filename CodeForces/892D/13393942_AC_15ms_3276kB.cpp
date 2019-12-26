// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int n;
    scanf("%d",&n);

    vector<int>ans , v;
    int mi = 2e9;

    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
        ans.push_back(0);
        mi = min(mi , in);
    }

    for(int i=0;i<n;i++){

        int mx = 2e9;

        for(int j=0;j<n;j++){

            if(v[i]<v[j]){

                mx = min(mx , v[j]);
            }
        }

        if(mx==2e9)mx = mi;

        ans[i] = mx;
    }


    for(int i=0;i<n;i++){

        if(i>0)printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");

    return 0;
}
