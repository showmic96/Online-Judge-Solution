// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct s{

    int st , en , idx;
    s(int _st , int _en , int _idx){

        st = _st;
        en = _en;
        idx = _idx;
    }
};

bool cmp(s A , s B)
{
    return abs(A.en-A.st) < abs(B.en-B.st);
}

int n;
vector<s>v;
int dp[505][505];

int f(int now , int last)
{
    if(now==n)return 0;
    if(dp[now][last]!=-1)return dp[now][last];

    int value = f(now+1 , last);

    if(last==504)value = max(value , f(now+1 , now)+1);
    else{

        if(v[now].st<v[last].st&&v[now].en>v[last].en){

            value = max(value , f(now+1 , now)+1);
        }
    }

    return dp[now][last] = value;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++){

        int in1 , in2;
        cin >> in1 >> in2;
        v.push_back(s(in1 , in2 , i));
    }

    sort(v.begin() , v.end() , cmp);

    memset(dp , -1 , sizeof(dp));
    int ans = f(0 , 504);
    cout << ans << endl;

    vector<int>store;

    int temp = 0 , last = -1 , t;

    for(int i=0;i<n;i++){

        t = 100000000;

        if(last==-1)t = f(i+1 , i) + 1;
        else{

            if(v[i].st<v[last].st&&v[i].en>v[last].en)t = f(i+1 , i) + 1;
        }

        if(t+temp==ans){

            last = i;
            temp++;
            store.push_back(v[i].idx+1);
        }
    }

    for(int i=0;i<store.size();i++){

        if(i>0)cout << " ";
        cout << store[i];
    }
    cout << endl;

    return 0;
}
