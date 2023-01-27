#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
        int arr[100];
        int size=-1;

    void insert_heap(int element){
        size=size+1;
        int idx=size;
        arr[idx]=element;

        while(idx>=1){
            int parent=(idx-1)/2;

            if(arr[parent]<arr[idx]){
                swap(arr[parent],arr[idx]);
                idx=parent;
            }
            else{
                return ;
            }
        }
        

    }

    void print(){
        for(int i=0;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deleteFromHeap(){
        if(size==0){
            cout<<"heap is emmpty to kya delete karu!!!"<<endl;
            return ;
        }


        arr[0]=arr[size];
        size--;


        // correcting the position of node 
        int i=0;
        while(i<size){
            int leftChildidx=2*i +1;
            int rightChildidx=2*i +2;

            if(leftChildidx < size && arr[leftChildidx]>arr[i]){
                swap(arr[leftChildidx],arr[i]);
                i=leftChildidx;
            }
            else if(rightChildidx<size && arr[rightChildidx]>arr[i]){
                swap(arr[rightChildidx],arr[i]);
                i=rightChildidx;
            }
            else{
                return ;
            }

        }
        
    }
};


void heapify(int arr[],int n,int i){
    int parent=i;
    int leftChild=2*i ;
    int rightChild=2*i+1;

    if(leftChild <= n && arr[leftChild]>arr[parent]){
        
        parent=leftChild;
    }
    if(rightChild<=n && arr[rightChild]>arr[parent]){
        
        parent=rightChild;
    }
    if(parent!=i){
        swap(arr[parent],arr[i]);
        heapify(arr,n,parent);
    }
}
void heapSort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
    
}
int main(){
    heap h;
    h.insert_heap(25);
    h.insert_heap(50);
    h.insert_heap(12);
    h.insert_heap(10);
    h.insert_heap(55);
    h.print();
    cout<<"after deleting 0th index element"<<endl;
    h.deleteFromHeap();
    h.print();


    
    int arr[9]={1,2,3,4,52,12,0,19,5};
    int n=8;
    for(int i=(n)/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"heapify the array"<<endl;
     for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

    cout<<"after heap sort"<<endl;
    heapSort(arr,n);
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}