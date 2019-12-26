// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct s{
    int a , b , idx;
};
vector<s>v1 , v2;
bool cmp1(s A , s B)
{
    return A.b > B.b;
}
bool cmp2(s A , s B)
{
    return A.b < B.b;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int in1 , in2;
        cin >> in1 >> in2;
        if(in2>in1)v1.push_back({in1 , in2 , i+1});
        else v2.push_back({in1 , in2 , i+1});
    }
    sort(v1.begin() , v1.end() , cmp1);
    sort(v2.begin() , v2.end() , cmp2);
    if(v1.size()>v2.size()){
        cout << v1.size() << endl;
        for(auto it:v1)cout << it.idx << " ";
    }
    else{
        cout << v2.size() << endl;
        for(auto it:v2)cout << it.idx << " ";
    }
    return 0;
}
