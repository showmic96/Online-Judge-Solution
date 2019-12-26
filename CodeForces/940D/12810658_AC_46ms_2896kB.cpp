// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int>v;
    string ar;

    for(int i=0;i<n;i++){

        int in;
        cin >> in;
        v.push_back(in);
    }

    cin >> ar;

    int l = -1e9 , r = 1e9;

    for(int i=4;i<n;i++){

        if(ar[i]=='0'){

            if(ar[i-1]=='0'){

            }

            else{

                int mi = min(v[i] , min(v[i-1] , min(v[i-2] , min(v[i-3] , v[i-4]))));
                if(r>=mi)r = mi-1;
            }
        }

        else{

            if(ar[i-1]=='1'){

                //int mi = min(v[i] , min(v[i-1] , min(v[i-2] , min(v[i-3] , v[i-4]))));
            }

            else{

                int mx = max(v[i] , max(v[i-1] , max(v[i-2] , max(v[i-3] , v[i-4]))));
                if(l<=mx)l = mx+1;
            }
        }
    }

    cout << l << " " << r << endl;

    return 0;
}
