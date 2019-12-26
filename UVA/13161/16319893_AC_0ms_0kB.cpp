// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    vector<int>v1 , v2;

    v1.push_back(0);
    v1.push_back(0);
    v1.push_back(0);
    v2.push_back(0);
    v2.push_back(0);
    v2.push_back(0);
    v2.push_back(0);

    int now = 0;
    for(int i=3;now<=1000;i++){

        now+=i;
        v1.push_back(now);
    }
    now = 0;
    for(int i=4;i<=1000;i++){

        now+=i;
        v2.push_back(now);
    }

    int d , n , m;
    while(scanf("%d %d %d",&d , &n , &m)==3){

        for(int i=3;;i++){

            if(v1[i]+v2[i+d]==n+m){

                printf("%d\n",n-v2[i+d]);
                break;
            }
        }
    }

    return 0;
}
