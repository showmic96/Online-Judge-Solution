// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

struct myStruct{

    char x ;
    int counter;

}ans[1010];

bool cmp(myStruct A , myStruct B)
{
    if(A.counter==B.counter){

        return A.x > B.x;
    }

    return A.counter < B.counter;
}

int main(void)
{
    string ar;
    map<char, int>maping;
    bool check = false;
    while(getline(cin , ar)){
        if(check)cout << endl;check=true;
        maping.clear();
        int si = ar.size();
        int d = 1;

        for(int i=0;i<si;i++){

            if(maping[ar[i]]==0){

                maping[ar[i]] = d;
                ans[d].counter = 0;
                ans[d].x = ar[i];

                d++;

            }


            //cout << ar[i] << " " << maping[ar[i]] << endl;;
            ans[maping[ar[i]]].counter++;

        }

        sort(ans+1 , ans+d , cmp);

        for(int i=1;i<d;i++){

            cout << (int)(ans[i].x) << " " << ans[i].counter << endl;
        }

    }
    return 0;
}
