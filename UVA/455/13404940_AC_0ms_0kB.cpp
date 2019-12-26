// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

bool check(string ar , string br)
{
    for(int i=0;i<ar.size();i++){

        if(ar[i]!=br[(i%br.size())])return false;
    }

    return true;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    bool blank = false;

    while(t--){

        if(blank)cout << endl;blank = true;

        string ar;
        cin >> ar;

        int mi = 1e9;

        for(int i=0;i<ar.size();i++){

            string br = "";
            for(int j=i;j<ar.size();j++){

                br+=ar[j];

                if(ar.size()%br.size()==0){

                    if(check(ar , br)==true){

                        mi = min(mi , (int)br.size());
                    }
                }
            }
        }

        cout << mi << endl;
    }

    return 0;
}
