// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int lis[10005] , lds[10005];

int main(void)
{
    int n;
    while(scanf("%d",&n)==1){

        memset(lis , 1 , sizeof(lis));
        memset(lds , 1 , sizeof(lds));

        vector<int>v;
        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v.push_back(in);
        }

        vector<int>ls;
        vector<int>:: iterator it;

        for(int i=0;i<n;i++){

            it = lower_bound(ls.begin() , ls.end() , v[i]);
            if(it==ls.end())ls.push_back(v[i]);
            else ls[it-ls.begin()] = v[i];

            lis[i] = ls.size();

        }

        ls.clear();

        for(int i=n-1;i>=0;i--){

            it = lower_bound(ls.begin() , ls.end() , v[i]);
            if(it==ls.end())ls.push_back(v[i]);
            else ls[it-ls.begin()] = v[i];

            lds[i] = ls.size();

        }

        int mx = 0;

        for(int i=0;i<n;i++){

            mx = max(mx , min(lds[i] , lis[i]));
        }

        printf("%d\n",2*mx-1);
    }
    return 0;
}
