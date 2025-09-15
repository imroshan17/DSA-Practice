#include<iostream>
#include<utility>
#include<list>

/*
g++ -std=c++11 c++STL2.cpp -o c++STL2
./c++STL2
*/
using namespace std;

void learnLists(){
    list<int>ls;
    ls.push_back(1);
    ls.emplace_back(2);
    ls.push_front(10);
    ls.emplace_front(20);
    for(auto t : ls){
        cout << t;
    }
}

int main(){
    learnLists();
}