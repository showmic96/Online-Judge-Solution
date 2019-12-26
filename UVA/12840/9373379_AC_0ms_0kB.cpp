// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

const int INF = 1234567;

int n , k , mx;
int dp[303];

int ar[55];
int ans[303];


bool cmp(int a, int b){

    return a>b;
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        scanf("%d %d",&n , &k);

        for(int i=0;i<303;i++)dp[i] = INF;
        memset(ans , -1 , sizeof(ans));

        dp[0] = 0;

        for(int i=0;i<n;i++)scanf("%d",&ar[i]);

        //sort(ar , ar+n , cmp);

        for(int i=0;i<n;i++){

            for(int j=1;j<=k;j++){

                if(j-ar[i]>=0){

                    int temp = dp[j-ar[i]] + 1;

                    if(temp<dp[j]){

                        dp[j] = temp;
                        ans[j] = i;
                    }

                    else if(temp==dp[j]){

                        if(ar[ans[j]]<ar[i]){

                            ans[j] = i;
                        }
                    }

                }
            }
        }

        printf("Case %d: ",++c);

        if(dp[k]==INF)printf("impossible\n");
        else{

            printf("[%d]",dp[k]);
            vector<int>v;

            int d = dp[k];

            while(d--){

                v.push_back(ar[ans[k]]);
                k-=ar[ans[k]];
            }

            sort(v.begin() , v.end(), cmp);

            for(int i=0;i<v.size();i++)printf("% d",v[i]);

            printf("\n");

        }
    }
    return 0;
}
