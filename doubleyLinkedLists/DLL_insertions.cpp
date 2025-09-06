#include <iostream>
#include <vector>

class Node{
public:
    int data;
    Node * next;
    Node * back;

    Node (int data1, Node * next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    Node (int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node * arr2Dll(std::vector<int> & arr){
    Node * head = new Node (arr[0]);
    Node * prev = head;
    for(int i =1;i<arr.size();i++){
        Node * temp = new Node (arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node * head){
    while(head != NULL){
        std::cout<<head->data<<" ";
        head = head->next;
    }
}

Node * insertHead(Node * head, int n){
    Node * temp = new Node (n,head,nullptr);
    if(head == NULL){return temp;}
    head->back = temp;

    return temp;
}

Node * insertTail(Node * head, int n){
    if (head == NULL){
        return new Node(n);
    }
    Node * tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node * newTail = new Node(n,nullptr,tail);
    tail->next = newTail;

    return head;
}

Node * insertAtKthNode(Node * head, int n, int k){
    if (head == NULL){
        return new Node (n);
    }
    Node * temp = head;
    int count {};
    while (temp){
        count ++;
        if(count == k){
            break;
        }
        temp = temp->next;
    }

    Node * newElm = new Node (n,temp,temp->back);
    temp->back->next = newElm;
    temp->back = newElm;
    return head;
}

void insertNode (Node * temp, int n){
    Node * prev = temp->back;
    Node * front = temp->next;

    Node* newNode = new Node (n,temp,prev);
    temp->back = newNode;
    prev->next = newNode;
    
}
int main(){
    std::vector<int> arr = {23,45,76,1,937};
    
    Node* head = arr2Dll(arr);
    head = insertHead(head,299);
    head = insertTail(head,4679);
    head = insertAtKthNode(head,6969,3);
    insertNode(head->next,51);
    print(head);
    
    return 0;
}