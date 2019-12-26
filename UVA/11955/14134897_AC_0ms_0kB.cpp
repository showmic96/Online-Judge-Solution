// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

char s[205] , x;
string n1 , n2;
int p;
ll dp[105][105];

ll f(int i , int j)
{
    if(j==0)return 1;
    if(i==j)return 1;
    if(j==1)return i;

    if(dp[i][j]!=-1)return dp[i][j];

    return dp[i][j] = f(i-1 , j)+f(i-1 , j-1);
}

int val(string ar)
{
    int ans = 0;

    for(int i=0;i<ar.size();i++){

        ans*=10;
        ans+=ar[i]-'0';
    }
    return ans;
}

void print(string ar)
{
    int si = ar.size();

    for(int i=0;i<si;i++){

        printf("%c",ar[i]);
    }
}

int main(void)
{
    memset(dp , -1 , sizeof(dp));

    int t , c = 0;
    scanf("%d",&t);

    while(t--){

        scanf("%s",&s);
        string temp = "";
        n1 = "" , n2 = "";

        int si = strlen(s) , i;

        for(i=1;i<si;i++){

            if(s[i]=='+')break;
            n1+=s[i];
        }

        for(++i;i<si;i++){

            if(s[i]==')')break;
            n2+=s[i];
        }

        for(i+=2;i<si;i++){

            temp+=s[i];
        }

        p = val(temp);

        printf("Case %d: ",++c);

        for(int i=0;i<=p;i++){

            if(i>0)printf("+");
            if(f(p, i)>1)printf("%lld",f(p , i));

            if(i!=p){

                if(f(p,i)>1)printf("*");
                print(n1);
                if(i!=p-1)printf("^%d",p-i);
            }

            if(i!=0){

                if(f(p, i)>1)printf("*");
                print(n2);
                if(i!=1)printf("^%d",i);
            }
        }

        printf("\n");
    }

    return 0;
}