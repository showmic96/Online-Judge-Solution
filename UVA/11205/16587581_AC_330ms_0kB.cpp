// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ar[105][16] , n , p , counter = 1e9 , now[105];

int Set(int n , int pos)
{
    return n|(1<<pos);
}

int reSet(int n , int pos)
{
    return n & ~(1<<pos);
}

void f(int i , int c)
{
    if(i==p){

        set<int>st;
        for(int i=0;i<n;i++)st.insert(now[i]);
        if(st.size()!=n)c = 1e9;
        counter = min(counter , c);
        return ;
    }

    f(i+1 , c);

    for(int j=0;j<n;j++){

        if(ar[j][i]==1)now[j] = Set(now[j] , i);
    }

    f(i+1 , c+1);

    for(int j=0;j<n;j++){

        if(ar[j][i]==1)now[j] = reSet(now[j] , i);
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    while(t--){

        scanf("%d %d",&p , &n);

        for(int i=0;i<n;i++){

            for(int j=0;j<p;j++){

                scanf("%d",&ar[i][j]);
            }
        }

        memset(now , 0 , sizeof(now));
        counter = 1e9;
        f(0 , 0);

        printf("%d\n",counter);
    }
    return 0;
}
