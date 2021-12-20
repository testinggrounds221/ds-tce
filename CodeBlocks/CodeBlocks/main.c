#include <stdio.h>
#include <stdlib.h>
// Josepheus
struct Node{
    int val;
    struct Node* next;
};

struct CLL{
    struct Node* head;
};

void createCLL(struct CLL* cll){
    cll = (struct CLL*)(malloc(sizeof(struct CLL)));

}

void display(struct CLL* cll){
    struct Node* ptr = cll->head;
    if(ptr){
        do{
            printf("%d",ptr->val);
            ptr = ptr->next;
        }while(ptr!=cll->head);
    }
}

void insertBeggining(struct CLL* cll, int key){
    if(!cll->head){
        cll->head = (struct Node*)(malloc(sizeof(struct Node)));
        cll->head->val = key;
        cll->head->next = cll->head;
        return;
    }
    struct Node* newNode = (struct Node*)(malloc(sizeof(struct Node)));
    newNode->val = key;
    newNode->next = cll->head;
}

void append(struct CLL* cll, int key){
    struct Node* ptr = cll->head;
    if(cll->head==0){
        insertBeggining(cll,key);
        return;
    }
    struct Node* newNode = (struct Node*)(malloc(sizeof(struct Node)));
    newNode->next = cll->head; // IMPORTANT
    newNode->val = key;

    while(ptr->next!=cll->head)
        ptr = ptr->next;
    ptr->next = newNode;
}

int main()
{
    printf("Hello world!\n");
    struct CLL* cll = (struct CLL*)(malloc(sizeof(struct CLL)));
    cll->head = 0;
    for(int i = 0;i <10;i++){
        append(cll,i);
    }
    display(cll);
    return 0;
}
