#include <iostream>
#include <utility> //Pairs
#include <vector> //Vectors
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

//Vectors
void explainVector(){
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int,int>> vec1;
    vec1.push_back({1,2});
    vec1.emplace_back(1,2);

    vector<int> vec2(5,100);
    vector<int> vec3(5);
    vector<int> vec4(5,20);
    vector<int> vec5(vec2);

    vector<int>::iterator it = vec2.begin();
    it++;
    cout<<*(it)<<" "<<endl;
}

int main(){
    explainPair();
    explainVector();
}