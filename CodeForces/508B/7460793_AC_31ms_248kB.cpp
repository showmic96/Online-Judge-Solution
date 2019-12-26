// In the name of Allah the Lord of the worlds .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isEven(char x)
{
    if(x=='0')return true;
    if(x=='2')return true;
    if(x=='4')return true;
    if(x=='6')return true;
    if(x=='8')return true;

    return false;

}

int main(void)
{
    string ar;
    cin >> ar;

    bool isThere = false;

    int si = ar.size();

    for(int i=0;i<si;i++){

        if(ar[i]=='0')isThere = true;
        if(ar[i]=='2')isThere = true;
        if(ar[i]=='4')isThere = true;
        if(ar[i]=='6')isThere = true;
        if(ar[i]=='8')isThere = true;
    }

    if(isThere==false){cout << -1 << endl;return 0;}

    if(isEven(ar[si-1])==true){

        for(int i=0;i<si-1;i++){

            int d = i+1;

            while(ar[i]<=ar[d]){d++;if(d==si-1)break;}

            if(d!=si-1){swap(ar[i],ar[d]);break;}


        }

        cout << ar << endl;

    }

    else{

        bool check = false;
        int d = si-1;

        for(int i=0;i<si;i++){

            if(isEven(ar[i])==true&&ar[i]<ar[si-1]){swap(ar[i], ar[si-1]);check = true;}
            if(check==true)break;
        }

        if(check==false){

            while(isEven(ar[d])==false)d--;

            swap(ar[d], ar[si-1]);
        }

        cout << ar << endl;
    }

    return 0;
}
