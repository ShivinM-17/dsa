#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct Queue{
    int* arr;
    int top;
    int back;
    int capacity;
    int size;
};
struct Queue* createQueue(int cap){
    struct Queue* new_q=(struct Queue*)malloc(sizeof(struct Queue));
    new_q->capacity=cap;
    new_q->top=-1;
    new_q->back=-1;
    new_q->size=0;
    new_q->arr=(int*)malloc(cap*sizeof(int));
    return new_q;
}
void push(struct Queue* q1, struct Queue* q2, int val){
    q2->arr[++q2->top]=val;
    q1->size++;
    while(q1->arr[q1->top]!=-1){
        q2->arr[++q2->top]=
    }

}

// #define n 20
// int q1[n], q2[n],temp[n];
// int t1=-1,b1=-1,t2=-1,b2=-1,n=0;

// void push(int val){
//     q2[++t2]=val;
//     n++;
//     while(t1!=-1){
//         q2[++t2]=q1[t1--];
//     }
//     temp=q1;
//     q1=q2;
//     q2=temp;


// }
int main(){
    return 0;
}