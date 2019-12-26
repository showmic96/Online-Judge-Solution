// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int ar[25*60];

void time_print(int x)
{
    int h = x/60;
    int m = x%60;
    if(h<10)cout << 0;
    cout << h << ":";
    if(m<10)cout << 0;
    cout << m;
}

void print(int x)
{
    int h = x/60;
    int m = x%60;

    if(h>0)cout << h << " hours and ";
    cout << m << " minutes.";
}

int main(void)
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);

    int n , c = 0;
    while(cin >> n){

        cin.ignore();
        memset(ar , 0 , sizeof(ar));
        int h1 , m1 , h2 , m2;

        for(int i=0;i<n;i++){

            string s1 , s2 , s3 , br;
            getline(cin , br);
            stringstream ss (br);
            ss >> s1;
            ss >> s2;

            h1 = (s1[0]-'0')*10 + s1[1] - '0';
            m1 = (s1[3]-'0')*10 + s1[4] - '0';
            h2 = (s2[0]-'0')*10 + s2[1] - '0';
            m2 = (s2[3]-'0')*10 + s2[4] - '0';

            int t1 = h1*60 + m1;
            int t2 = h2*60 + m2;

            for(int j=t1+1;j<=t2;j++)ar[j] = 1;
        }

        int counter = 0;
        for(int i=10*60;i<=18*60;i++){

            if(ar[i]==0)counter++;
            else counter = 0;

            ar[i] = counter;
        }

        int mx = 0 , ans = 0;

        for(int i=18*60;i>=600;i--){

            if(i-ar[i]<600){

                int t1 = ar[i] - 1;
                int t2 = i - ar[i] + 1;

                if(t1>=mx){

                    mx = t1;
                    ans = t2;
                }
            }

            else if(ar[i]>=mx){
                mx = ar[i];
                ans = i-ar[i];
            }
        }

        cout << "Day #" << ++c << ": the longest nap starts at ";
        time_print(ans);
        cout << " and will last for ";
        print(mx);
        cout << endl;
    }

    return 0;
}
