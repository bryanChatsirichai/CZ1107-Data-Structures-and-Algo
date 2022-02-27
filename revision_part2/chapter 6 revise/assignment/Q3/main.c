#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 10
#define PRIME     13

enum Marker {EMPTY,USED};

typedef struct _slot{
    int key;
    enum Marker indicator;
    int next;
} HashSlot;

int HashInsert(int key, HashSlot hashTable[]);
int HashFind(int key, HashSlot hashTable[]);

int hash(int key)
{
    return (key % TABLESIZE);
}

int main()
{
    int opt;
    int i;
    int key;
    int index;
    HashSlot hashTable[TABLESIZE];

    for(i=0;i<TABLESIZE;i++){
        hashTable[i].next = -1;
        hashTable[i].key = 0;
        hashTable[i].indicator = EMPTY;
    }

    printf("============= Hash Table ============\n");
    printf("|1. Insert a key to the hash table  |\n");
    printf("|2. Search a key in the hash table  |\n");
    printf("|3. Print the hash table            |\n");
    printf("|4. Quit                            |\n");
    printf("=====================================\n");

    printf("Enter selection: ");
    scanf("%d",&opt);
    while(opt>=1 && opt <=3){
        switch(opt){
        case 1:
            printf("Enter a key to be inserted:\n");
            scanf("%d",&key);
            index = HashInsert(key,hashTable);
            if(index <0)
                printf("Duplicate key\n");
            else if(index < TABLESIZE)
                printf("Insert %d at index %d\n",key, index);
            else
                printf("Table is full.\n");
            break;
        case 2:
            printf("Enter a key for searching in the HashTable:\n");
            scanf("%d",&key);
            index = HashFind(key, hashTable);

            if(index!=-1)
                printf("%d is found at index %d.\n",key,index);
            else
                printf("%d is not found.\n",key);
            break;

        case 3:
            printf("index:\t key \t next\n");
            for(i=0;i<TABLESIZE;i++) printf("%d\t%d\t%d\n",i, hashTable[i].key,hashTable[i].next);
            break;
        }
        printf("Enter selection: ");
        scanf("%d",&opt);
    }
    return 0;
}

int HashInsert(int key, HashSlot hashTable[])
{
    int i = 1;
    int new_index,prev_index,index,next_index;
    index  = hash(key);

    if(hashTable[index].indicator == EMPTY )
    {
        ///original slot empty no need jump
        hashTable[index].key = key;
        hashTable[index].indicator = USED;
        return index;
    }
    //printf("index is %d\n",index);
    while(hashTable[index].next != -1 && hashTable[index].key != key)
    {
        ///jump as far as can and no duplicate
        index = hashTable[index].next;
    }
    if(hashTable[index].key == key)
    {
        return -1;
    }

    printf("index now at %d\n",index);

    new_index = (index + i) % TABLESIZE; ///check the next index since we stop at currently used
    prev_index = index; //pre index will point to the new jump location of the current index
    while(new_index != index)
    {
        if(hashTable[new_index].indicator == EMPTY)
        {
            hashTable[new_index].key = key;
            hashTable[new_index].indicator = USED;
            hashTable[prev_index].next = new_index;
            return new_index;
        }
        else
        {
            i++;
            new_index = (index + i) % TABLESIZE; ///check the next index since we stop at currently used

        }
        printf("new_index is %d pre_index is %d\n",new_index,prev_index);
        printf("i is %d\n",i);
    }
     printf("i is %d\n",i); /// max i will be is table size as it check all the slot once
    return TABLESIZE; ///check the entire list

}

int HashFind(int key, HashSlot hashTable[])
{
    int index;
    index = hash(key);
    if(hashTable[index].key == key && hashTable[index].indicator == USED)
    {
        return index;
    }
    else
    {
        while(index != -1) ///go through all jump index next is -1 mean key not in table
        {
            if(hashTable[index].key == key)
            {
                printf("found\n");
                return index;
            }
            else
            {
                index = hashTable[index].next;
            }
            printf("index is %d\n",index);
        }
        return -1; //all jump index no have mean key not in table
    }
}
