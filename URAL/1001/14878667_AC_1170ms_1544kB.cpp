// In the name of Allah the Lord of the Worlds. 

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    double n;
    vector<double>v;
    while(cin >> n){
        v.push_back(sqrt(n));
    }
    for(int i=v.size()-1;i>=0;i--)cout << setprecision(4) << fixed << v[i] << endl;
    return 0;
}