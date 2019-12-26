// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

bool taken[27];
int len , n;

void f(int i , string ar)
{
    if(n==0)return ;
    if(i==len){

        cout << ar << endl;
        n--;
        return ;
    }

    for(int j=0;j<len;j++){

        if(taken[j]==false){

            taken[j] = true;

            string temp = "";
            temp+='A'+j;

            f(i+1 , ar + temp);

            taken[j] = false;
        }
    }
}

int main(void)
{
    int t , c = 0;
    scanf("%d",&t);
    while(t--){

        memset(taken , false , sizeof(taken));
        scanf("%d %d",&len , &n);
        printf("Case %d:\n",++c);
        f(0 , "");

    }
    return 0;
}
