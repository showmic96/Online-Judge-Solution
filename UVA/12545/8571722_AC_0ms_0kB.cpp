// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    for(int l=0;l<t;l++){

        string ar , br;
        cin >> ar >> br;

        int si = ar.size();
        int counter = 0 , t_one = 0 , s_one = 0 , t_zero = 0 , s_zero = 0;

        for(int i=0;i<si;i++){

            if(ar[i]=='1')s_one++;
            if(br[i]=='1')t_one++;
            if(ar[i]=='0')s_zero++;
            if(br[i]=='0')t_zero++;
        }

        for(int i=0;i<si;i++){

            if(ar[i]=='?'){

                counter++;

                if(s_zero==t_zero){

                    s_one++;
                    ar[i] = '1';
                    continue;
                }

                else if(s_one==t_one){

                    s_zero++;
                    ar[i]='0';
                    continue;
                }

                if(br[i]=='1'){

                    ar[i] = '1';
                    s_one++;
                }

                if(br[i]=='0'){

                    s_zero++;
                    ar[i] = '0';
                }
            }
        }

        for(int i=0;i<si;i++){

            if(s_one==t_one)break;

            if(ar[i]=='0'&&br[i]=='1'){

                s_zero--;
                s_one++;

                ar[i] = '1';
                counter++;
            }
        }

        //cout << ar << endl << br << endl;

        int temp = 0;

        for(int i=0;i<si;i++){

            if(ar[i]!=br[i])temp++;
        }

        counter+= (temp/2);

        if(s_one > t_one)counter = -1;

        printf("Case %d: ",l+1);
        cout << counter << endl;
    }
    return 0;
}
