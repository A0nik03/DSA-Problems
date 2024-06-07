#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

// Method - 1(Number Counting)
int f(int number,int arr[],int n){
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if(number == arr[i]){
            cnt++;
        }
    }
return cnt;
}

int main (){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int number;
    cin>>number;
    cout<<f(number,arr,n);
}

// Method - 2 (Number Hashing)

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //precompute:
    int hash[13] = {0};
    for (int i = 0; i < n; i++) {
        hash[arr[i]] += 1;
    }

    int q;
    cin >> q;
    while (q--) {
        int number;
        cin >> number;
        // fetching:
        cout << hash[number] << endl;
    }
    return 0;
}


// Method - 1(Character Counting)
int f(char character,string s){
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if(character == s[i]){
            cnt++;
        }
    }
return cnt;
}

int main (){
    int n;
    cin>>n;
    string s;
    cin>>s;
    char character;
    cin>>character;
    cout<<f(character,s);
}


// Method -2(Character hashing)
#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    //precompute:
    int hash[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        hash[s[i] - 'a']++;
    }

    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        // fetch:
        cout << hash[c - 'a'] << endl;
    }
    return 0;
}

// Method - 3(Charater Hashing)
#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    //precompute:
    int hash[256] = {0};
    for (int i = 0; i < s.size(); i++) {
        hash[s[i]]++;
    }

    int q;
    cin >> q;
    while (q--) {
        char c;
        cin >> c;
        // fetch:
        cout << hash[c] << endl;
    }
    return 0;
}

// How to hash large numbers like 10^9 or higher:
// Until now, we have learned the method of number hashing but using this method we cannot hash large numbers like 10e9 or higher. We can solve this problem using the STL map and unordered_map in C++ or the HashMap in Java collection. Now, we are going to discuss these concepts in detail and most of the concepts are the same in map/unordered_map(in C++) and HashMap(in Java).

// map and unordered_map in C++ / HashMap in Java

// Key: In a map, a key refers to the element, for which we want to store information. We can access the value of a key using the key itself like mp[key].

// Value: Value refers to the information stored corresponding to a key.

// Difference between array hashing and hashing using the map:
// Let’s understand the difference considering the array: [1, 2, 3, 1, 3, 2, 12]. Here, the maximum element of the array is 12. So, if we apply array hashing, we need an array of size 13. But if we apply the map data structure, it will be the following:


// Note: If we want to fetch the value of a key that does not exist in the map, the map will always return 0 in C++ and null in Java.

// Method-3(Number Hashing using map)

#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //precompute:
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        mp[arr[i]]++;
    }

    // iterate over the map:
    /* for(auto it : mp){
            cout << it.first << "->" << it.second << endl;
        }
    */

    int q;
    cin >> q;
    while (q--) {
        int number;
        cin >> number;
        // fetch:
        cout << mp[number] << endl;
    }
    return 0;
}

// Collision:
// Now, if we are applying linear chaining and division rule and we find that all elements of an array get stored in a single index, then we will call it a case of collision.

