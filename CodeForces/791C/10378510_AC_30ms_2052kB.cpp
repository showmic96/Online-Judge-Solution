// In the name of Allah the Most Merciful.

#include<bits/stdc++.h>
using namespace std;

int main(void)
{

    int n , k;
    cin >> n >> k;

    int parent[55];

    for(int i=0;i<n;i++) parent[i] = i;

    for(int i=k-1;i<n;i++){

        string ar;
        cin >> ar;

        if(ar=="YES")parent[i] = i;
        else parent[i] = parent[i-k+1];
    }

    for(int i=0;i<n;i++){

        if(parent[i]<26)cout << (char)(parent[i] + 'A') << " ";
        else cout << "A" << (char)(parent[i] - 26 + 'a') << " ";
    }

    cout << endl;


    return 0;
}
