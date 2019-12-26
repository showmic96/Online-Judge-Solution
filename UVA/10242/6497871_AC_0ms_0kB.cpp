#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    double a1 , a2 , b1 , b2 , c1 , c2 , d1 ,d2;

    while(cin  >> a1 >> a2 >> b1 >> b2 >> c1 >> c2 >> d1 >> d2){

        if(a1==b1&&a2==b2){

            if(c1==a1){
                a1 = d1-a1+c1;
                a2 = d2-a2+c2;
            }

            else{
                a1 = c1-a1+d1;
                a2 = c2-a2+d2;
            }
        }

        else if(a1==c1&&a2==c2){
                if(a1==b1){

                    a1 = d1-a1+b1;
                    a2 = d2-a2+b2;

                }

                else{

                    a1 = b1-a1+d1;
                    a2 = b2-a2+d2;

                }
        }

        else if(a1==d1&&a2==d2){
                if(a1==c1){

                    a1 = b1-a1+c1;
                    a2 = b2-a2+c2;
                }
                else{

                    a1 = c1-a1+b1;
                    a2 = c2-a2+b2;
                }
        }

        else if(b1==c1&&b2==c2){

                if(b1==a1){
                    a1 = d1-b1+a1;
                    a2 = d2-b2+a2;
                }

                else{
                    a1 = a1-b1+d1;
                    a2 = a2-b2+d2;
                }
        }
        else if(b1==d1&&b2==d2){
                if(b1==c1){
                    a1 = a1-b1+c1;
                    a2 = a2-b2+c2;
                }

                else{
                    a1 = c1-b1+a1;
                    a2 = c2-b2+a2;
                }
        }

        else if(c1==d1&&c2==d2){
                if(c1==a1){
                    a1 = b1-c1+a1;
                    a2 = b2-c2+a2;
                }

                else{
                    a1 = a1-c1+b1;
                    a2 = a2-c2+b2;
                }
        }

        printf("%.3f %.3f\n",a1,a2);

    }

    return 0;
}
