#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a;
    vector<double>input;

    while(cin >> a){

        input.clear();

        double temp = 0 , in;

        if(!a)break;

        for(int i=0;i<a;i++){

            cin >> in;
            temp+=in;
            input.push_back(in);

        }

        temp = 1.00*temp/a;
        double temp2;
        char ar[100];

        sprintf(ar,"%.2f",temp);

        temp2 = atof(ar);
        double sum1 = 0 , sum2 = 0;

        for(int i=0;i<a;i++){

            if(input[i]<temp2)sum1+=fabs(input[i]-temp2);
        }

        for(int i=0;i<a;i++){

            if(input[i]>temp2)sum2+=fabs(input[i]-temp2);
        }

        printf("$%.2f\n",min(sum1,sum2));

    }

    return 0;
}
