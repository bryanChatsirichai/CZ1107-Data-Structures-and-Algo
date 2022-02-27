#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 11
#define PRIME     3

enum Marker {EMPTY,USED,DELETED};

typedef struct _slot{
    int key;
    enum Marker indicator;
} HashSlot;

int HashInsert(int key, HashSlot hashTable[]);
int HashDelete(int key, HashSlot hashTable[]);


int hash1(int key);
int hash2(int key);
int hash3(int key,int i);

int main()
{
    int opt;
    int i;
    int key;
    int comparison;
    HashSlot hashTable[TABLESIZE];

    for(i=0;i<TABLESIZE;i++){
        hashTable[i].indicator = EMPTY;
        hashTable[i].key = 0;
    }

    printf("============= Hash Table ============\n");
    printf("|1. Insert a key to the hash table  |\n");
    printf("|2. Delete a key from the hash table|\n");
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
            comparison = HashInsert(key,hashTable);
            if(comparison <0)
                printf("Duplicate key\n");
            else if(comparison < TABLESIZE)
                printf("Insert: %d Key Comparisons: %d\n",key, comparison);
            else
                printf("Key Comparisons: %d. Table is full.\n",comparison);
            break;
        case 2:
            printf("Enter a key to be deleted:\n");
            scanf("%d",&key);
            comparison = HashDelete(key,hashTable);
            if(comparison <0)
                printf("%d does not exist.\n", key);
            else if(comparison <= TABLESIZE)
                printf("Delete: %d Key Comparisons: %d\n",key, comparison);
            else
                printf("Error\n");
            break;
        case 3:
            for(i=0;i<TABLESIZE;i++) printf("%d: %d %c\n",i, hashTable[i].key,hashTable[i].indicator==DELETED?'*':' ');
            break;
        }
        printf("Enter selection: ");
        scanf("%d",&opt);
    }
    return 0;
}

int hash1(int key)
{
    return (key % TABLESIZE);
}

int hash2(int key)
{
    return (key % PRIME) + 1;
}

int hash3(int key,int i)
{
    return (hash1(key) + (i * hash2(key))) % TABLESIZE;
}

int HashInsert(int key, HashSlot hashTable[])
{
    int i = 0;
    int index,compair = 0;
    int saved_index,new_index;
    saved_index = -1;
    new_index = -1;

    while(i < TABLESIZE)
    {
        index = hash3(key,i);
        if(hashTable[index].indicator == EMPTY)
        {
            ///if have empty slot dunid jump further
            //hashTable[index].indicator = USED;
             //hashTable[index].key = key;
             new_index = index;
             break;

        }
        else if(hashTable[index].key == key && hashTable[index].indicator == USED)
        {
            //duplicate
            return -1;
        }
        else if( hashTable[index].indicator == USED)
        {
            //clash
            compair++;
        }
        else if( hashTable[index].indicator == DELETED && saved_index == -1)
        {
            //saved the deleted slot but need check if behind still got the number
            saved_index = index;
        }
        i++;
    }
    printf("i is %d\n",i);
    if(saved_index != -1 && i < TABLESIZE)
    {
         hashTable[saved_index].key = key;
         hashTable[saved_index].indicator = USED;
         return compair;

    }
    else if(new_index != -1 && i < TABLESIZE)
    {
         hashTable[new_index].key = key;
         hashTable[new_index].indicator = USED;
         return compair;
    }
    else
    {
        return TABLESIZE;
    }

}

int HashDelete(int key, HashSlot hashTable[])
{
   int i = 0,index;
   int compair = 0;
   while(i < TABLESIZE)
   {
       index = hash3(key,i);
       if(hashTable[index].key == key && hashTable[index].indicator == USED)
       {
           hashTable[index].indicator = DELETED;
           return i + 1;
       }

       i++;
       printf("i is %d\n",i);
   }
   return -1;

}
