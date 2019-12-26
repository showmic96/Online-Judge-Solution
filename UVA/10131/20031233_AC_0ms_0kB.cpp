// In the name of Allah the most Merciful .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX = 1005;
int dp[MAX][MAX];

struct ss{
    int w , s , idx;
    ss(int _w , int _s , int _idx){
        w = _w;
        s = _s;
        idx = _idx;
    }
};
bool cmp(ss A , ss B)
{
    if(A.w==B.w){
        return A.s > B.s;
    }
    return A.w < B.w;
}

vector<ss> v;

int f(int i , int j)
{
    if(i==v.size())return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int value = f(i+1, j);
    if(j==1001){
        value = max(value , f(i+1, i)+1);
    }
    else{
        if(v[i].w>v[j].w&&v[i].s<v[j].s)value = max(value , f(i+1, i)+1);
    }
    return dp[i][j] = value;
}

int main(void)
{
    int a, b , c = 0;
    while(scanf("%d %d",&a , &b)==2){
        if(a==-1)break;
        v.push_back(ss(a , b , ++c));
    }
    sort(v.begin() , v.end() , cmp);
    memset(dp , -1 , sizeof(dp));
    printf("%d\n",f(0 , 1001));
    int now = 0 , last = 1001;
    for(int i=0;i<v.size();i++){
        if(now+f(i+1 , i)+1==f(0 , 1001)){
            now = now+1;
            last = i;
            printf("%d\n",v[last].idx);
        }
    }
    return 0;
}
