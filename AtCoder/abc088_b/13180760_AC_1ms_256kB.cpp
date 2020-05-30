// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    vector<int>v;
    cin >> n;
    for(int i=0;i<n;i++){

        int in;
        scanf("%d",&in);
        v.push_back(in);
    }

    sort(v.begin() , v.end());

    int sum = 0;
    int c = 0;
    for(int i=n-1;i>=0;i--){

        if(c%2)sum-=v[i];
        else sum+=v[i];
        c++;
    }

    cout << sum << endl;

    return 0;
}
