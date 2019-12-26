#include<bits/stdc++.h>
using namespace std;
#define si 1000

char ar[si][si];
int i , j;


void oil_location(int a , int b)
{
    if(ar[a][b]=='*')return ;
    else if(a<0||b<0)return ;
    else if(a>i-1||b>j-1)return ;

    ar[a][b]='*';

    oil_location(a,b-1);
    oil_location(a,b+1);
    oil_location(a+1,b-1);
    oil_location(a+1,b);
    oil_location(a+1,b+1);
    oil_location(a-1,b-1);
    oil_location(a-1,b);
    oil_location(a-1,b+1);
}



int main(void)
{
    while(cin >> i >> j){

        if(!i&&!j)break;

        for(int a=0;a<i;a++)cin >> ar[a];

        int count1 = 0;

        for(int a=0;a<i;a++){


            for(int b=0;b<j;b++){

                if(ar[a][b]=='@'){

                    count1++;
                    oil_location(a,b);
                }

            }
        }

        cout << count1 << endl;
    }


    return 0;
}
