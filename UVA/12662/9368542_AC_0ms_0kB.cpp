// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

string ar[111];

int main(void)
{
    int n;
    cin >> n;

    for(int i=0;i<n;i++)cin >> ar[i];

    int q;
    cin >> q;

    while(q--){

        int in;
        cin >> in;

        int d = in-1 , l = 0 , r = 0;
        string ls , rs;

        if(ar[in-1]!="?"){

            cout << ar[in-1] << endl;
            continue;
        }

        while(ar[d]=="?"){

            d++;
            r++;
            if(d==n)break;
        }

        if(d==n)r = 1e9;
        else rs = ar[d];

        d = in-1;

        while(ar[d]=="?"){

            d--;
            l++;
            if(d==-1)break;
        }

        if(d==-1)l=1e9;
        else ls = ar[d];

        if(l==r)cout << "middle of "<< ls << " and " << rs << endl;
        else if(l>r){

            for(int i=0;i<r;i++)cout << "left of ";
            cout << rs << endl;
        }

        else{

            for(int i=0;i<l;i++)cout << "right of ";
            cout << ls << endl;
        }
    }

    return 0;
}
