#include <iostream>
#include <utility> //Pairs
#include <vector> //Vectors
#include <list> //List
#include <deque> //Deque
using namespace std;

//Pairs
void explainPair(){
    pair<int,int> p1 = {1,3};
    cout<<p1.first<<" "<<p1.second<<endl;
    pair<int,pair<int,int>> p2 = {1,{3,4}};
    cout<<p2.first<<" "<<p2.second.second<<" "<<p2.second.first<<endl;
    pair<int,int> arr[] = {{1,2},{2,5},{5,1}};
    cout<<arr[1].second<<endl;
}

// //Vectors
// void explainVector(){
//     vector<int> v;
//     v.push_back(1);
//     v.emplace_back(2);

//     vector<pair<int,int>> vec1;
//     vec1.push_back({1,2});
//     vec1.emplace_back(1,2);

//     vector<int> vec2(5,100);
//     vector<int> vec3(5);
//     vector<int> vec4(5,20);
//     vector<int> vec5(vec2);

//     vector<int>::iterator it = vec2.begin();
//     it++;
//     cout<<*(it)<<" "<<endl;
//     it = it + 2;
//     cout<<*(it)<<" "<<endl;
    
//     vector<int>::iterator it = v.end();
//     // vector<int>::iterator it = v.rend();
//     // vector<int>::iterator it = v.rbegin();

//     cout<<v[0]<<" "<<v.at(0)<<endl;
//     cout<<v.back()<<" "<<endl;

//     // for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//     // {
//     //     cout<<*(it)<<" "<<endl;
//     // }

//     for (auto it = v.begin();it != v.end(); it++)
//     {
//         cout<<*(it)<<" "<<endl;
//     }

//     for (auto it:v)
//     {
//         cout<<it<<" "<<endl;
//     }

//     //{10,20,12,23}
//     v.erase(v.begin()+1);
//     v.erase(v.begin()+2,v.begin()+4); //{10,20,35} [start,end)

//     // Insert Function
//     vector<int> v(2,100); //{100,100}
//     v.insert(v.begin(),300); //{300,100,100}
//     v.insert(v.begin()+1,2,10); //{300,10,10,100,100}
//     vector<int> copy(2,50); //{50,50}
//     v.insert(v.begin(),copy.begin(),copy.end()); //{50,50,300,10,10,100,100}

//     //{10,20}
//     cout<<v.size()<<endl; //2
//     //{10,20}
//     v.pop_back(); //{10}
//     //v1-->{10,20}
//     //v2-->{30,40}
//     v.swap(vec2); //v1-->{30,40},v2-->{10,20}
//     v.clear(); //Erases the entire vector
//     cout<<v.empty();
// }

// List
void explainList(){
    list <int> ls;
    ls.push_back(2);
    ls.push_back(3);
    ls.emplace_back(4);
    for(auto it:ls){
        cout<<it<<" ";
    }

    ls.push_front(5);
    ls.emplace_front(6);
    for(auto it:ls){
        cout<<it<<" ";
    }
}

// Deque
void explainDeque(){
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.emplace_back(3);
    for(auto it:dq){
        cout<<it<<" ";
    }
    cout<<endl;
    dq.push_front(4);
    dq.push_front(5);
    dq.emplace_front(6);
    for(auto it:dq){
        cout<<it<<" ";
    }
    cout<<endl;

    dq.pop_back();
    dq.pop_front();
    for(auto it:dq){
        cout<<it<<" ";
    }
    cout<<endl;

    dq.back();
    dq.front();
    for(auto it:dq){
        cout<<it<<" ";
    }
}

int main(){
    // explainPair();
    // explainVector();
    // explainList();
    explainDeque();
}