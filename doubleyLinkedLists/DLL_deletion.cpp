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

Node * deleteHead(Node * head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node * temp = head;
    head = head->next;
    head->back = nullptr;

    temp->next = nullptr;
    delete temp;

    return head;
}

Node * deleteTail(Node * head){
    if(head ==NULL || head->next ==NULL){
        return NULL;
    }
    Node * tail = head;
    while(tail->next != NULL){
        tail=tail->next;
    }
    Node * newTail = tail->back;
    tail->back = nullptr;
    newTail->next = nullptr;
    delete tail;

    return head;
}

Node * removeKthElement(Node * head,int k){
    if(head == NULL) return NULL;
    int count = 1;
    Node * kElm = head;
    while(kElm != NULL && count < k){
        kElm = kElm->next;
        count++;
    }
    if(kElm == NULL) return head; // k out of bounds

    Node * prev = kElm->back;
    Node * front = kElm->next;

    if(prev == NULL && front == NULL){
        delete kElm;
        return NULL;
    }
    else if(prev == NULL){
        // Deleting the head node
        head = front;
        if(front) front->back = nullptr;
        delete kElm;
        return head;
    }
    else if(front == NULL){
        // Deleting the tail node
        prev->next = nullptr;
        delete kElm;
        return head;
    }

    prev->next = front;
    front->back = prev;
    delete kElm;
    return head;
}

void deleteNode (Node * temp){
    Node * front = temp->next;
    Node * prev = temp->back;

    if(front == NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }

    prev->next = front;
    front->back = prev;
    temp->back = nullptr;
    temp->next = nullptr;

    delete temp;
}
int main(){
    std::vector<int> arr = {23,45,76,1,937};
    
    Node* head = arr2Dll(arr);
    // head = deleteHead(head);
    // head = deleteTail(head);
    // head = removeKthElement(head,2);
    deleteNode(head->next->next->next->next);
    print(head);
    
    return 0;
}