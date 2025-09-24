#include<iostream>
#include<map>

using namespace std;

void usingHash(int arr[], int n){
    // precompute
    int hash[13] = {0};        //we are hardcoding 13 for simplicity becoz in example we will take digits upto 12
    for(int i = 0;i<n;i++){
        hash[arr[i]] += 1;
    }

    int q;      // q is query
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        //fetch
        cout << hash[number];
    }
}

void usingUnorderedMap(int arr[], int n){
    //precompute
    map <int, int> mpp;
    for(int i = 0; i<n ; i++){
        mpp[arr[i]]++;
    }
    int q;      // q is query
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        //fetch
        cout << mpp[number];
    }
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    usingHash(arr, n);
    usingUnorderedMap(arr, n);
    return 0;

}

