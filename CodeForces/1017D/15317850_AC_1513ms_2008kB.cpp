// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n , m , q;
vector<int>v;
int mp[4900];
int t;

int ans[(1<<12)+5][105];

bool Check(int N,int pos){return (bool)(N & (1<<pos));}

void f(int i , int val , int number)
{
    if(i==n){

        if(val<=100){

            ans[number][val] += mp[t];
        }
        return ;
    }

    if(Check(t , n-1-i)==true){

        f(i+1 , val+v[i] , number*2+1);
        f(i+1 , val , number*2);
    }
    else{

        f(i+1 , val , number*2+1);
        f(i+1 , val+v[i] , number*2);
    }
}

int get(string ar)
{
    int val = 0;
    for(int i=0;i<ar.size();i++){

        val*=2;
        if(ar[i]=='1')val+=1;
    }
    return val;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    memset(ans , 0 , sizeof(ans));
    memset(mp , 0 , sizeof(mp));

    cin >> n >> m >> q;
    for(int i=0;i<n;i++){

        int in;
        cin >> in;
        v.push_back(in);
    }

    for(int i=0;i<m;i++){

        string ar;
        cin >> ar;
        mp[get(ar)]++;
    }

    for(int i=0;i<(1<<n);i++){

        t = i;
        f(0 , 0 , 0);
    }

    for(int i=0;i<(1<<n);i++){

        for(int j=1;j<=100;j++)ans[i][j]+=ans[i][j-1];
    }

    while(q--){

        string ar;
        int val;
        cin >> ar >> val;
        cout << ans[get(ar)][val] << endl;
    }

    return 0;
}
