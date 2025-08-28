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

Node * delHead(Node* head){
    if(head==NULL){return head;}
    Node* temp =head;
    head=head->next;
    free(temp);
    return head;
}

Node* delTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp = head;

    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    return head;
}

Node* delPosition(Node* head,int pos){
    if(head==NULL) return head;
    Node* temp = head;
    if(pos==1){
        head=head->next;
        delete temp;
        return head;
    }
    int count = 0;
    Node * prev = nullptr;
    while(temp){
        count++;
        if(count==pos){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp=temp->next;
    }

    return head;
}

Node* delVal(Node* head,int val){
    if(head==NULL) return head;
    Node* temp = head;
    if(head->data==val){
        head=head->next;
        delete temp;
        return head;
    }
    Node * prev = nullptr;
    while(temp){
        if(temp->data==val){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp=temp->next;
    }

    return head;
}
int main (){
    std::vector<int> arr = {33,66,1,7,34};
    Node* head = arr2LL(arr);

    //delete head case
    head = delHead(head);
    print(head);

    //delete tail case
    head = delTail(head);
    print(head);


    std::vector<int> arr2 = {69,32,12,4,39};
    Node* heads = arr2LL(arr2);
    //delete val at a particular postion
    heads=delPosition(heads,3);
    print(heads);

    //delete a particular val
    heads = delVal(heads,69);
    print(heads);
}