// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string ar;
int counter = 0;

void f(int i , string s)
{
    if(counter==2)return ;
    if(i==n){

        counter++;
        return ;
    }
    if(ar[i]!='?'){

        if(i!=0){

            if(ar[i]==s[i-1])return ;
        }
        string temp = s;
        temp+=ar[i];
        f(i+1 , temp);
    }

    else{


        if(i==0){

            string temp = s;
            temp+='C';

            f(i+1 , temp);

            temp = s;
            temp+='M';

            f(i+1 , temp);

            temp = s;
            temp+='Y';

            f(i+1 , temp);

            return ;
        }

        if(i+1<n)if(ar[i-1]=='?'&&ar[i+1]=='?'){

            counter = 2;
            return ;
        }

        if(s[i-1]=='Y'){

            string temp = s;
            temp+='C';

            f(i+1 , temp);

            temp = s;
            temp+='M';

            f(i+1 , temp);
        }

        if(s[i-1]=='M'){

            string temp = s;
            temp+='C';

            f(i+1 , temp);

            temp = s;
            temp+='Y';

            f(i+1 , temp);
        }

        if(s[i-1]=='C'){

            string temp = s;
            temp+='Y';

            f(i+1 , temp);

            temp = s;
            temp+='M';

            f(i+1 , temp);
        }
    }
}

int main(void)
{
    cin >> n >> ar;

    f(0 , "");

    bool check = true;

    for(int i=1;i<n;i++){

        if(ar[i]==ar[i-1]&&ar[i]!='?')check = false;
    }

    if(counter==2&&check)cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
