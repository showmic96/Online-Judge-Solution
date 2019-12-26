// In the name of Allah the most Merciful.

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int a[6] , tower1 , tower2;
    for(int i=0;i<6;i++)cin >> a[i];
    cin >> tower1 >> tower2;

    int i , j , k;
    bool check = false;

    for(i=0;i<6;i++){

        for(j=i+1;j<6;j++){

            for(k = j+1;k<6;k++){

                if(a[i]+a[j]+a[k]==tower1){

                    if(a[i]!=a[j]){

                        if(a[i]!=a[k]){

                            if(a[j]!=a[k]){check=true;break;}
                        }
                    }
                }
            }
            if(check==true)break;
        }
        if(check==true)break;
    }
    check=false;
    int b[3] , c[3];
    b[0] = a[i];
    b[1] = a[j];
    b[2] = a[k];

    a[i] = 0;
    a[j] = 0;
    a[k] = 0;

    for(i=0;i<6;i++){

        for(j=i+1;j<6;j++){

            for(k = j+1;k<6;k++){

                if(a[i]+a[j]+a[k]==tower2){

                    if(a[i]!=a[j]){

                        if(a[i]!=a[k]){

                            if(a[j]!=a[k]){check=true;break;}
                        }
                    }
                }
            }

            if(check==true)break;
        }

        if(check==true)break;
    }

    c[0] = a[i];
    c[1] = a[j];
    c[2] = a[k];

    sort(b , b+3);
    sort(c , c+3);

    cout << b[2] << " " << b[1] << " " << b[0] << " " << c[2] << " " << c[1] << " " << c[0] << endl;

    return 0;
}
