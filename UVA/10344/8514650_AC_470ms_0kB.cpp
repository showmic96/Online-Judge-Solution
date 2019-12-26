// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

bool check;
int a[5];
bool taken[5];

void f(int value , int i)
{
    //cout << value << endl;
    if(i==5){

        if(value==23)check=true;
        return ;
    }

    for(int j=0;j<5;j++){

            if(taken[j]==false){

                taken[j] = true;

                f(value + a[j] , i+1);
                f(value - a[j] , i+1);
                f(value * a[j] , i+1);

                taken[j] = false;
            }
        }

    return ;
}

int main(void)
{

    while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4]){

        if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0)break;

        memset(taken , false , sizeof(taken));

        check = false;

        for(int i=0;i<5;i++){

            if(taken[i]==false){

                taken[i] = true;

                f(a[i] , 1);

                taken[i] = false;
            }
        }

        if(check==false){

            cout << "Impossible" << endl;
        }

        else cout << "Possible" << endl;
    }
    return 0;
}
