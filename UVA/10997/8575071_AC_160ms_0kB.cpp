// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

struct myStruct{

    double g , s , b;

}data[10101];

int main(void)
{
    int n;
    while(cin >> n){

        if(!n)break;

        map<int , string>mp;

        bool check = false;

        string ar;
        double a , b , c , total = 0;

        for(int i=1;i<=n;i++){

            cin >> ar >> a >> b >> c;

            mp[i] = ar;

            data[i].g = a;
            data[i].s = b;
            data[i].b = c;

            total+=a;
            total+=b;
            total+=c;
        }


        double lim = 1e18 , temp = 0;
        int t = 1;

        while(temp<lim){

            temp = pow(total , t);
            t++;
        }
        t+=3;

        for(int i=1;i<=110;i++){

            for(int j=1;j<=110;j++){

                for(int k=1;k<=110;k++){


                    double temp1 =  i, temp2 =  j , temp3 =  k;
                    double value = 0;
                    int pos;

                    for(int l=1;l<=n;l++){

                        temp = data[l].g*temp1 + data[l].s*temp2 + data[l].b*temp3;

                        if(temp>value){

                            value = temp;
                            pos = l;
                        }

                    }

                    if(mp[pos]=="Canada")check = true;

                    if(check==true)break;

                }

                if(check==true)break;
            }

            if(check==true)break;
        }

        if(check==true)cout << "Canada wins!" << endl;
        else cout << "Canada cannot win." << endl;
    }

    return 0;
}
