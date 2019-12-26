// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int ar[][12] = {{31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31},{31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31}};

bool leap_year(int x)
{
    if(x%400==0)return true;
    if(x%100!=0&&x%4==0)return true;
    return false;
}

void get(int d , int m , int y)
{
    if(m==1){

        if(d>=21)cout << "aquarius" << endl;
        else cout << "capricorn" << endl;
    }
    else if(m==2){

        if(d>=20)cout << "pisces" << endl;
        else cout << "aquarius" << endl;
    }
    else if(m==3){

        if(d>=21)cout << "aries" << endl;
        else cout << "pisces" << endl;
    }
    else if(m==4){

        if(d>=21)cout << "taurus" << endl;
        else cout << "aries" << endl;
    }
    else if(m==5){

        if(d>=22)cout << "gemini" << endl;
        else cout << "taurus" << endl;
    }
    else if(m==6){

        if(d>=22)cout << "cancer" << endl;
        else cout << "gemini" << endl;
    }
    else if(m==7){

        if(d>=23)cout << "leo" << endl;
        else cout << "cancer" << endl;
    }
    else if(m==8){
        if(d>=22)cout << "virgo" << endl;
        else cout << "leo" << endl;
    }
    else if(m==9){
        if(d>=24)cout << "libra" << endl;
        else cout << "virgo" << endl;
    }
    else if(m==10){
        if(d>=24)cout << "scorpio" << endl;
        else cout << "libra" << endl;
    }
    else if(m==11){
        if(d>=23)cout << "sagittarius" << endl;
        else cout << "scorpio" << endl;
    }
    else if(m==12){
        if(d>=23)cout << "capricorn" << endl;
        else cout << "sagittarius" << endl;
    }
}

int main(void)
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);

    int t , c = 0;
    cin >> t;
    while(t--){

        string in;
        cin >> in;

        int m = (in[0]-'0')*10+in[1]-'0';
        int d = (in[2]-'0')*10+in[3]-'0';
        int y = (in[4]-'0')*1000+(in[5]-'0')*100+(in[6]-'0')*10+(in[7]-'0');

        for(int i=0;i<40*7;i++){

            if(leap_year(y)==true){

                if(d==ar[1][m-1]){

                    d = 1;
                    m++;

                    if(m==13){

                        m = 1;
                        y++;
                    }
                }
                else d++;
            }
            else{

                if(d==ar[0][m-1]){

                    d = 1;
                    m++;

                    if(m==13){

                        m = 1;
                        y++;
                    }
                }
                else d++;
            }
        }

        printf("%d %02d/%02d/%04d ",++c , m , d , y);
        get(d , m , y);
    }

    return 0;
}
