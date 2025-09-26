#include<iostream>


using namespace std;

void selection(int arr[],int n){
    int minn, temp;
    for(int i = 0; i<n-1 ; i++){
        minn = i;
        for(int j = i + 1;j<n;j++){
            if(arr[j]<arr[minn]) minn = j;
        }
        swap(arr[minn], arr[i]);
    }
    for(int i = 0;i<n;i++){
        cout << arr[i];
    }
}

int main(){
    int arr[50], n;
    cout << "number of elements in the array = ";
    cin >> n;
    cout << "enter elements of array: ";
    for(int i = 0; i<n ; i++){
        cin >> arr[i];
    }
    selection(arr, n);
}