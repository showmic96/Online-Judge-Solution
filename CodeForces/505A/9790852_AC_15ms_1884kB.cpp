// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

bool palindrome(string ar)
{
    int si = ar.size();

    for(int i=0;i<si/2;i++){

        if(ar[i]!=ar[si-i-1])return false;
    }

    return true;
}

int main(void)
{
    string ar , t1 = "" , t2 = "";
    cin >> ar;
    int si = ar.size();
    bool check = false;

    for(int i=0;i<si/2;i++){

        if(ar[i]!=ar[si-i-1]){

            check=true;

            for(int j=0;j<i;j++){

                t1+=ar[j];
            }

            t1+=ar[si-i-1];

            for(int j=i;j<si;j++){

                t1+=ar[j];
            }

            for(int j=0;j<=si-i-1;j++){

                t2+=ar[j];
            }

            t2+=ar[i];

            for(int j=si-i;j<si;j++){

                t2+=ar[j];
            }

            break;
        }
    }

    //cout << t1 << " " << t2 << endl;

    if(check==false){

        if(si%2==1){

            for(int i=0;i<=si/2;i++)cout << ar[i];

            cout << ar[si/2];

            for(int i=si/2 + 1;i<si;i++)cout << ar[i];

            cout << endl;
        }
        else{

            for(int i=0;i<si/2;i++)cout << ar[i];

            cout << 'a';

            for(int i=si/2;i<si;i++)cout << ar[i];

            cout << endl;
        }
    }

    else{

        if(palindrome(t1)==true)cout << t1 << endl;
        else if(palindrome(t2)==true)cout << t2 << endl;
        else cout << "NA" << endl;
    }

    return 0;
}
