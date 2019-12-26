// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int countValue[1234567];

void kmpProcessing(string ar)
{
    int i=0 ,j=-1;
    int m = ar.size();

    countValue[i]=j;

    while(i<m){

        while(j>=0&&ar[i]!=ar[j])j=countValue[j];
        i++;j++;
        countValue[i]=j;
    }

}

int kmpSearch(string br , string ar)
{
    int i=0 , j=0 , counter = 0;
    int m = br.size();
    int k = ar.size();

    while(i<m){

        while(j>=0&&br[i]!=ar[j])j=countValue[j];
        i++;
        j++;

        if(j==k){
            counter++;
            j=countValue[j];
        }
    }

    return counter;
}

int main(void)
{
    int n;
    while(cin >> n){

        if(!n)break;
        vector<string>v;

        for(int i=0;i<n;i++){

            string ar;
            cin >> ar;
            v.push_back(ar);
        }

        string ar;
        cin >> ar;

        int mx=0;
        vector<string>ans;

        for(int i=0;i<n;i++){

            kmpProcessing(v[i]);
            int temp = kmpSearch(ar , v[i]);
            if(temp>mx){

                ans.clear();
                ans.push_back(v[i]);
                mx = temp;
            }

            else if(temp==mx){
                ans.push_back(v[i]);
            }
        }

        cout << mx << endl;
        int si = ans.size();

        for(int i=0;i<si;i++)cout << ans[i] << endl;
    }
    return 0;
}
