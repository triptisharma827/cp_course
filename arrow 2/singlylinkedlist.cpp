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
    // ~node(){
    //     int value=this->data;
    //     if(this->next!=NULL){
    //         delete next;
    //         this->next= NULL;
    //     }
    //     cout<<"memory is now free for node with data "<<value<<endl;

    // }

};

void insert_front(node* &head,int data){
    node* newnode= new node(data);
    newnode->next=head;
    head=newnode;
}
void insert_back(node* &tail,int data){
    node* newnode= new node(data);
    tail->next=newnode;
    tail=newnode;
}
void insert_pos(node* &head, node* &tail,int data,int pos){
    //for handling position 1
    if(pos==1){
        insert_front(head,data);
        return ;
    }
    //for any given position 
    node* temp=head;
    int a=1;
    while(a<pos-1){
        temp=temp->next;
        a++;
    }
    if(temp->next==NULL){
        insert_back(tail,data);
        return;
    }
    //creation of node to insert
    node* newnode= new node(data);
    newnode->next=temp->next;
    temp->next=newnode;

}
void delete_node(node* &head,node* &tail,int data){
    if(data==head->data){
        node* temp=head;
        head=head->next;

        //free up the memory 
        temp->next==NULL;
        free(temp);
    }
    else{
        node* temp=head;
        node* prev=NULL;
        while(temp->data!=data){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        //free up the memory
        temp->next=NULL;
        free(temp);
        //correction of tail position
        if(prev->next==NULL){
            tail=prev;
        }
    }

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
    
    node* node1=new node(5);
    // node* node2=new node(6);
    node* head=node1;
    node* tail=node1;
    insert_front(head,4);
    insert_front(head,3);
    insert_back(tail,7);
    print_list(head);
    cout<<endl;
    cout<<"after insert at any position function"<<endl;
    insert_pos(head,tail,2,3);
    print_list(head);
    delete_node(head,tail,2);
    print_list(head);
    return 0;
}