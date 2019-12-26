// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

typedef long long ll;
ll in;

void do_the_work(int lim)
{
    int one = 0;

    for(int i=0;i<lim;i++){

        if(check(in , i)==true)one++;
    }

    for(int i=0;i<lim;i++){

        if(one>0){in = Set(in , i);one--;}
        else in = reset(in , i);
    }
}

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){

        ll lim = 0;

        scanf("%lld",&in);

        for(int j=0;j<32;j++){

            if(check(in , j)==true)lim = j;
        }

        bool ch = true;
        int zero = -1;
        int one = -1;


        for(int j=0;j<lim;j++){

            if(check(in , j)==false){

                if(j!=0){

                    if(check(in , j-1)==false)continue;
                    zero = j;
                    one = j-1;
                    break;
                }
            }
        }

        //cout << one  << " " << zero  << endl;

        if(zero==-1||one==-1)ch = false;

        else{

            in = Set(in , zero);
            in = reset(in , one);
            do_the_work(zero);
        }

        if(ch==false){

            //cout << "YES" << endl;
            in = in << 1 ;

            ch = false;
            zero = -1;
            one = -1;
/*
            for(int j=0;j<=lim;j++){

                if(check(in , j)==true){

                    one = j;
                }
            }
*/
            //cout << one  << " " << lim  << endl;

            //in = Set(in , 0);
            //in = reset(in , one);
            do_the_work(lim+1);

        }

        printf("Case %d: %lld\n",i+1,in);

    }
    return 0;
}
