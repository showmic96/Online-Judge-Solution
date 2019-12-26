#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9 , MAX = 100010;
typedef long long ll;
typedef unsigned long long LL;



int main(void)
{
    string ar;

    double ans = 0 , ans_temp = 0;

    char x;

    ll hour , miniute, sec , speed=0 , hour_temp=0 , miniute_temp=0 , sec_temp=0 , hour_temp2=0 , miniute_temp2=0 , sec_temp2=0;

   /* getline(cin , ar);

    stringstream s(ar);

    s >> hour_temp >> x >> miniute_temp >> x >> sec_temp >> speed;

    //cout << hour_temp << " " << miniute_temp << " " << sec_temp << " " << speed << endl;
*/
    while(getline(cin,ar)){

        stringstream ss(ar);

        ss >> hour >> x >> miniute >> x >> sec;



        hour_temp2 = hour;
        miniute_temp2 = miniute;
        sec_temp2 = sec;

        if(miniute<miniute_temp){ miniute = (60-miniute_temp+miniute);hour--;}
        else miniute = miniute - miniute_temp;


        if(sec<sec_temp){sec =(60-sec_temp+sec);miniute--;}
        else sec = sec-sec_temp;

        hour = hour-hour_temp;

        ans+=((double)((hour*3600.00+miniute*60.00+sec)/3600 * speed)*1.00);

        hour_temp = hour_temp2;
        miniute_temp = miniute_temp2;
        sec_temp = sec_temp2;

        if(ar[ar.size()-3]!=':'){

            ss >> speed;


        }


        if(ar[ar.size()-3]==':') {

            cout << ar;
            printf(" %.2lf km\n",ans);

        }


    }


    return 0;
}
