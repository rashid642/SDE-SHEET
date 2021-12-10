#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct block{
    char name[50];
   long long int phnno;
    struct block *next;
    struct block *prev;
};

int compare(char *str1, char *str2) {
    int i = 0;
    while(str1[i] == str2[i])
    {
        if(str1[i] == '\0' && str2[i] == '\0')
        break;

        i++;

    }
    return (str1[i] - str2[i]);
}

struct block *insert(struct block *head,long long int _phnno, char *_name) {

    struct block* newblock = (struct block*)malloc(sizeof(struct block));

    if(newblock == NULL){

        printf("Memory full..!!!\n");
        return head;

    }

    newblock->phnno=_phnno;
    strcpy(newblock->name, _name);
    if(head==NULL){

        return newblock;
    }

struct block *temp = head;
    while(temp!=NULL){

        int res = compare(newblock->name, temp->name);

        if(res == 0){

            printf("Name Already Exists\n");
            return head;

        }

        if(res<0){

           if(temp->prev == NULL){
               //insert at head;
               newblock->next=head;
               head->prev=newblock;
               head=newblock;
               return head;
           }

struct block *previous=temp->prev;

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
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=newblock;
    newblock->prev=temp;
    return head;

}

void deleteblock(struct block * &temp,struct block * &head) {
    //deleting head
    if(temp->prev==NULL){
        if(temp->next==NULL){
            head=NULL;
            return;
        }
        temp->next->prev=NULL;
        head=head->next;
        return;
    }
    //deleting last element
    if(temp->next==NULL){
        temp->prev->next=NULL;
        return;
    }
    //deleting in-between element
    temp->prev->next=temp->next;
}


void traverse(struct block *head){
    if(head==NULL){
        printf(".....No data.....\n");
    }
    while(head!=NULL){
        printf("%s \t \t \t %lld\n",head->name, head->phnno);
        head=head->next;
    }
}

struct block * searchByPhoneNo(struct block * head, long long int no){
    while(head!=NULL){
        if(head->phnno==no){
            return head;
        }
        head=head->next;
    }
    return NULL;
}

struct block * searchByName(struct block * head, char *_name){
    while(head!=NULL){
        int res = compare(head->name, _name);
        if(res==0){
            return head;
        }
        head=head->next;
    }
    return NULL;
}

int main(){

    struct block *head = NULL;
    char name1[50]="Viren";
    head=insert(head,9898989898,name1);
    char name2[50]="Rashid";
    head=insert(head,9834581231,name2);
    char name3[50]="Khan";
    head=insert(head,9823982242,name3);
    char name4[50]="Vidhi";
    head=insert(head,9823982123,name4);
    char name5[50]="Soham";
    head=insert(head,9823987653,name5);
    int option, op = 0;
    long long int phone_no;
    char name[50];

    while(op != 13) {
        printf("\n1.Insert\n2.Delete\n3.Change\n4.Display\n5.Search\n6.Delete All\n7.Exit\nEnter your choice: ");
        scanf("%d", &option);
        switch(option) {
            case 1: {
                printf("\nEnter the name: ");
                scanf("%s", name);
                printf("\nEnter the number: ");
                scanf("%lld", &phone_no);

               head = insert(head, phone_no, name);
                break;

            }
            case 2: {
                printf("\n\n1. Delete by Phone no ");
                printf("\n2. Delete by Name \n");
                int n;
                scanf("%d",&n);
                if(n==1){
                    printf("\nEnter the phone number you want to delete: ");
                    scanf("%lld", &phone_no);
                    struct block*temp=searchByPhoneNo(head,phone_no);
                    if(temp!=NULL){
                        deleteblock(temp,head);
                        printf("Deleted..!!");
                    }else{
                        printf("\nThis Phone number does't exist ");
                    }
                }
                else if(n==2){
                    printf("\nEnter the name you want to delete: ");
                    scanf("%s", name);
                    struct block*temp=searchByName(head,name);
                    if(temp!=NULL){
                        deleteblock(temp,head);
                        printf("Deleted..!!");
                    }else{
                        printf("\nThis name does't exist ");
                    }
                }else{
                    printf("\nSelect correct input ");
                }
                break;

            }
            case 3: {
                printf("\n\n1. Change Phone no ");
                printf("\n2. Change Name \n");
                int n;
                scanf("%d",&n);
                if(n==1){
                    printf("\nEnter the phone number you want to Change: ");
                    scanf("%lld", &phone_no);
                    struct block*temp=searchByPhoneNo(head,phone_no);
                    if(temp!=NULL){
                        printf("\nEnter new Number: ");
                        long long int newno;
                        scanf("%lld", &newno);
                        temp->phnno=newno;
                        printf("Updated..!!");
                    }else{
                        printf("\nThis Phone number does't exist ");
                    }
                }
                else if(n==2){
                    printf("\nEnter the name you want to Change: ");
                    scanf("%s", name);
                    struct block*temp=searchByName(head,name);
                    if(temp!=NULL){
                        printf("\nEnter new Name: ");
                        char newname[50];
                        scanf("%s", newname);
                        strcpy(temp->name, newname);
                        printf("Updated..!!");
                    }else{
                        printf("\nThis name does't exist ");
                    }
                }else{
                    printf("\nSelect correct input ");
                }
                break;
            }
            case 4: {
                printf("Name \t \t \tPhone Number\n");
                traverse(head);
                break;
            }
            
            case 5: {
                printf("\n\n1. Search by Phone no ");
                printf("\n2. Search by Name \n");
                int n;
                scanf("%d",&n);
                if(n==1){
                    printf("\nEnter the phone number you want to search: ");
                    scanf("%lld", &phone_no);
                    struct block*temp=searchByPhoneNo(head,phone_no);
                    if(temp!=NULL){
                        printf("Name=%s   Phone No=%lld",temp->name,temp->phnno);
                    }else{
                        printf("\nThis Phone number does't exist ");
                    }
                }
                else if(n==2){
                    printf("\nEnter the name you want to search: ");
                    scanf("%s", name);
                    struct block*temp=searchByName(head,name);
                    if(temp!=NULL){
                        printf("Name=%s   Phone No=%lld",temp->name,temp->phnno);
                    }else{
                        printf("\nThis name does't exist ");
                    }
                }else{
                    printf("\nSelect correct input ");
                }
                break;

            }
            case 6: {
                head=NULL;
                break;

            }
            case 7: {
                op = 13;
                break;
            }
            default: {
                printf("\nInvalid input\n");
            }

        }
    }

    return 0;
}















#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct block{
    char name[50];
   long long int phnno;
    struct block *next;
    struct block *prev;
};

int compare(char *str1, char *str2) {
    int i = 0;
    while(str1[i] == str2[i])
    {
        if(str1[i] == '\0' && str2[i] == '\0')
        break;

        i++;

    }
    return (str1[i] - str2[i]);
}

struct block *insert(struct block *head,long long int _phnno, char *_name) {

    struct block* newblock = (struct block*)malloc(sizeof(struct block));

    if(newblock == NULL){

        printf("Memory full..!!!\n");
        return head;

    }

    newblock->phnno=_phnno;
    strcpy(newblock->name, _name);
    if(head==NULL){

        return newblock;
    }

struct block *temp = head;
    while(temp!=NULL){

        int res = compare(newblock->name, temp->name);

        if(res == 0){

            printf("Name Already Exists\n");
            return head;

        }

        if(res<0){

           if(temp->prev == NULL){
               //insert at head;
               newblock->next=head;
               head->prev=newblock;
               head=newblock;
               return head;
           }

struct block *previous=temp->prev;

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
    while(temp->next != NULL){
        temp=temp->next;
    }
    temp->next=newblock;
    newblock->prev=temp;
    return head;

}

struct block* deleteblock(struct block * temp,struct block *head) {
    //deleting head
    if(temp->prev==NULL){
        if(temp->next==NULL){
            head=NULL;
            return head;
        }
        temp->next->prev=NULL;
        head=head->next;
        return head;
    }
    //deleting last element
    if(temp->next==NULL){
        temp->prev->next=NULL;
        return head;
    }
    //deleting in-between element
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    return head;
}


void traverse(struct block *head){
    if(head==NULL){
        printf(".....No data.....\n");
    }
    while(head!=NULL){
        printf("%s \t \t \t %lld\n",head->name, head->phnno);
        head=head->next;
    }
}

struct block * searchByPhoneNo(struct block * head, long long int no){
    while(head!=NULL){
        if(head->phnno==no){
            return head;
        }
        head=head->next;
    }
    return NULL;
}

struct block * searchByName(struct block * head, char *_name){
    while(head!=NULL){
        int res = compare(head->name, _name);
        if(res==0){
            return head;
        }
        head=head->next;
    }
    return NULL;
}

int main(){

    struct block *head = NULL;
    char name1[50]="Viren";
    head=insert(head,9898989898,name1);
    char name2[50]="Rashid";
    head=insert(head,9834581231,name2);
    char name3[50]="Khan";
    head=insert(head,9823982242,name3);
    char name4[50]="Vidhi";
    head=insert(head,9823982123,name4);
    char name5[50]="Soham";
    head=insert(head,9823987653,name5);
    int option, op = 0;
    long long int phone_no;
    char name[50];

    while(op != 13) {
        printf("\n1.Insert\n2.Delete\n3.Change\n4.Display\n5.Search\n6.Delete All\n7.Exit\nEnter your choice: ");
        scanf("%d", &option);
        switch(option) {
            case 1: {
                printf("\nEnter the name: ");
                scanf("%s", name);
                printf("\nEnter the number: ");
                scanf("%lld", &phone_no);

               head = insert(head, phone_no, name);
                break;

            }
            case 2: {
                printf("\n\n1. Delete by Phone no ");
                printf("\n2. Delete by Name \n");
                int n;
                scanf("%d",&n);
                if(n==1){
                    printf("\nEnter the phone number you want to delete: ");
                    scanf("%lld", &phone_no);
                    struct block*temp=searchByPhoneNo(head,phone_no);
                    if(temp!=NULL){
                        head=deleteblock(temp,head);
                        printf("Deleted..!!");
                    }else{
                        printf("\nThis Phone number does't exist ");
                    }
                }
                else if(n==2){
                    printf("\nEnter the name you want to delete: ");
                    scanf("%s", name);
                    struct block*temp=searchByName(head,name);
                    if(temp!=NULL){
                        head=deleteblock(temp,head);
                        printf("Deleted..!!");
                    }else{
                        printf("\nThis name does't exist ");
                    }
                }else{
                    printf("\nSelect correct input ");
                }
                break;

            }
            case 3: {
                printf("\n\n1. Change Phone no ");
                printf("\n2. Change Name \n");
                int n;
                scanf("%d",&n);
                if(n==1){
                    printf("\nEnter the phone number you want to Change: ");
                    scanf("%lld", &phone_no);
                    struct block*temp=searchByPhoneNo(head,phone_no);
                    if(temp!=NULL){
                        printf("\nEnter new Number: ");
                        long long int newno;
                        scanf("%lld", &newno);
                        temp->phnno=newno;
                        printf("Updated..!!");
                    }else{
                        printf("\nThis Phone number does't exist ");
                    }
                }
                else if(n==2){
                    printf("\nEnter the name you want to Change: ");
                    scanf("%s", name);
                    struct block*temp=searchByName(head,name);
                    if(temp!=NULL){
                        printf("\nEnter new Name: ");
                        char newname[50];
                        scanf("%s", newname);
                        strcpy(temp->name, newname);
                        printf("Updated..!!");
                    }else{
                        printf("\nThis name does't exist ");
                    }
                }else{
                    printf("\nSelect correct input ");
                }
                break;
            }
            case 4: {
                printf("Name \t \t \tPhone Number\n");
                traverse(head);
                break;
            }
            
            case 5: {
                printf("\n\n1. Search by Phone no ");
                printf("\n2. Search by Name \n");
                int n;
                scanf("%d",&n);
                if(n==1){
                    printf("\nEnter the phone number you want to search: ");
                    scanf("%lld", &phone_no);
                    struct block*temp=searchByPhoneNo(head,phone_no);
                    if(temp!=NULL){
                        printf("Name=%s   Phone No=%lld",temp->name,temp->phnno);
                    }else{
                        printf("\nThis Phone number does't exist ");
                    }
                }
                else if(n==2){
                    printf("\nEnter the name you want to search: ");
                    scanf("%s", name);
                    struct block*temp=searchByName(head,name);
                    if(temp!=NULL){
                        printf("Name=%s   Phone No=%lld",temp->name,temp->phnno);
                    }else{
                        printf("\nThis name does't exist ");
                    }
                }else{
                    printf("\nSelect correct input ");
                }
                break;

            }
            case 6: {
                head=NULL;
                break;

            }
            case 7: {
                op = 13;
                break;
            }
            default: {
                printf("\nInvalid input\n");
            }

        }
    }

    return 0;
}