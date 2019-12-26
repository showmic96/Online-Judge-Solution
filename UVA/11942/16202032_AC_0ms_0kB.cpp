// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    cout << "Lumberjacks:" << endl;

    while(t--){

        vector<int>v , v1 , v2;

        for(int i=0;i<10;i++){

            int in;
            cin >> in;
            v.push_back(in);
        }

        v1 = v;
        v2 = v;

        sort(v1.begin() , v1.end());

        v2 = v1;
        reverse(v2.begin() , v2.end());

        bool check = false;

        bool c = true;

        for(int i=0;i<10;i++){

            if(v[i]!=v1[i])c = false;
        }

        if(c==true)check = true;

        c = true;

        for(int i=0;i<10;i++){

            if(v[i]!=v2[i])c = false;
        }

        if(c==true)check = true;

        if(check==true)cout << "Ordered" << endl;
        else cout << "Unordered" << endl;
    }

    return 0;
}
