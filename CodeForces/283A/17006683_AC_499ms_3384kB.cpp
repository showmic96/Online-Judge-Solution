// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll ar[200005];
ll extra[200005];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    ll sum = 0 , tot = 1;

    for(int i=0;i<n;i++){

        int in;
        cin >> in;

        if(in==1){

            int in1 , in2;
            cin >> in1 >> in2;

            extra[in1]+=in2;

            sum+=(ll)in1*(ll)in2;
        }
        else if(in==2){

            int in;
            cin >> in;

            tot++;
            ar[tot] = in;
            sum+=in;
        }
        else{

            extra[tot-1]+=extra[tot];
            //extra[tot] = 0;
            ar[tot]+=extra[tot];
            extra[tot] = 0;

            sum-=ar[tot];
            ar[tot] = 0;
            tot--;
        }

        cout << setprecision(14) << fixed << (long double)sum/tot << '\n';
    }

    return 0;
}
