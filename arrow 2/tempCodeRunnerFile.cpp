#include<bits/stdc++.h>
using namespace std;
class node{

    public:
    int data;
    node* next;

    //constructor
    node(int data){
         this->data = data;
         this->next= NULL;
    }

    //destructor
    ~node(){
        int value=this->data;
        if(this->next!=NULL){
            delete next;
            this->next= NULL;
        }
        cout<<"memory is now free for node with data "<<value<<endl;

    }

};

void insert_front(node* &head,int data){
    node* newnode= new node(data);
    newnode->next=head;
    head=newnode;
}
void insert_back(node* &tail,int data){
    node* newnode= new node(data);
    newnode->next=NULL;
    tail=newnode;
}
void print_list(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){