#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a;
    while(cin >> a){

        if(!a) break;
        bool check =false;
        int ar[a];

        for(int b=0;b<a;b++)ar[b]=0;

        int colom_counter=0 , row_counter=0 , colom_position , row_position;
        int sum , in;
        for(int b=0;b<a;b++){

            sum =0;

            for(int c=0;c<a;c++){

                cin >> in;
                sum+=in;
                ar[c]+=in;
            }
            if(sum%2!=0){colom_counter++;colom_position=b;}
        }


        for(int b=0;b<a;b++){

            sum =0;


            if(ar[b]%2!=0){row_counter++;row_position=b;}
        }

        if(row_counter==0&&colom_counter==0)cout << "OK" << endl;
        else if(row_counter==1&&colom_counter==1)cout << "Change bit (" << colom_position+1 << "," << row_position+1 << ")" << endl;
        else cout << "Corrupt" << endl;


    }
    return 0;
}
