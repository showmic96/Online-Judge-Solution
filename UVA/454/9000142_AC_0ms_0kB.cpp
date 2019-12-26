// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

string make(string ar)
{
    string temp = "";

    int si = ar.size();

    for(int i=0;i<si;i++){

        if(ar[i]!=' ')temp+=ar[i];
    }
    
    sort(temp.begin() , temp.end());

    return temp;
}

int main(void)
{
    int t;
    cin >> t;
    bool check = false;
    scanf("\n");
    while(t--){

		if(check)cout << endl;check=true;
        vector<string>v;
        string ar;
        int c = 0;

        while(getline(cin , ar)){

            if(ar=="")break;
            v.push_back(ar);
            c++;
        }
        
        sort(v.begin() , v.end());

        for(int i=0;i<c;i++){

            string temp1 = make(v[i]) , temp2;

            for(int j=i+1;j<c;j++){
				//cout << "YES" << " " << temp1 << " " << temp2 << endl;
                temp2 = make(v[j]);

                if(temp1==temp2){

                    cout << v[i] << " = " << v[j] << endl;
                }
            }
        }
    }
    return 0;
}
