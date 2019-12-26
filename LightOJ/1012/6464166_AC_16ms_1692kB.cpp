#include<bits/stdc++.h>
using namespace std;

char ar[51][51];
int i , j;
int cou;

void reset()
{
    for(int a=0;a<51;a++)memset(ar[a],'\0',sizeof(ar[a]));
}

void where_i_can_go(int a , int b)
{


    if(ar[a][b]=='.')cou++;
    if(ar[a][b]=='#')return;
    else if(a<0||b<0)return;
    else if(a>j-1||b>i-1)return;



    ar[a][b]='#';

    where_i_can_go(a,b+1);
    where_i_can_go(a,b-1);
    where_i_can_go(a+1,b);
    where_i_can_go(a-1,b);
    //cout << cou << endl;

}


int main(void)
{
    int t;
    cin >> t;

    for(int s = 0; s < t ; s++){
        cou=0;
        reset();
        cin >> i >> j;

        for(int a =0 ;a<j;a++)cin >> ar[a];


        for(int a=0;a<j;a++){

            for(int b=0;b<i;b++){

                if(ar[a][b]=='@')where_i_can_go(a , b);
            }
        }

        printf("Case %d: ",s+1);
        cout << cou+1 << endl;
    }

    return 0;

}
