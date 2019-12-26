// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while(t--){

        string ar;
        cin >> ar;

        int si = ar.size();
        int total = 0 , c = 1;

        for(int i=0;i<si;i++){

            if(ar[i]=='O'){

                total+=c;
                c++;
            }

            else c = 1;
        }

        cout << total << endl;
    }
    return 0;
}
