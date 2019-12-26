#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll humble[6000];

void humble_generator()
{
    humble[1] = 1;

    ll humble_2 = 1 , humble_3=1 , humble_5 = 1 , humble_7=1;
    ll humble_2_temp, humble_3_temp , humble_5_temp , humble_7_temp;

    for(int i=2;i<6000;i++){

        humble_2_temp = humble[humble_2]*2;
        humble_3_temp = humble[humble_3]*3;
        humble_5_temp = humble[humble_5]*5;
        humble_7_temp = humble[humble_7]*7;

        ll temp = min(humble_7_temp,min(humble_5_temp,min(humble_2_temp,humble_3_temp)));

        humble[i]=temp;

        if(temp==humble_7_temp)humble_7++;
        if(temp==humble_5_temp)humble_5++;
        if(temp==humble_3_temp)humble_3++;
        if(temp==humble_2_temp)humble_2++;

    }
}

int main(void)
{
    humble_generator();
    int a;
    int temp;
    while(cin >> a){

        if(!a)break;

        cout << "The ";
        temp = a/10;
        if((a-1)%10==0&&(a%10!=1||temp%10!=1)||a==1)cout << a<<"st";
        else if((a-2)%10==0&&(a%10!=2||temp%10!=1)||a==2)cout << a<<"nd";
        else if((a-3)%10==0&&(a%10!=3||temp%10!=1)||a==3)cout << a<<"rd";
        else cout << a<<"th";

        cout << " humble number is " << humble[a] << "." << endl;
    }

    return 0;

}

