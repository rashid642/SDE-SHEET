#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct block{
    char name[50];
    float phnno;
    struct block* next;
    struct block* prev;
};
int compare(char * str1, char * str2)
{
    int i = 0;
    while(str1[i] == str2[i])
    {
        if(str1[i] == '\0' && str2[i] == '\0')
            break;

        i++;
    }
    return str1[i] - str2[i];
}
struct block* insert(struct block* head, float _phnno, char* _name){
    struct block* newblock = (struct block*)malloc(sizeof(struct block));
    if(newblock==NULL){
        printf("Memory full..!!!\n");
        return head;
    }
    newblock->phnno=_phnno;
    strcpy(newblock->name, _name);
    if(head==NULL){
        return newblock;
    }
    struct block* temp=head;
    while(temp!=NULL){
        int res = compare(newblock->name, temp->name);
        if(res==0){
            printf("Name Already Exit\n");
            return head;
        }
        if(res<0){
           if(temp->prev==NULL){
               //insert at head;
               newblock->next=head;
               head->prev=newblock;
               head=newblock;
               return head;
           }
           struct block* previous=temp->prev;
           previous->next=newblock;
           newblock->prev=previous;
           newblock->next=temp;
           temp->prev=newblock;
           return head;
        }
        temp=temp->next;
    }
    //this will insert at end;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newblock;
    newblock->prev=temp;
    return head;
}
void traverse(struct block* head){
    while(head!=NULL){
        printf("%s %f\n",head->name, head->phnno);
        head=head->next;
    }
}
int main(){
    struct block* head=NULL;
    traverse(head);
    char name1[50]="Viren";
    head=insert(head,989898.0,name1);
    char name2[50]="Rashid";
    head=insert(head,983458.0,name2);
    char name3[50]="Zzz";
    head=insert(head,982398.0,name3);
    char name4[50]="Vidhi";
    head=insert(head,982398.0,name4);
    char name5[50]="Soham";
    head=insert(head,982398.0,name5);
    traverse(head);
    return 0;
}

