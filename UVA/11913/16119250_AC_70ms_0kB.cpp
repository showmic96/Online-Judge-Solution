// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;

struct ss{

    int s , en, p;
    ss(int _s , int _en , int _p){

        s = _s;
        en = _en;
        p = _p;
    }
};

bool cmp(ss A , ss B)
{
    if(A.s==B.s)return A.en<B.en;
    return A.s<B.s;
}

vector<ss>v;

int dp[105][105][105];

int f(int i , int j , int now)
{
    if(now>n)return 0;

    if(dp[i][j][now]!=-1)return dp[i][j][now];

    int value = f(i , j , now+1);

    if(v[now].s>=v[i].en||i==0)value = max(value , f(now , j , now+1)+v[now].p);
    if(v[now].s>=v[j].en||j==0)value = max(value , f(i , now , now+1)+v[now].p);

    return dp[i][j][now] = value;
}

int main(void)
{
    int c = 0;
    while(cin >> n){

        if(n==0)break;
        v.clear();
        v.push_back(ss(0 , 0 , 0));
        for(int i=1;i<=n;i++){

            int h1 , m1 , h2 , m2 , in;
            scanf("%d:%d-%d:%d %d",&h1 , &m1 , &h2 , &m2 , &in);

            string ar;
            getline(cin , ar);

            v.push_back(ss(h1*60+m1 , h2*60+m2 , in));
            if(h1*60+m1<6*60){
                v[i].s+=60*24;
            }
            if(v[i].en<v[i].s)v[i].en+=60*24;
        }

        sort(v.begin() , v.end() , cmp);

        memset(dp , -1 , sizeof(dp));
        printf("Case %d: ",++c);

        cout << f(0 , 0 , 1) + 0<< endl;
    }

    return 0;
}