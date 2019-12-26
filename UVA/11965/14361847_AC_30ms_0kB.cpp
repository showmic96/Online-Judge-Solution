// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t , c = 0;
    cin >> t;
    while(t--){

        int n;
        cin >> n;
        cin.ignore();
        
        if(c>0)cout << endl;
        cout << "Case " << ++c << ":" << endl;
        while(n--){

            string ar , temp = "";
            getline(cin , ar);
            bool check = false;

            for(int i=0;i<ar.size();i++){

                if(ar[i]==' '){

                    if(check==false)temp+=" ";
                    check = true;
                }
                else{

                    check = false;
                    temp+=ar[i];
                }
            }
            cout << temp << endl;
        }
    }

    return 0;
}
