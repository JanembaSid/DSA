#include <iostream>
#include <vector>

class Node{
public:
    int data;
    Node * next;
    Node * back;

    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }

    Node(int data1, Node * next1, Node * back1){
        data = data1;
        next = next1;
        back = back1;
    }
};

Node * arr2Dll(std::vector<int> &arr){

    Node * head = new Node (arr[0]);
    Node * prev = head;
    for(int i =1; i <arr.size();i++){
        Node *temp = new Node (arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node * head){
    while(head){
        std::cout<< head->data<< " ";
        head = head->next;
    }
}
// one way to reverse a DLL is to use a stack and two while loops -> space complexity of O(n) and Time of O(2N)
// Another is the following
Node * reverseDll(Node * head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node * last = NULL;
    Node * current = head;
    while(current){
        last = current->back;
        current->back = current->next;
        current->next = last;
        current = current->back;
    }
    return last->back;
}

int main(){
    std::vector<int> arr = {32,46,99,12,1};
    Node * head = arr2Dll(arr);
    head = reverseDll(head);
    print(head);

}