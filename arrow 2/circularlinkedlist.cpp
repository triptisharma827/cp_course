#include<bits/stdc++.h>
using namespace std;

//for singly linked list

class node{
    public:
    int data;
    node* next;


    // constructor
    node(int data){
        this->data =data;
        this->next=NULL;
    }
};

void insertNode(node* &tail,int element,int value){
    node* newnode= new node(value);
    // for empty list 
    if(tail==NULL){
        tail=newnode;
        newnode->next=newnode;
    }
    else{
        // for non empty list that has the element 
        node* temp=tail;

        while(temp->data!=element){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        
    }
}

void print_list(node* &tail){
    node* temp=tail;
    if(tail==NULL){
        cout<<"the list is empty"<<endl;
        return;
     }
    do {
        cout<< tail->data<<" ";
        tail=tail->next;

    } while(tail != temp); 

    cout<<endl;
}
void delete_node(node* &tail,int data){
    // empty list
     if(tail==NULL){
        cout<<"the list is empty"<<endl;
        return;
     }
     else{
        node* prev=tail;
        node* curr=prev->next;

        while(curr->data!=data){
            prev=curr;
            curr=curr->next;

        }

        prev->next=curr->next;
        // 1 node linked list 
        if(curr == prev){
            tail=NULL;
        }

        // >=2 node linked list 
        else if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;

        // delete curr;
        free(curr);
     }
}
int main(){
    node* tail=NULL;

    // insertNode(tail,5,2);
    // print_list(tail);

    // insertNode(tail,2,3);
    // print_list(tail);

    // insertNode(tail,2,5);
    // print_list(tail);

    insertNode(tail,2,7);
    print_list(tail);

    insertNode(tail,7,4);
    print_list(tail);

    delete_node(tail,7);
    print_list(tail);

    delete_node(tail,4);
    print_list(tail);

    return 0;
}