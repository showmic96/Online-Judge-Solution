#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++){

        ll in;
        cin >> in;

        ll tax_counter = 0;

        if(in>180000){

            in-=180000;
        }

        else in=0;

        if(in>300000){

            in-=300000;
            tax_counter+=30000;
        }

        else if(in>0){

            //cout << "YES" << endl;
            tax_counter+= (double)(ceil)(1.00*.10*in);
            in = 0;
        }

        if(in>400000){

            in-=400000;
            tax_counter+= (double)(ceil)(1.00*.15*400000);
        }

        else if(in>0){

            tax_counter+= (double)(ceil)(1.00*.15*in);
            in = 0;
        }

        if(in>300000){

            in-=300000;
            tax_counter+=60000;
        }

        else if(in>0){

            tax_counter+= (double)(ceil)(1.00*.20*in);
            in = 0;
        }

        if(in>0){

            tax_counter+= (double)(ceil)(1.00*.25*in);
        }

        if(tax_counter>0&&tax_counter<2000)tax_counter = 2000;

        printf("Case %d: ",i+1);
        cout << tax_counter << endl;

    }
    return 0;
}
