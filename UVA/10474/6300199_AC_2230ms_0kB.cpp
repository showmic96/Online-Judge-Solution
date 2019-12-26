#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a , b;

    multiset<int>marbel;
    map<int , int>is;
    multiset<int>::iterator it;

    int j=0;

    while(cin >> a >> b){
    j++;
        if(!a&&!b)break;
        marbel.clear();is.clear();
        int in;

        while(a--){

            cin >> in;
            is[in]++;
            marbel.insert(in);
        }

        printf("CASE# %d:\n",j);
        while(b--){
        cin >> in;
        if(is[in]==0)cout <<in << " not found" << endl;
        else{
            bool check = false;
            int d=0;
            for(it = marbel.begin();it!=marbel.end();it++){
                d++;
                if(*it==in){break;check=true;}
            }

        cout << in << " found at " << d << endl;
        }

        }
    }
    return 0;
}
