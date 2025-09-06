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

int main(){
    std::vector<int> arr = {23,45,76,1,937};
    
    Node* head = arr2Dll(arr);
    
    print(head);
    
    return 0;
}