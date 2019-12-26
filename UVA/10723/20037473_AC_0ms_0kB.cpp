// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 35;
string ar , br;
ll dp1[MAX][MAX] , dp2[MAX][MAX][2*MAX];

ll f1(int i , int j)
{
    if(i==ar.size()&&j==br.size())return 0;
    if(dp1[i][j]!=-1)return dp1[i][j];
    ll value = 1e18;
    if(i==ar.size())value = min(value , f1(i , j+1)+1);
    else if(j==br.size())value = min(value , f1(i+1, j)+1);
    else{
        if(ar[i]==br[j])value = min(value , f1(i+1, j+1)+1);
        value = min(value , f1(i+1, j)+1);
        value = min(value , f1(i , j+1)+1);
    }
    return dp1[i][j] = value;
}
ll f2(int i , int j , int k)
{
    if(k==0){
        if(i==ar.size()&&j==br.size())return 1;
        return 0;
    }
    if(i==ar.size()&&j==br.size()){
        if(k==0)return 1;
        return 0;
    }
    if(dp2[i][j][k]!=-1)return dp2[i][j][k];
    ll value = 0;
    if(i==ar.size())value+=f2(i , j+1 , k-1);
    else if(j==br.size())value+=f2(i+1, j , k-1);
    else{
        if(ar[i]==br[j])value+=f2(i+1, j+1 , k-1);
        else{
            value+=f2(i, j+1 , k-1);
            value+=f2(i+1, j , k-1);
        }
    }
    return dp2[i][j][k] = value;
}

char in1[35] , in2[35];

int main(void)
{
    int t , c = 0;
    cin >> t;
    getchar();
    while(t--){
        gets(in1);gets(in2);
        ar = "" , br = "";
        for(int i=0;i<strlen(in1);i++)ar+=in1[i];
        for(int i=0;i<strlen(in2);i++)br+=in2[i];
        memset(dp1 , -1 , sizeof(dp1));
        memset(dp2 , -1 , sizeof(dp2));
        ll ans1 = f1(0 , 0);
        ll ans2 = f2(0 , 0 , ans1);
        cout << "Case #" << ++c << ": " << ans1 << " " << ans2 << endl;
    }
    return 0;
}
