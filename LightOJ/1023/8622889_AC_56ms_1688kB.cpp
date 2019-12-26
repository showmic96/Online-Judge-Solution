// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

bool taken[26];

int n , k;

void f(int i , string ar)
{
    if(i==n){

        cout << ar << endl;
        k--;

        return ;
    }

    if(i>=n)return;
    if(k<=0)return;

    for(int j=0;j<n;j++){

        if(taken[j]==false){

            taken[j] = true;

            string temp = "";
            temp+= 'A'+j;

            f(i+1 , ar+temp);

            taken[j] = false;
        }
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){

        memset(taken , false , sizeof(taken));

        scanf("%d %d",&n , &k);

        printf("Case %d:\n",i+1);

        f(0 , "");

    }
    return 0;
}
