// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

char ar[15];
int n;
string ans;
bool check;

int dp[2][15][15][1005];

struct node{

    int i , j , k , sig;
    string value;
    node(int _sig , int _i , int _j , int _k , string _value){

        sig = _sig;
        i = _i;
        j = _j;
        k = _k;
        value = _value;
    }
};

string toString(int x)
{
    if(x==1)return "1";
    if(x==2)return "2";
    if(x==3)return "3";
    if(x==4)return "4";
    if(x==5)return "5";
    if(x==6)return "6";
    if(x==7)return "7";
    if(x==8)return "8";
    if(x==9)return "9";
    if(x==10)return "10";

}

void bfs()
{
    memset(dp , -1 , sizeof(dp));

    queue<node>current;

    current.push(node(0 , 0 , 0 , 0 , ""));

    while(!current.empty()){

        int sig = current.front().sig;
        int i = current.front().i;
        int j = current.front().j;
        int k = current.front().k;
        string value = current.front().value;
        current.pop();

        if(dp[sig][i][j][k]!=-1)continue;
        dp[sig][i][j][k] = 1;
        if(sig==1)i = -i;
        if(k==n){

            check = true;
            ans = value;
            break;
        }
        if(value!="")value+=" ";
        for(int l=0;l<10;l++){
            if(l==j-1)continue;
            if(ar[l]=='1'){

                if(k%2==0){

                    int temp = i+l+1;
                    if(temp==0)continue;
                    if(temp>10||temp<0)continue;

                    current.push(node(0 , temp , l+1 , k+1 , value+toString(l+1)));
                }

                else{

                    int temp = i-l-1;
                    if(temp==0)continue;
                    if(temp<-10||temp>0)continue;

                    current.push(node(1 , abs(temp) , l+1 , k+1 , value+toString(l+1)));
                }
            }
        }
    }
}

int main(void)
{
    scanf("%s",&ar);
    scanf("%d",&n);
    check = false;

    bfs();

    if(check==false){

        printf("NO\n");
    }
    else{
        printf("YES\n");
        int si = ans.size();
        for(int i=0;i<si;i++){

            printf("%c",ans[i]);
        }

        printf("\n");
    }
    return 0;
}

/*
0000000101
3
*/
