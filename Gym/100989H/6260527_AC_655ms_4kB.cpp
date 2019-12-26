#include<stdio.h>
#include<iostream>

using namespace std;

int main(void)
{
    long long int a;
    cin >> a;
    long long note_1=0 , note_5=0 , note_10=0,note_20=0 , note_50=0 , k=0;
    long long int note1 , note5 , note10 , note20 , note50 , k1;
    bool check = true;
    long long int ar[a];
    for(long long int b=0;b<a;b++){

        cin >> k1 >> note1 >> note5 >> note10 >> note20 >> note50;
        //k+=k1;
        note_1+=note1;
        note_5+=note5;
        note_10+=note10;
        note_20+=note20;
        note_50+=note50;
        k=(note1*1+note5*5+note10*10+note20*20+note50*50)-k1;

        while(k>=50&&note_50>0){

            note_50--;
            k-=50;
        }
        while(k>=20&&note_20>0){

            note_20--;
            k-=20;
        }
        while(k>=10&&note_10>0){

            note_10--;
            k-=10;
        }
        while(k>=5&&note_5>0){

            note_5--;
            k-=5;
        }
        while(k>=1&&note_1>0){

            note_1--;
            k-=1;
            //cout << note_1 << endl;
        }
        if(k>0)check=false;


    }





    if(check==false)cout << "no" << endl;
    else cout << "yes" << endl;
    return 0;
}
