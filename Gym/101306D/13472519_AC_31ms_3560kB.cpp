// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

string ar = "CARScarsIuVEJxTXsUvOHhngyZKfAYmaqolMNtGQibwdjPrCpekFWzLaySBaPybRMgzYMynYD";
string br = "UnilEPFLvpVZzBNtLSCubWmaocIYneAPqxDshRkMGgJfHrFUQTjXOwdPolyProgisawesomeK";

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i=0;i<n;i++){

        string in;
        cin >> in;
        if(i>0)cout << " ";

        for(int j=0;j<in.size();j++){

            for(int i1=0;i1<ar.size();i1++){

                if(in[j]==ar[i1]){

                    cout << br[i1];
                    break;
                }
            }
        }
    }

    cout << endl;

    return 0;
}
