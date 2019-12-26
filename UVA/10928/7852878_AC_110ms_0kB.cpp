// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    //freopen("input.txt","r",stdin);
    int t;
    cin >> t;
    set<int>ans;

    while(t--){
        //maping.clear();
        int p , hi = 1e9;
        cin >> p;
        scanf("\n");
        for(int i=0;i<p;i++){
            string ar , br;
            getline(cin , ar);
            int counter = 0;

            stringstream ss (ar);

            while(ss >> br){

                counter++;
            }

            //cout << "Counter : " << counter << endl;

            if(counter<hi){ans.clear();ans.insert(i+1);hi = counter;}
            if(counter==hi)ans.insert(i+1);

        }

        set<int>::iterator it;
        it = ans.begin();

        //cout << ans.size() << " SIZE" << endl;
        cout << *it;

        for(it++;it!=ans.end();it++)cout << " " << *it;
        ans.clear();

        cout << endl;
    }

    return 0;
}
