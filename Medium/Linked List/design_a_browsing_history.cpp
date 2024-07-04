//  Design Browser History

/*
Your task is to maintain a data structure that supports the following functions of a web browser.

1- Browser(homepage): Set homepage of the browser

2- Visit(url): Visit the url from the current page. It clears up all the forward history.

3- Back(steps): Move ‘steps’ backward in the browser history

4- Forward(steps): Move ‘steps’ forward in the browser history
Note:
If you can’t move steps forward or backward, just return the last website that can be reached.

The Queries are in the given format-:
The first line of each query contains the string representing the homepage of the web browser.

(1, url): Visit the url from the current page. 

(2, steps): Move ‘steps’ backward in the browser history.

(3, steps): Move ‘steps’ forward in the browser history.
*/

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    string data;
    Node* next;
    Node* back;
    Node(): data(0),next(nullptr),back(nullptr){};
    Node(string x) : data(x), next(nullptr), back(nullptr) {}
    Node(string x,Node* next,Node* back): data(x),next(next),back(back){};
};

class Browser
{
    Node* currPage;
    public:
    
    Browser(string &homepage)
    {
        currPage = new Node(homepage);
    }

    void visit(string &url)
    {
       Node* visit = new Node(url);
       currPage->next = visit;
       visit->back = currPage;
       currPage = visit;
    }

    string back(int steps)
    {
        while(steps){
            if(currPage->back){
                currPage = currPage->back;
            }
            else{
                break;
            }
            steps--;
        }
        return currPage->data;
    }

    string forward(int steps)
    {
        while(steps){
            if(currPage->next){
                currPage = currPage->next;
            }
            else{
                break;
            }
            steps--;
        }
        return currPage->data;
    }
};
