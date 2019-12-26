#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    int c = 0;

    while(t--){

        string ar;
        int si;
        cin >> si >> ar;


        int ban_counter = 0 , wi_counter = 0 , a_counter = 0 , t_counter = 0;

        for(int i=0;i<si;i++){

            if(ar[i]=='B')ban_counter++;
            if(ar[i]=='W')wi_counter++;
            if(ar[i]=='A')a_counter++;
            if(ar[i]=='T')t_counter++;

        }

        printf("Case %d: ",++c);

        if(ban_counter+a_counter==si&&ban_counter!=0)cout << "BANGLAWASH" << endl;
        else if(wi_counter+a_counter==si&&wi_counter!=0)cout << "WHITEWASH" << endl;
        else if(a_counter==si)cout << "ABANDONED" << endl;
        else if(ban_counter>wi_counter)cout << "BANGLADESH " << ban_counter << " - " << wi_counter << endl;
        else if(ban_counter<wi_counter)cout << "WWW " << wi_counter << " - " << ban_counter << endl;
        else cout << "DRAW " << ban_counter << " " << t_counter << endl;

    }
    return 0;
}
