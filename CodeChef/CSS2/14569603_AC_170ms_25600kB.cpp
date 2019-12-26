#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct s{

    ll val , pr , idx;
    s(ll _val , ll _pr , ll _idx){

        val = _val;
        pr = _pr;
        idx = _idx;
    }
};

bool cmp(s A , s B)
{
    if(A.pr==B.pr)return A.idx>B.idx;
    return A.pr>B.pr;
}

map<pair<int , int> , int>mp;
vector<s>v[100005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , m , c = 1;
    cin >> n >> m;

    for(int i=0;i<n;i++){

        ll in1 , in2 , in3 , in4;
        cin >> in1 >> in2 >> in3 >> in4;

        if(mp.find(make_pair(in1 , in2))==mp.end()){

            mp[make_pair(in1 , in2)] = c;
            c++;
        }

        v[mp[make_pair(in1 , in2)]].push_back(s(in3 , in4 , i));
    }

    for(int i=0;i<c;i++){

        sort(v[i].begin() , v[i].end() , cmp);
    }

    while(m--){

        int in1 , in2;
        cin >> in1 >> in2;

        cout << v[mp[make_pair(in1 , in2)]][0].val << endl;
    }

    return 0;
}
