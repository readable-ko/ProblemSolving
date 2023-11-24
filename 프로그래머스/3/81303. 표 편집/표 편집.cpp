#include <string>
#include <vector>
#include <iostream>
using namespace std;
class node {
public:
    node* prev;
    node* next;
    int curr;
    node(int c) {
        prev = nullptr;
        next = nullptr;
        curr = c;
    }
    
    node(node* p, node* n, int c): prev(p), next(n){
        curr = c;
    }
};

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<node*> st;
    int times;
    node* tail = new node(0);
    node* head = tail;
    
    for(int i = 0 ; i < n - 1; i++) {
        node* n_node = new node(i+1);
        n_node->prev = tail;
        tail->next = n_node;
        tail = n_node;
    }
    
    node* now = head;
    for(int i = 0 ; i < k ; i++) {
        now = now->next;
    }
        
    for(string command : cmd) {
        switch(command[0]) {
            case 'D': {
                times = stoi(command.substr(1,command.length()));
                for(int i = 0 ; i < times ; i++) {
                    now = now->next;
                }
                break;
            }   
            case 'U': {
                times = stoi(command.substr(1,command.length()));
                for(int i = 0 ; i < times ; i++) {
                    now = now->prev;
                }
                break;
            }
            case 'C':{
                st.push_back(now);
                node* tmp = now->prev;
                
                if(tmp != nullptr)
                    tmp->next = now->next;
                if(now->next != nullptr)
                    now->next->prev = tmp;
                
                if (now->next != nullptr)
                    now = now->next;
                else
                    now = tmp;
                break;
            }
            case 'Z': {
                node* n_node = st.back();
                st.pop_back();
                
                if(n_node->prev != nullptr) {
                    n_node->prev->next = n_node;
                }
                
                if(n_node->next != nullptr) {
                    n_node->next->prev = n_node;
                }
            }
        }
    }
    answer = string(n, 'O');
    while(!st.empty()) {
        node* curr = st.back(); st.pop_back();
        answer[curr->curr] = 'X';
    }
    return answer;
}