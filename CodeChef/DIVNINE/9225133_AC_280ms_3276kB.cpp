// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long t;
    cin >> t;
    while(t--){

        string ar;
        long long sum = 0;
        cin >> ar;
        int si = ar.size();

        for(int i=0;i<si;i++){

            sum+= ar[i] - '0';
        }

        sum%=9;
        int temp = sum , ans = 1234;
        bool check1 = false , check2 = false;

        for(int i=0;i<si;i++){

            if(i==0){

                while(ar[i]-'0'!=1){

                    temp--;
                    ar[i]--;
                }

                if(temp<=0)check1=true;
            }
            else{

                while(ar[i]-'0'!=0){

                    temp--;
                    ar[i]--;
                }

                if(temp<=0)check1=true;
            }

            if(check1==true)break;
        }

        temp = sum;

        for(int i=0;i<si;i++){

            while(ar[i]-'0'!=9){

                temp++;
                ar[i]++;
            }

            if(temp>=9){check2=true;break;}
        }

        if(ar.size()==1)cout << min(sum , 9-sum) << endl;
        else if(check1==true&&check2==true)cout << min(sum , 9-sum) << endl;
        else if(check1==true)cout << sum << endl;
        else cout << 9-sum << endl;
    }

    return 0;
}
