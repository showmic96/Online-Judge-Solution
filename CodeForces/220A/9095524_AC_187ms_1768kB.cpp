// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int>v1 , v2;
    for(int i=0;i<n;i++){

        int in;
        cin >> in;
        v1.push_back(in);
        v2.push_back(in);
    }

    sort(v2.begin() , v2.end());
    int counter = 0;

    for(int i=0;i<n;i++){

        if(v1[i]!=v2[i])counter++;
    }

    if(counter<=2)cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
