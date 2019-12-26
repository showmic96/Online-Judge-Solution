// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , ans , mx;
vector<int>v1 , v2;

void f(int value)
{
    int lim = 0;
    for(lim=0;lim<n;lim++){

        if(v1[lim]!=v2[lim])break;
    }

    if(lim==n){

        if(value==mx){

            ans++;
        }
        else if(value<mx){

            ans = 1;
            mx = value;
        }
        return ;
    }

    if(value>mx)return ;

    for(int i=lim;i<n-1;i++){

        swap(v1[i] , v1[i+1]);
        f(value+1);
        swap(v1[i] , v1[i+1]);
    }

    return;
}

int main(void)
{
    int c = 0;
    while(scanf("%d",&n)==1){

        if(n==0)break;

        ans = 1e9;
        v1.clear();v2.clear();

        for(int i=0;i<n;i++){

            int in;
            scanf("%d",&in);
            v1.push_back(in);
        }

        v2 = v1;mx = 25;
        sort(v2.begin() , v2.end());

        bool check = true;
        for(int i=0;i<n;i++)if(v1[i]!=v2[i])check = false;

        f(0);
        if(check==true)ans = 0;

        printf("There are %d swap maps for input data set %d.\n",ans , ++c);
    }

    return 0;
}
