// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ar[1100];

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        int n , m , k;
        scanf("%d %d %d",&n , &m, &k);

        vector<int>v;

        v.push_back(1);
        v.push_back(2);
        v.push_back(3);

        ll sum = 6;

        for(int i=3;i<n;i++){

            ll temp = v[i-1]+v[i-2]+v[i-3];
            temp%=m;
            temp++;

            v.push_back(temp);
        }

        memset(ar , 0 , sizeof(ar));

        ar[1] = 1;
        int i = 0 , j = 0;
        int counter = 1 , ans = 1e9;

        while(true){

            if(i==j){

                if(i==n-1)break;
            }

            if(counter==k){

                ar[v[i]]--;
                if(ar[v[i]]==0&&v[i]<=k)counter--;
                i++;

                if(counter==k){

                    ans = min(ans , j-i+1);
                }
            }

            else{

                j++;
                if(j==n)break;

                ar[v[j]]++;

                if(ar[v[j]]==1&&v[j]<=k)counter++;

                if(counter==k){

                    ans = min(ans , j-i+1);
                }
            }
        }

        if(ans==1e9)printf("Case %d: sequence nai\n",++c);
        else printf("Case %d: %d\n",++c , ans);
    }
    return 0;
}
