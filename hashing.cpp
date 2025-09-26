#include<iostream>

using namespace std;

int countElements(int ele,int arr[], int n){
    int count = 0;
    for(int i = 0;i < n;i++){
        if(arr[i] == ele){
            count++;
        }
    }
    return count;
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }

    // precompute
    int hash[13] = {0};        //we are hardcoding 13 for simplicity becoz in example we will take digits upto 12
    for(int i = 0;i<n;i++){
        hash[arr[i]] += 1;
    }

    int q;      // q is query
    while(q--){
        int number;
        cin >> number;
        //fetch

        cout << hash[number] << endl;
    }
    return 0;

}

