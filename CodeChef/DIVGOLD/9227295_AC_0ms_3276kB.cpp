// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

string change(string ar , char x , char y)
{
    int si = ar.size();
    bool check = false;

    for(int i=si-1;i>=1;i--){

        if(ar[i]==x){

            check=true;
        }

        if(check==true){

            ar[i] = ar[i-1];
        }
    }

    return ar;
}

int main(void)
{
    int t;
    cin >> t;
    while(t--){

        int si;
        string ar , br , s1="" , s2 = "" , cr;
        cin >> si >> ar;
        br = ar;
        cr = ar;

        sort(br.begin() , br.end());

        bool check = false;

        for(int i=0;i<si;i++){

            if(check==false){

                if(ar[i]!=br[i]){

                    check = true;
                    s1+=br[i];//cout << br[i];

                    ar = change(ar , br[i] , ar[i]);
                }
                else s1+=ar[i];//cout << ar[i];
            }
            else{
                s1+=ar[i];//cout << ar[i];
            }
        }

        check = false;
        char temp;

        ar = cr;

        for(int i=0;i<si;i++){

            if(check==false){

                if(ar[i]!=br[i]){

                    temp = ar[i];
                    check=true;
                }
                else s2+=ar[i];
            }

            else{

                if(ar[i]>temp&&temp!='#'){

                    s2+=temp;
                    temp = '#';
                }

                s2+=ar[i];
            }
        }

        if(temp!='#')s2+=temp;
        //cout << s1 << " " << s2 << endl;
        if(s1<s2)cout << s1 << endl;
        else cout << s2 << endl;
    }
    return 0;
}
