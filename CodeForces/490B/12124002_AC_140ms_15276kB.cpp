// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e6+9;

int ar[MAX+9] , br[MAX+9];
int ans[MAX+9];

int main(void)
{
    memset(ar , -1 , sizeof(ar));
    memset(br , -1 , sizeof(br));
    memset(ans , -1 , sizeof(ans));
    vector<int>v;

    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){

        int in1 , in2;
        scanf("%d %d",&in1 , &in2);
        ar[in1] = in2;
        br[in2] = in1;
        v.push_back(in2);
    }

    if(n%2==0){

        int cur = 0;

        for(int i=1;i<n;i+=2){

            ans[i] = ar[cur];
            cur = ar[cur];
        }

        cur = 0;

        for(int i=n-2;i>=0;i-=2){

            ans[i] = br[cur];
            cur = br[cur];
        }

        for(int i=0;i<n;i++){

            if(i>0)printf(" ");
            printf("%d",ans[i]);
        }

        printf("\n");
    }

    else{

        int cur = 0;

        for(int i=1;i<n;i+=2){

            ans[i] = ar[cur];
            cur = ar[cur];
        }

        for(int i=0;i<n;i++){

            if(ar[v[i]]==-1&&v[i]>0){

                cur = v[i];
            }
        }

        ans[n-1] = cur;

        for(int i=n-3;i>=0;i-=2){

            ans[i] = br[cur];
            cur = br[cur];
        }

        for(int i=0;i<n;i++){

            if(i>0)printf(" ");
            printf("%d",ans[i]);
        }

        printf("\n");
    }

    return 0;
}
