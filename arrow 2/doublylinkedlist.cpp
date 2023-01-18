#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;


    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }

};


// for traversing the linked list
void print_list(Node* &head){
    if(head==NULL){
        return ;
    }
    else{
        Node* temp=head;

        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}
int list_length(Node* &head){
    if(head==NULL){
        return 0;
    }
    else{
        Node* temp =head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        return len;
    }
}
void insert_front(Node* &head,Node* &tail,int data){
    Node* nodeToInsert= new Node(data);
    // for handling empty list 
    if(head==NULL){
        head=nodeToInsert;
        tail=nodeToInsert;
        
    }
    else{
        nodeToInsert->next=head;
        head->prev=nodeToInsert;
        head=nodeToInsert;
    }

}
void insert_back(Node* &head,Node* &tail,int data){
    Node* nodeToInsert= new Node(data);
    // for empty list 
    if(tail==NULL){
        tail=nodeToInsert;
        head=nodeToInsert;
    }
    else{
        nodeToInsert->prev=tail;
        tail->next=nodeToInsert;
        tail=nodeToInsert;

    }
}

void insert_pos(Node* &head, Node* &tail,int data,int pos){
    //for handling position 1
    if(pos==1){
        insert_front(head,tail,data);
        return ;
    }
    //for any given position 
    Node* temp=head;
    int a=1;
    while(a<pos-1){
        temp=temp->next;
        a++;
    }
    if(temp->next==NULL){
        insert_back(head,tail,data);
        return;
    }
    //creation of node to insert
    Node* newnode= new Node(data);
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;

}
void delete_node(Node* &head,Node* &tail,int data){
    if(data==head->data){
        Node* temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        

        //free up the memory 
        temp->next==NULL;
        free(temp);
    }
    else{
        Node* curr=head;
        Node* prev=NULL;
        while(curr->data!=data){
            prev=curr;
            curr=curr->next;
        }
        curr->prev=NULL;
        prev->next=curr->next;

        //free up the memory
        curr->next=NULL;
        free(curr);
        //correction of tail position
        if(prev->next==NULL){
            tail=prev;
        }
    }

}

int main(){
    // Node* node1= new Node(10);
    // if we declare an empty list
    Node* head=NULL;
    Node* tail = NULL;
    cout<<"hello"<<endl;

    insert_front(head,tail,10);
    print_list(head);
    cout<<"length of linked list is "<<list_length(head)<<endl;

    insert_front(head,tail,11);
    print_list(head);

    insert_back(head,tail,9);
    print_list(head);

    insert_pos(head,tail,100,2);
    print_list(head);

    delete_node(head,tail,9);
    print_list(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;

    return 0;
}