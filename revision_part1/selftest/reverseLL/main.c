#include <stdio.h>
#include <stdlib.h>

typedef struct _listnode{
    int item;
    struct _listnode *next;

}ListNode;

typedef struct _linkList{
    int size;
    ListNode *head;
    ListNode *tail;

}LinkedList;

///LinkedList functions///
void insertNode(LinkedList *ll,int index,int value);
void printList(LinkedList *ll);
void removeNode(LinkedList *ll,int index);
ListNode *findNode(LinkedList *ll,int index);

void reverseLL(LinkedList *ll);

int main()
{
    LinkedList ll;
    ll.size = 0;
    ll.head = ll.tail = NULL;
    int option,index,value;
    printf("Enter Option -1 to quit\n");
    scanf("%d",&option);
    while(option != -1)
    {
        switch(option)
        {
            case 1:
                printf("Enter Index\n");
                scanf("%d",&index);
                printf("Enter value\n");
                scanf("%d",&value);
                insertNode(&ll,index,value);
                //insertNode(&ll,ll.size,value);
                break;
            case 2:
                printf("The Linklist :\n");
                printList(&ll);
                break;
            case 3:
                printf("Enter Index to remove\n");
                scanf("%d",&index);
                removeNode(&ll,index);
                break;
            case 4:
                printf("Reverse Linked list\n");
                reverseLL(&ll);
                printList(&ll);
                break;
            default:
                printf("Default value entered\n");
                break;
        }
    printf("Enter Option -1 to quit\n");
        scanf("%d",&option);
    }
    return 0;
}
void reverseLL(LinkedList *ll){
    ListNode *r,*p,*q,*temp;
    if(ll->head == NULL)
        return;
    else
    {
        r = NULL;
        p = NULL;
        q = ll->head;
        while(q != NULL)
        {
            r = p;
            p = q;
            q = q->next;
            p->next = r;
        }
        temp = ll->head;
        ll->head = ll->tail;
        ll->tail = temp;
    }
}



ListNode *findNode(LinkedList *ll,int index){
    ListNode *temp;
    if(ll== NULL || ll->head == NULL || index < 0 )
    {
        printf("FindNode Error 1\n");
        return NULL;
    }
    else
    {
        temp = ll->head;
        while(index != 0)
        {
            if(temp == NULL)
            {
                //overshot
                return NULL;
            }
            temp = temp->next;
            index--;
        }
        return temp;
    }
}
void insertNode(LinkedList *ll,int index,int value){
    ListNode *pre,*cur,*temp;

    if(ll == NULL || index < 0 || index > ll->size + 1)
    {
        printf("InsertNode error 1\n");
        return;
    }

    // If empty list or inserting first node, need to update head pointer
    if(ll->head == NULL || index == 0)
    {
        printf("Insert option 1\n");
        cur = ll->head;
        temp = (ListNode*)malloc(sizeof(ListNode));
        temp->item = value;
        temp->next = cur;
        ll->head = temp;
        if(ll->size == 0)
        {
            ll->tail = ll->head;
        }
        ll->size++;
        return;
    }
    // Inserting as new last node
    if(index == ll->size)
    {
        printf("Insert option 2\n");
        pre = ll->tail;
        ll->tail = (ListNode*)malloc(sizeof(ListNode));
        ll->tail->item = value;
        ll->tail->next = NULL;
        pre->next = ll->tail;
        ll->size++;
        return;
    }
    // Find the nodes before and at the target position
	// Create a new node and reconnect the links
    if( (pre = findNode(ll,index - 1)) != NULL)
    {
        printf("Insert Option 3\n");
        cur = pre->next;
        temp = (ListNode *)malloc(sizeof(ListNode));
        temp->item = value;
        temp->next = cur;
        pre->next = temp;
        ll->size++;
        return;
    }
}
void printList(LinkedList *ll){
    ListNode *temp;
    temp = ll->head;
    if(ll->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    else
    {
        while(temp!= NULL)
        {
            printf("%d ",temp->item);
            temp = temp->next;
        }
        printf("\n");
        return;
    }
}
void removeNode(LinkedList *ll,int index){
    ListNode *pre,*cur,*temp;
    if(ll == NULL || index < 0 || index >= ll->size )
    {
        printf("RemoveNode error 1 \n");
        return;
    }
    if(ll->head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if(index == 0)
    {
        cur = ll->head->next;
        free(ll->head);
        ll->head = cur;
        ll->size--;
        if(ll->size == 0)
        {
            //if the linked list is empty tail will not be pointed to anything
            ll->head = NULL;
        }
        return;
    }

    // Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if( (pre = findNode(ll,index - 1 )) != NULL )
    {

        // Removing the last node, update the tail pointer
        if(index == ll->size - 1)
        {   //last node of linklist
            temp = ll->tail;
            free(temp);
            ll->tail = pre;
            pre->next = NULL;
        }
        else
        {
            temp = pre->next; //to be remove
            cur = temp->next;
            free(temp);
            pre->next = cur;

        }
        ll->size--;
        return;
    }


}
