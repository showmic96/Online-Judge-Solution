// In the name of Allah the Lord of the Worlds.

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool cmp(char x , char y)
{
    return x>y;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string ar , br;

    cin >> ar >> br;

    sort(ar.begin() , ar.end());
    sort(br.begin() , br.end() , cmp);

    string ans = "";
    deque<char>d1 , d2;

    int si = ar.size() , i = 0 , j = ar.size()-1 , l1 = 0 ,l2 = 0;

    for(int i=0;i<si;i++)ans+='a';

    for(int i1=0;i1<ceil(1.00*si/2);i1++)d1.push_back(ar[i1]);
    for(int i1=0;i1<floor(1.00*si/2);i1++)d2.push_back(br[i1]);

    for(int i1=0;i1<si;i1++){

        if(i1%2==0){

            if(d2.empty()){

                ans[i] = d1.front();
                i++;
            }

            else if(d1.front()<d2.front()){

                ans[i] = d1.front();
                d1.pop_front();
                i++;
            }

            else{

                ans[j] = d1.back();
                d1.pop_back();
                j--;
            }
        }

        else{

            if(d1.empty()){

                ans[i] = d2.front();
                i++;
            }

            else if(d1.front()<d2.front()){

                ans[i] = d2.front();
                d2.pop_front();
                i++;
            }

            else{

                ans[j] = d2.back();
                d2.pop_back();
                j--;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
