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

int ll_len(Node * head){
    int count{};
    Node * temp = head;
    //while temp is not null
    while(temp){
        count++;
        temp=temp->next;
    }
    return count;
}

bool is_Present(Node * head,int num){
    Node * temp = head;
    while(temp){
        if(num==temp->data){return true;}
        temp = temp->next;
    }
    return false;
}

int main (){
std::vector<int> arr = {77,86,23,1,12,69,7};

Node * head = arr2LL(arr);
Node * temp = head;
while(temp){
std::cout<<temp->data<<" ";
temp=temp->next;

}
std::cout<<"The length of the linked list is "<<ll_len(head)<<std::endl;


std::cout<<"Checking if 7 is in the linked list..."<<std::endl;
std::cout<<is_Present(head,7);
}