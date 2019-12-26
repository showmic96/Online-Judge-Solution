// In the name of Allah the Lord of The Worlds.

#include<bits/stdc++.h>
using namespace std;

int dp[55][3][6];
string ar;
int si;

bool check1 , check2;

bool is_vowel(char x)
{

    if(x=='A')return true;
    if(x=='E')return true;
    if(x=='I')return true;
    if(x=='O')return true;
    if(x=='U')return true;

    return false;
}

int f(int i , int v , int c)
{
    if(v==3){check2 = true;return 1;}
    if(c==5){check2 = true;return 1;}

    if(i==si){check1 = true;return 0;}

    if(dp[i][v][c]!=-1)return dp[i][v][c];

    int value1 = 2 , value2 = 2;

    if(ar[i]=='?'){

        value1 = f(i+1 , v+1 , 0);
        value2 = f(i+1 , 0 , c+1);
    }

    else if(is_vowel(ar[i])==true){

        value1 = f(i+1 , v+1 , 0);
    }

    else value1 = f(i+1 , 0 , c+1);

    return dp[i][v][c] = value1+value2;
}

int main(void)
{
    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++){

        memset(dp , -1 , sizeof(dp));
        cin >> ar;
        si = ar.size();
        check1 = false, check2 = false;

        int k = f(0 , 0 , 0);

        if(check1==true&&check2==true)printf("Case %d: MIXED\n",i+1);
        else if(check1==true)printf("Case %d: GOOD\n",i+1);
        else printf("Case %d: BAD\n",i+1);
    }

    return 0;
}
