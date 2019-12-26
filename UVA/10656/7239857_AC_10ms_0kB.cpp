#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a , b;
    vector<int>in;

    while(cin >> a){

        if(!a)break;
        in.clear();

        while(a--){

            cin >> b;
            if(b>0)in.push_back(b);
        }
        int si = in.size();
        if(si==0){cout << 0 << endl;continue;}
        cout << in[0];
        for(int i=1;i<si;i++)cout << " " << in[i];
        cout << endl;
    }

    return 0;
}
