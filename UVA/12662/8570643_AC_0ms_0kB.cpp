// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    string ar[n+10];
    int si = n;
    for(int i=0;i<n;i++)cin >> ar[i];

    int q;
    cin >> q;

    while(q--){

        int in;
        cin >> in;

        in--;
        int d = in , l = 0 , r = 0;
        string l_c , r_c;

        if(ar[in]!="?"){cout << ar[in] << endl;continue;}

        while(ar[d]=="?"){

            d++;
            r++;
            if(d==si)break;
        }

        if(d==si)r = 1e9;
        else r_c = ar[d];

        d = in;

        while(ar[d]=="?"){

            d--;
            l++;
            if(d==-1)break;
        }

        if(d==-1)l=1e9;
        else l_c = ar[d];

        if(l==r)cout << "middle of "<< l_c << " and " << r_c << endl;
        else if(l>r){

            for(int i=0;i<r;i++)cout << "left of ";
            cout << r_c << endl;
        }

        else{

            for(int i=0;i<l;i++)cout << "right of ";
            cout << l_c << endl;
        }
    }

    return 0;
}
