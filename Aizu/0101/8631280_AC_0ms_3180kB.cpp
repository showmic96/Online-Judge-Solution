// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    scanf("\n");

    while(t--){

        string ar;
        getline(cin , ar);

        int si = ar.size();

        for(int i=0;i<si-6;i++){

            string temp = "";
            temp+=ar[i];
            temp+=ar[i+1];
            temp+=ar[i+2];
            temp+=ar[i+3];
            temp+=ar[i+4];
            temp+=ar[i+5];
            temp+=ar[i+6];

            if(temp=="Hoshino"){
                ar[i+6]='a';
            }
        }

        cout << ar << endl;

    }
    return 0;
}
