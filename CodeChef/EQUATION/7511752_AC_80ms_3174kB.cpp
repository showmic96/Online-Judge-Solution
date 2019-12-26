// In the name of Allah the Lord of the worlds .

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void)
{
    long long int a , b , c , d , t;

    cin >> t;

    while(t--){

        long long int counter = 0;

        cin >> a >> b >> c >> d;

        for(int i=0;i<=b;i++){

            if(i>a)break;

            for(int j=0;j<=c;j++){

                if(i+j>a)break;

                if(a-(i+j)>0){

                    counter+=min(a-(i+j),d)+1;
                }

                else if(a-(i+j)==0)counter+=1;
            }
        }

        cout << counter << endl;

    }

    return 0;
}
