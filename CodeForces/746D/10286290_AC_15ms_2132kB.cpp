// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n , k , a , b , last = 0;
    cin >> n >> k >> a >> b;

    string ar = "";

    bool check = true;

    while(n!=0){

        if(last==1){

            for(int i=0;i<k;i++){

                ar+='B';
                b--;
                n--;
                if(n==0)break;

                if(a>=b)break;

            }

            last = 2;
        }

        else if(last==2){

            for(int i=0;i<k;i++){

                ar+='G';
                a--;
                n--;
                if(n==0)break;

                if(a<=b)break;
            }

            last = 1;
        }

        else{

            if(a>b){

                for(int i=0;i<k;i++){

                    ar+='G';
                    a--;
                    n--;
                    if(n==0)break;

                    if(a<=b)break;
                }

                last = 1;
            }

            else if(a<b){

                for(int i=0;i<k;i++){

                    ar+='B';
                    b--;
                    n--;
                    if(n==0)break;

                    if(a>=b)break;
                }

                last = 2;
            }

            else{

                ar+='G';
                a--;
                n--;
                last = 1;
            }
        }
    }

    if(a<0||b<0)ar = "NO";

    cout << ar << endl;

    return 0;
}
