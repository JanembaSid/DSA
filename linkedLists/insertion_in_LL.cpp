#include <iostream>
#include <vector>
class Node {
    public:
    int data;
    Node * next;

    Node(int data1){
        data = data1;
        next = nullptr;
    }

    Node (int data1,Node * next1){
        data=data1;
        next = next1;
    }
};

Node* arr2LL(std::vector<int> & arr){
    Node* head = new Node (arr[0]);
    Node* mover = head;
    for(int i =1;i<arr.size();i++){
        Node * temp = new Node(arr[i]);
        mover->next = temp;
        mover=temp;
    }
    
    
    return head;
}

void print(Node* head){
    Node * temp = head;
    while(temp){
    std::cout<<temp->data<<" ";
    temp=temp->next;
    }
    std::cout<<std::endl;
}

Node * insertHead(Node* head,int val){
    if(head==NULL){return new Node(val);}
    return new Node(val,head);
}

Node* insertTail(Node* head,int val){
    if(head==NULL ) return new Node(val);
    Node* temp = head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* tail = new Node(val);
    temp->next=tail;
    return head;
}

Node* insertPosition(Node* head,int pos,int val){
    if(head==NULL && pos==1) return new Node(val);
    if(pos==1){
        return new Node(val,head);
    }
    Node* temp = head;
    int count =0;


    while(temp){
        count++;
        if(pos==count-1){
            Node * newNode = new Node(val,temp->next);
            temp->next = newNode;
            break;
        }
        temp =temp->next;
    }
    return head;
}

Node* insertbeforeVal(Node* head,int val,int insVal){
    if(head==NULL) return head;
    if(head->data==val) return new Node(insVal,head);
    Node* temp = head;
    while(temp->next!=NULL){
        if(temp->next->data==val){
            Node* newVal = new Node(insVal,temp->next);
            temp->next=newVal;
            break;
        }
        temp=temp->next;
    }
    return head;
}
int main (){
    std::vector<int> arr = {33,66,1,7,34};
    Node* head = arr2LL(arr);

    //delete head case
    head = insertHead(head,227);
    print(head);

    //delete tail case
    head = insertTail(head,889);
    print(head);


    std::vector<int> arr2 = {69,32,12,4,39};
    Node* heads = arr2LL(arr2);
    //delete val at a particular postion
    heads=insertPosition(heads,1,55);
    print(heads);

    //delete a particular val
    heads = insertbeforeVal(heads,32,69);
    print(heads);
}