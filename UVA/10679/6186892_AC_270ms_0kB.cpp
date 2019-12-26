#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a;
    cin >> a;
    while(a--){
        scanf("\n");
        string ar;
        getline(cin,ar);
        int i = ar.size();

        scanf("\n");

        int b;
        cin >> b;
        while(b--){

            scanf("\n");
            string br;
            getline(cin , br);
            int j = br.size();
            bool yes = true;

            if(j>i){cout << "n" << endl; continue;}

            for(int h=0;h<j;h++){

                if(ar[h]!=br[h]){yes = false; break;}
            }
            if(yes==true)cout << "y" << endl;
            else cout << "n" << endl;


        }
    }
    return 0;
}
