#include <bits/stdc++.h>

using namespace std;

// Creating node structure
struct node{
    int data;
    node *next;
};

// Creating linked list class
class linked_list{
    public:
        node *head,*tail;
        // Default constructor assigning head and tail as NULL
        linked_list(){
            head=NULL;
            tail=NULL;
        }

        // Function to add new nodes to our list
        void add_node(int value){
            node *temp=new node;
            temp->data=value;
            temp->next=NULL;

            // When head is empty, the first node will be both the head and tail
            if(head==NULL){
                head=temp;
                tail=temp;
            }
            // Other times, we will connect the previous tail to the new node and make the new node our tail 
            else{
                tail->next=temp;
                tail=tail->next;
            }
        }
        // Function to get the head
        node get_head(){
            return *head;
        }
        // Function to get the tail
        node get_tail(){
            return *tail;
        }
};

int main(){
    linked_list L;
    L.add_node(1);
    // the head and tail is both node 1
    L.add_node(2);
    // the head is node 1, while tail is node 2
    L.add_node(3);
    // the head is node 1, while tail is node 3

    cout<<"Head is:"<<L.get_head().data<<" Tail is:"<<L.get_tail().data<<endl;     // Head is:1 Tail is:3
    return 0;
}
