// In the name of Allah the Most Merciful.

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
        vector<int>v;

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        int ar[10];
        memset(ar , 0 , sizeof(ar));

        bool check = false;

        for(int i=n-1;i>=0;i--){

            int now = v[i];

            for(int j=now+1;j<10;j++){

                if(ar[j]==1){

                    check = true;
                    int idx = j;

                    for(int k=i;k<n;k++){

                        if(v[k]==j){

                            swap(v[k] , v[i]);
                            sort(v.begin()+i+1 , v.end());
                            break;
                        }
                    }
                }

                if(check)break;
            }

            if(check)break;

            ar[now] = 1;
        }

        if(check){
            for(int i=0;i<n;i++){

                printf("%d",v[i]);
            }

            printf("\n");
        }
        else printf("-1\n");
    }

    return 0;
}
