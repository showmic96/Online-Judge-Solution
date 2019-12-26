#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n , k , s;
    cin >> n >> k >> s;

    vector<int>v;

    for(int i=0;i<n;i++){

        int in;
        cin >> in;
        v.push_back(in);
    }
    sort(v.begin() , v.end());
    reverse(v.begin() , v.end());
    int counter = 0 , now = 0;
    for(int i=0;i<n;i++){

        counter++;
        now+=v[i];
        if(now>=k*s)break;
    }
    cout << counter << endl;
    return 0;
}

