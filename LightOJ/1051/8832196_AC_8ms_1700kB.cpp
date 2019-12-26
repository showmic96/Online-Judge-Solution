#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string ar;
int si;
bool check1 , check2;
int dp[123][6][4];

bool is_vowel(char x)
{
    if(x=='A')return true;
    if(x=='E')return true;
    if(x=='I')return true;
    if(x=='O')return true;
    if(x=='U')return true;

    return false;
}

int f(int i , int c , int v)
{
    if(c==5){check2 = true;return 0;}
    if(v==3){check2 = true;return 0;}

    if(i==si){check1=true;return 1;}

    if(dp[i][c][v]!=-1)return dp[i][c][v];

    int value1 = 0 , value2 = 0;

    if(ar[i]=='?'){

        value1 = f(i+1 , c+1 ,0);
        value2 = f(i+1 , 0 ,v+1);
    }

    else if(is_vowel(ar[i])==true)value1 = f(i+1 , 0 , v+1);
    else value1 = f(i+1 , c+1 , 0);

    return dp[i][c][v] = max(value1 , value2);
}

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){

        memset(dp , -1 , sizeof(dp));

        check1 = false , check2 = false;

        cin >> ar;//scanf("%s",&ar);
        si = ar.size();
        f(0 , 0 , 0);
        if(check1==true&&check2==true)printf("Case %d: MIXED\n",i+1);
        else if(check1==true)printf("Case %d: GOOD\n",i+1);
        else printf("Case %d: BAD\n",i+1);

    }

    return 0;
}
