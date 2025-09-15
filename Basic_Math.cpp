#include <iostream>
#include<vector>
#include<cmath>

using namespace std;
/* use this to run using latest version of compiler
g++ -std=c++11 Basic_Math.cpp -o Basic_Math
./Basic_Math
*/

int countDigits(int n){
    int count = 0;
    while(n>0){
        n = n/10;
        count++;
    }
    return count;
}

int revNum(int n){
    int rev = 0;
    while(n>0){
        int lastDigit = n % 10;
        rev = (rev*10) + lastDigit;
        n = n/10;
    }
    return rev;   
}

void checkPalindrome(int n){    // palindrome if rev of a num equals to the num
    int rNum = revNum(n);
    if(rNum == n){
        cout << "it is palindrome";
    }
    else{
        cout << "not a palindrome";
    }
    
}

void printDivisors1(int n){      //this way of solving requires more TC
    for(int i = 1 ; i <= n ; i++ ){
        int rem = n%i;
        if(rem == 0){
            cout << i << " ";
        }
    }
}

void printDivisors2(int n){      //this way of solving requires less TC
    vector <int> vec;
    for(int i = 1 ; i*i <= n ; i++ ){
        int rem = n%i;
        if(rem == 0){
            vec.push_back(i);
            if(n/i != i){
                vec.push_back(n/i);
            }
        }
    }
    sort(vec.begin(), vec.end());
    for(auto it : vec) cout << it << " ";
}

void checkArmstrong(int n){      //a number that is equal to the sum of its own digits each raised to the power of the number of digits.
    int dup = 0;
    int lastDigit;
    int cube;
    int original = n;
    int digits = countDigits(n);
    while(n > 0){
        lastDigit = n%10;
        cube = pow(lastDigit, digits);
        n = n/10;
        dup = dup + cube;
    }
    if(dup == original){
        cout << "true";
    }
    else{
        cout << "false";
    }
}
 
void checkPrime(int n){
    int count = 0;
    for(int i = 1;i <= sqrt(n);i++){
        if (n%i == 0){
            count++;
            if(i != n/i){
                count++;
            }
        }
    }
    if(count == 2){
        cout << "prime";
    }
    else{
        cout << "not prime";
    }
}

void findGcd1(){     // longer method, starting from 1 and then going higher
    int gcd;
    int n1, n2;
    cout << "enter two nums: ";
    cin >> n1 >> n2;
    for (int i = 1;i <= min(n1, n2);i++){
        if (n1%i == 0 && n2%i == 0){
            gcd = i;
        }
    }
    cout << gcd;
}

void findGcd2(){    // shorter method, going backwards
    int gcd;
    int n1, n2;
    cout << "enter two nums: ";
    cin >> n1 >> n2;
    for (int i = min(n1, n2);i >= 1;i--){
        if (n1%i == 0 && n2%i == 0){
            gcd = i;
            break;      // breaks the loop once the condition is satisfied
        }
    }
    cout << gcd;   
}

int main(){
    int n;
    cin >> n;
    findGcd2();
}