/*
*       Queue
*
*       code by vuong :>/
*/
#include <iostream>
using namespace std;

// khai báo cấu trúc của queue 
struct node{
    int data;
    struct node *next;
};
typedef struct node node;
struct queue{
    node *head;
    node *tail;
};
typedef struct queue queue;
//================================================
// khởi tạo queue
void createQueue(queue &q){
    q.head = NULL;
    q.tail = NULL;
}
// khởi tạo một node mới
node *createNode(int data){
    node *newNode = new node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//================================================
// kiểm tra rỗng
bool isEmpty(queue q){
    return q.head == NULL;
}
// thêm phần tử vào queue
void push(queue &q, node *newNode){
    if(isEmpty(q)){
        q.head  = q.tail = newNode;
    }
    else{
        q.tail->next = newNode;
        q.tail = newNode;
    }
}
// xem phần tử trên cùng
int top(queue q){
   return q.head->data; 
}
// lấy phần tử trên cùng ra
int pop(queue &q){
    int data = q.head->data;
    node *temp = q.head->next;
    q.head = NULL;
    q.head = temp;
    return data;
}
// lấy toàn bộ queue ra
void display(queue &q){
    while(!isEmpty(q)){
        cout << pop(q) << " ";
    }
}
//================================================

int main(){
    int n;cin>>n;
    queue q;
    createQueue(q);
    cout << "\nqueue rong : " << isEmpty(q);
    for(int i = 0; i <n;i++){
        int data;cin>>data;
        node *newNode = createNode(data);
        push(q,newNode);
    }
    cout << "\nqueue rong : " << isEmpty(q);
    cout << "\nphan tu dau tien la (top) : " << top(q);
    
    cout << "\nphan tu dau tien la (pop) : " << pop(q) << endl;
    display(q);
    cout << "\nqueue rong : " << isEmpty(q);
    return 0;
}
