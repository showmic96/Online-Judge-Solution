// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t , k = 0;
    scanf("%d",&t);
    while(t--){

        vector<int>v;
        int sum = 0 , in;

        int a , b , c , d , e;

        for(int i=0;i<10;i++){

            scanf("%d",&in);
            sum+=in;
            v.push_back(in);
        }

        sum/=4;

        c = sum-v[0]-v[9];

        a = v[1] - c;

        b = v[0] - a;

        e = v[8] - c;

        d = v[9] - e;

        printf("Case %d: %d %d %d %d %d\n", ++k , a ,b , c , d , e);


    }
    return 0;
}
