#include<iostream>
#include<utility>
#include<vector>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<set>
#include <unordered_set>
#include<map>

/* PAIRS
use this in terminal to compile with the latest version of the compiler.
this device uses older version of compiler in which syntax for initialization is different.

g++ -std=c++11 c++STL.cpp -o c++STL
./c++STL

*/
using namespace std;

void printPair(){               // basic pair syntax. use pair as a data type
    pair<int, int> p1 = {1,3};      //declaration and initialization 
    cout << p1.first << " " << p1.second << endl;    //printing a pair 
    pair<int, pair<int, int>> p2 = {1, {2, 5}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl;
    pair<int, int> arr[] = {{1, 3} , {2, 5} , {7, 8}};
    cout << arr[0].first;
}

void learnVector(){       //vectors are dynamic arrays. dynamic by size.
    
    // functions of vectors: push_back(), emplace_back(), begin(), end(), rbegin(), rend(), clear(), insert, size(), swap()
    
    vector<int> v;      //declare a vector

    v.push_back(10);         //initialise the vector
    v.emplace_back(20);
    v.emplace_back(12);
    v.emplace_back(23);

    vector<pair<int, int>>vec;

    vec.push_back({2,3});       //constructs, copies and sends
    vec.emplace_back(4,5);      //constructs in the container directly

    //print using vector iterators

    vector<int>::iterator it1 = v.begin();
    vector<int>::iterator it2 = v.end();
    it2--;
    cout << *it2 << " ";
    it2--;
    cout << *(it2) << " ";
    cout << endl;

    //print without vector iterators(using indexing)

    cout << v[0] <<" "<< v.at(0) << endl;//same thing

    cout << v.back() << endl;

    //or

    for(vector<int>::iterator it = v.begin() ; it != v.end() ; it++){
        cout << *(it) << " ";
    }
    cout << endl;

    for(auto it = v.begin() ; it != v.end() ; it++){
        cout << *(it) << " ";
    }
    cout << endl;

    for(auto it : v){
        cout << it << " ";
    }
    cout << endl;

    //deletion 
    // {10, 20, 12, 23} 
    v.erase(v.begin() + 2);     // deletes 12

    // {10, 20, 12, 23} 
    v.erase(v.begin() + 1, v.begin() + 3);   // {10, 23}         [start, end)

    //•Insert function
    vector<int>v2(2, 100);   // {100, 100}
    v2.insert(v2.begin(), 300);   // {300, 100, 100}
    v2.insert(v2.begin() + 1, 2, 10);     // {300, 10, 10, 100, 100}

    vector<int>copy(2, 50);
    v2.insert(v2.begin(), copy.begin(), copy.end());  // {50, 50, 300, 10, 10, 100, 100}

    cout << v2.size();

    v2.clear();  //clears entire vector

    cout << v2.empty();  //returns 1 if empty or 0 if not empty

}

void learnLists(){      //vectors where elements can be added in the front
    list<int>ls;
    ls.push_back(1);
    ls.emplace_back(2);
    ls.push_front(10);
    ls.emplace_front(20);
    for(auto t : ls){
        cout << t;
    }
}

void learnDQ(){         // basically faster lists, coz they are doubly linked. idk why
    deque<int>dq;
    dq.push_back (1); // {1} 
    dq.emplace_back(2); // {1, 2} 
    dq.push_front (4); // {4, 1, 2}
    dq.emplace_front (3); // {3, 4, 1, 2}

    dq.pop_front(); // {4, 1, 2}
    dq.pop_back();  //  {4, 1}

    //rest same as vector and list
}

void learnStack(){  //LIFO
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(3);
    st.emplace(5);  //{5, 3, 3, 2, 1}

    st.pop();

    cout << st.top();
    cout << st.size();
    cout << st.empty();

    stack<int> st1, st2;
    st1.swap(st2);
}

void learnQueue(){  //FIFO
    queue<int>q;
    q.push(1);
    q.emplace(4);
    q.push(2);
    q.push(5);

    q.back() += 5;  //prints 10

    q.pop(); // {4, 2, 5};

    cout << q.front();  // prints 4
    cout << q.back();   // prints 5

    //swap similar to stack
}

void learnPQ(){     //queue but bigger num comes on the top (* Max Heap * )
    priority_queue<int> pq1;

    pq1.push(5); //{5}
    pq1.push(2); //{5, 2}
    pq1.push(8); //{8, 5, 2}
    pq1.emplace(10); //{10, 8, 5, 2}

    cout << pq1.top() << endl;       //prints 10

    //Min Heap
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(5); //{5}
    pq2.push(2); //{2, 5}
    pq2.push(8); //{2, 5, 8}
    pq2.emplace(10); //{2, 5, 8, 10}

    cout << pq2.top() << endl;
}

void learnSet(){        //every element is sorted and unique
    set<int> st;
    st.insert(1);   //{1}
    st.emplace(2);  //{1, 2}
    st.insert(2);   //{1, 2} same as it is sorted and unique
    st.insert(4);   //{1, 2, 4}
    st.insert(3);   //{1, 2, 3, 4} as it is sorted
    st.insert(5);   //{1, 2, 3, 4, 5}
    // vector functions like insert and iterators can be used here

    auto it = st.find(3);   //points the iterator to 3
    cout << *it << endl;

    for(auto it = st.begin(); it != st.end() ; it++){
        cout << *(it) << endl;
    }
    
    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2); // after erase {1, 4, 5} [first, last)

}

void learnMultiset(){       //not unique, just sorted
    multiset<int> ms;
    ms.insert(1);   //{1}
    ms.insert(2);   //{1, 2}
    ms.insert(1);   //{1, 2, 1}
    ms.insert(1);   //{1, 2, 1, 1}

    // ms.erase(1);    // all 1s are erased
    ms.erase(ms.find(1));   // only one 1 is erased
}

void learnUSet(){   // not sortered but unique
    unordered_set<int> st;
    //elements are arranged randomly
}

void learnMap(){    //maps are basically referencing a key to a value
    map<int, int> mpp1;
    // map<key, value>
    map<int, pair<int, int>> mpp2;
    map<pair<int, int>, int> mpp3;
    

    mpp1[1] = 2;
    mpp1.insert({3, 1});
    mpp1.emplace(2, 2);

    /*final order will be sorted and unique based on key
    {1, 2}
    {2, 2}
    {3, 1}
    */
   
   mpp3[{2, 3}] = 10; // ((key as a pair), value)

   for(auto it : mpp1){
        cout << it.first << " " << it.second << endl;
   }
   
   cout << mpp1[2];
   cout << mpp1[3];
   cout << mpp1[5];

   // erase, swap, size, empty are same

}

void learnMultimap(){   //not unique, just sorted
    // only mpp[key] cannot be used here
}

void learnUMap(){   //not sorted but unique

}



int main(){
    learnMap();
}
