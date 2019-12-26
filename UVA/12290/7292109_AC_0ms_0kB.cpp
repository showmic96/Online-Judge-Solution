#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isSeven(int a)
{
    bool check=false;
    while(a!=0){

        if(a%10==7)check=true;
        a/=10;
    }

    return check;
}

int main(void)
{
    int a, b , c;

    while(cin >> a >> b >> c){

        if(!a&&!b&&!c)break;

        int d = 1 , counter = 0 , person = 1;

        bool check = false;

        while(true){

            if(person==b&&(d%7==0||isSeven(d)==true))counter++;
            if(counter==c)break;

            if(check==false)person++;
            if(check==true)person--;
            d++;
            if(person==a+1){person=a-1;check=true;}
            if(person==0){person=2;check=false;}
        }

        cout << d << endl;
    }

    return 0;
}
