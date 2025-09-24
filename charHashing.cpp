#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){
    string s;
    cin >> s;

    //pre compute
    int hash[256] = {0};      //256 is the number of characters
    for(int i = 0;i < s.size();i++){
        hash[s[i]]++;
    }

    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        //fetch
        cout << hash[c];
    }
    return 0;
}