// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n, m , in , sum = 0;
    cin >> n >> m;
    vector<int>value;
    for(int i=0;i<n;i++){
        cin >> in;
        value.push_back(in);
    }

    sort(value.begin() , value.end());

    for(int i=0;i<m;i++){
        
        if(value[i]>=0)break;
        sum+=value[i];
    }

    cout << -sum << endl;

    return 0;
}
