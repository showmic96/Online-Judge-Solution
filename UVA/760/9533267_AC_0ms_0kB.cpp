// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string ar , br;
    bool space = false;
    while(cin >> ar >> br){

        if(space)printf("\n");space = true;
        int si1 = ar.size();
        int si2 = br.size();
        int mx = 0;

        set<string>ans;
        set<string>::iterator it;

        for(int i=0;i<si1;i++){

            for(int j=0;j<si2;j++){

                if(ar[i]==br[j]){

                    string temp = "";
                    int counter = 0;

                    for(int k=j;k<si2;k++){

                        if(i+counter==si1)break;

                        if(ar[i+counter]==br[k])temp+=ar[i+counter];
                        else break;

                        counter++;
                    }

                    if(ans.empty()){ans.insert(temp);mx = counter;}
                    else if(mx==counter)ans.insert(temp);
                    else if(mx<counter){ans.clear();ans.insert(temp);mx = counter;}
                }
            }
        }

        for(it = ans.begin() ;it!=ans.end();it++)cout << *it << endl;

        if(ans.empty())printf("No common sequence.\n");
    }
    return 0;
}
