#include<iostream>

using namespace std;

/*recursion: when a function calls itself until the condition is met
g++ -std=c++11 recursion.cpp -o recursion
./recursion
*/

/*imp terms:
1. recursion
2. base case: a base case is the condition that stops the recursion
3. stack overflow: when function calls or local memory use exceed the stack’s limit.
4. recursion tree: diagram that explains the flow of recursion

*/

void f1(){       //infinite recursion, segmentation error
    cout << 1;
    f1();    // again calls f(), which means this function does not end. this is called STACK OVERFLOW
}

void f2(int count){     //finite recursion
    if(count == 3){     //base case
        return;
    }
    cout << count;
    f2(count+1);
}

void printName(int cnt,int n){
    if(cnt == n){
        return;
    }
    cout << "roshan" << " ";
    printName(cnt + 1, n);
}

void printNum1(int cnt, int n){
    if (cnt > n){
        return;
    }
    cout << cnt << " ";
    printNum1(cnt+1, n);
}

void printrNum(int i){
    if(i < 1){
        return;
    }
    cout << i << " ";
    printrNum(--i);
}



void printNum2(int i){      //Backtrack Method
    if (i < 1){
        return;
    }
    printNum2(i-1);
    cout << i << " ";
}

void sumNum1(int i, int sum){        //parameterised recursion
    if(i < 1){
        cout << sum;
        return;
    }
    sumNum1(i-1, sum + i);
}

int sumNum2(int n){     // functional recursion
    if(n == 0){        
        return 0;
    }
    return n + sumNum2(n-1);
}

int factorial(int n){
    if (n == 0){
        return 0;
    }
    return n*factorial(n-1);
}

int main(){
    int n;
    cin >> n;
    cout << factorial(n);
}
