// In the name the Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int sum[20000005];
int now[20000005] , lim;

void pre()
{
    sum[0] = 0;
    for(int i=0;i<=20000000;i++)now[i] = 1;
    now[10] = 2;
    now[100] = 3;
    now[1000] = 4;
    now[10000] = 5;
    now[100000] = 6;
    now[1000000] = 7;
    now[10000000] = 8;

    int cur = now[0];

    for(int i=1;;i++){

        cur = max(cur , now[i]);
        sum[i] = sum[i-1]+cur;
        if(sum[i]>100001000){lim = i;break;}
    }
}

int main(void)
{
    pre();
    ll n;
    while(cin >> n){

        int t = 50 , hi = lim-1 , low = 0 , mid , ans = -1;

        while(t--){

            mid = (hi+low)/2;
            if(sum[mid]<n){

                ans = mid;
                low = mid+1;
            }
            else hi = mid-1;
        }

        n-=sum[ans];

        ans++;
        vector<int>temp;
        while(ans){

            temp.emplace_back(ans%10);
            ans/=10;
        }

        reverse(temp.begin() , temp.end());
        printf("%d\n",temp[n-1]);
    }
    return 0;
}
