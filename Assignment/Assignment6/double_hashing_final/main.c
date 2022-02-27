#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 37
#define PRIME     13

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
    // will be used if there is a collision
    /*
     hash 2 has 2 desired properties, should not give a result 0
     Its should  try to probe all location,whenever there is a collision it should not give
     indices in the same pattern should give different indices so all utilize.
     Therefore suggested use with a prime number
      */
    return (key % PRIME) + 1;
}

int hash3(int key,int i)
{
    // combine hash 1 and hash 2
    // if i = 0 we using this for first time same as using hash 1 only
    // else i >= 1,2,... same as how many times calling hash 2
    //thus hash 1 + hash 2 will give new index position
   return (hash1(key) + (i * hash2(key) ) ) % TABLESIZE;


}

int HashInsert(int key, HashSlot hashTable[])
{
   // key compair when there is a collision
    int i = 0 ,new_index = -1,save_index = -1,comparision = 0;

    int index;

    while(i < TABLESIZE) // maximum amount of iteration equal to table size ==> check every slot
    {
        index = hash3(key,i); //prone to next index

        if(hashTable[index].indicator == EMPTY )
        {
            //implies the key has not in the hashtable
            // has not been inserted and deleted before
            //also use as a stop indicator that since empty the key is not inserted further based on the prone pattern
            //as if it is empty that means the next i+1 to the hash3() will also be empty
            new_index = index;
            break;
        }
        else if(hashTable[index].indicator == DELETED && save_index == -1)
        {
                /*
                if slot has been deleted save the index and check
                the hash table if the key appears.
                Therefore if the key not in the table this first
                'empty' slot from the prone sequence will be used to store the key.
                we do not break of the iteration as we are not sure if through the
                probing sequence the key is still in some slot
                */

                save_index = index;
        }
        else if(hashTable[index].indicator == USED && hashTable[index].key == key)
        {
            // duplicate encounter while iterating through the hash sequence
            return -1;
        }
        else if(hashTable[index].indicator == USED)
        {
            //collision happen when the key clash with a used slot
            //Empty or deleted the slot is consider empty so key cannot clash with anything
            comparision++;
        }

            i++; //increment to allow the hash function to prone to next available index

    }
    //printf("index i is %d\n",i);
    if(save_index != -1)
    {
        /*
        I gave this highest priority as if pass by a deleted_slot
        before empty and key not inside hash table insert it a the deleted node
        */
            hashTable[save_index].indicator = USED;
            hashTable[save_index].key = key;
            return comparision;
    }
    else if(i< TABLESIZE)
    {
            /*
            check through hash table and found an empty slot
            If there is no deleted slot the key will be inserted here
            as all the previous probing movement the slots are Used.
            */
            hashTable[new_index].indicator = USED;
            hashTable[new_index].key = key;
            return comparision;
    }
    else
    {
        /*
        Check all the slots in the hash tableand all the slots are filled
        maximum iteration is the tablesize or how many slots there are
        */
        return TABLESIZE;
    }
}

int HashDelete(int key, HashSlot hashTable[])
{
       // key compair when there is a collision
    int i = 0;

    int index;

    while(i < TABLESIZE)
    {
        index = hash3(key,i);
        if(hashTable[index].indicator == USED && hashTable[index].key == key)
        {   //empty so no collision count
            hashTable[index].indicator = DELETED ;
            return i + 1;
        }

        else
        {
            i++;
        }


    }
    return -1; //key was not found
}
