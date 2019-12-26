// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int a[5];
int n;
bool taken[10] , found;

void print(int x , bool check)
{

    if(x%n!=0)return;

    int y = x/n;

    int ar[10] , c = 0;

    memset(ar , 0 , sizeof(ar));

    int y_temp = y;
    int x_temp = x;
    int t = 5;
    while(t--){

        //cout << y%10 << endl;
        ar[y%10]++;
        y/=10;
        if(y!=0)c++;
    }
    t = 5;
    while(t--){

        //cout << x%10 << endl;
        ar[x%10]++;
        x/=10;
    }

    for(int i=0;i<=9;i++){

        //cout << i << " " << ar[i] << endl;
        if(ar[i]>1)return;
    }

    if(check==true)cout << "0";
    cout << x_temp;
    //cout << c << endl;
    if(c==3){

        cout << " / 0" << y_temp;
    }

    else cout << " / " << y_temp;

    cout << " = " << n << endl;

    found = true;
}

void f(int idx)
{

    if(idx==5){

        int num = 0;

        for(int i=0;i<5;i++){

            num+=a[i];
            num*=10;
        }

        num/=10;

        //cout << num << endl;

        if(a[0]==0)print(num , true);

        else print(num , false);

        return;
    }

    if(idx>=5)return;

    for(int i=0;i<=9;i++){

        if(taken[i]==false){

            taken[i] = true;

            a[idx] = i;

            f(idx+1);

            taken[i] = false;
        }
    }
}

int main(void)
{

    //n = 62;
    //print(7936 , true);
    bool space = false;
    while(cin >> n){

        if(!n)break;
        if(space)cout << endl;
        space = true;
        found = false;
        memset(taken , false ,sizeof(taken));
        f(0);

        if(found==false)cout << "There are no solutions for " << n << "." << endl;
    }

    return 0;
}
