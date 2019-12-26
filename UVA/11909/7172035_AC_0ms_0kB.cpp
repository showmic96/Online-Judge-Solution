#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    double l , w , h  , thita , h_temp , area , area_full;

    double pi = acos(-1);

    while(cin >> l >> w >> h >> thita){

        thita = thita*pi/180;

        //cout << thita << endl;

        h_temp = l*tan(thita);

        //cout << h_temp << endl;

        if(h_temp>h){

            thita = pi/2 - thita;

           // cout << thita << endl;

            h_temp = h*tan(thita);
            area = 0.5*h*w*h_temp;
            printf("%.3lf mL\n",area);
            continue;
        }

        area_full = l*w*h;
        area = 0.5*l*h_temp*w;

        //cout << area_full << " " << area << endl;

        printf("%.3lf mL\n",area_full - area);

    }

    return 0;
}
