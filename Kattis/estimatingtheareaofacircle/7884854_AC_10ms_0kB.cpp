// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pi acos(-1)

int main(void)
{
    //freopen("input.txt","r",stdin);

    double r , m , c;
    while(cin >> r >> m >> c){

        if(r==0&&m==0&&c==0)break;
        printf("%.14lf %.14lf\n",pi*r*r , 4*r*r/(m/c));
    }

    return 0;
}
