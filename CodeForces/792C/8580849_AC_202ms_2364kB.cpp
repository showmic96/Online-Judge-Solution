// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int find_out(string ar , int v1 , int t1 , int v2 , int t2)
{
    string br = "";

    int si = ar.size();

    bool print = false;

    for(int i=si-1;i>=0;i--){

            int temp = ar[i]-'0';

            if(temp==v1){

                if(t1>0){
                    t1--;
                    continue;
                }
            }

            if(temp==v2){

                if(t2>0){

                    t2--;
                    continue;
                }
            }

            if(print==false&&ar[i]=='0')continue;

            br+=ar[i];

            print = true;
        }

        reverse(br.begin() , br.end());
        int counter = 0;
        bool zero = true;

        si = br.size();

        for(int i=0;i<si;i++){

            if(br[i]!='0')zero = false;

            if(zero==false)counter++;
        }

        //cout << br  << " " << counter << endl;

        return counter;
}

int main(void)
{
    int a[10];
    string ar;
    cin >> ar;

    memset(a , 0 , sizeof(a));

    int si = ar.size();
    int sum = 0;
    bool zero = false;

    for(int i=0;i<si;i++){

        int temp = ar[i]-'0';

        sum+=temp;

        a[temp]++;

        if(temp==0)zero = true;
    }

    int need = sum%3;

    int mx = 0 , v1 = -1 , t1 , v2 = -1 , t2;

    if(need==0)cout << ar << endl;
    else{

        for(int i=0;i<5;i++){

            for(int j=0;j<5;j++){

                for(int k=1;k<10;k++){

                    for(int l=k;l<10;l++){

                        if((i*k+j*l)%3==need){

                            if(k==l)if(a[k]<i+j)continue;
                            if(a[k]<i||a[l]<j)continue;

                            int f = find_out(ar , k , i , l , j);

                            if(f >= mx){

                                mx = f;
                                v1 = k;
                                t1 = i;
                                v2 = l;
                                t2 = j;
                            }
                        }
                    }
                }
            }
        }

        bool print = false;
//cout << v1 << " " << t1 << " " << v2 << " " << t2 << endl;
        string br = "";

        for(int i=si-1;i>=0;i--){

            int temp = ar[i]-'0';

            if(temp==v1){

                if(t1>0){
                    t1--;
                    continue;
                }
            }

            if(temp==v2){

                if(t2>0){

                    t2--;
                    continue;
                }
            }

            br+=ar[i];
        }

        int si = br.size();
        reverse(br.begin() , br.end());

        for(int i=0;i<si;i++){

            if(br[i]!='0')print = true;
            if(print==true)cout << br[i];
        }

        if(zero==true&&print==false)cout << 0;
        else if(print==false&&zero==false)cout << -1;
        //else cout << br;
        cout << endl;
    }

    return 0;
}
