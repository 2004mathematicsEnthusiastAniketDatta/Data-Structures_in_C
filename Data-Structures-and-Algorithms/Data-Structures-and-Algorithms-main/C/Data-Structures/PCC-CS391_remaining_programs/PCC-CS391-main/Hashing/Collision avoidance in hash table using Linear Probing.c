#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct HashTable
{
    int key;
} hashTable;

int h(int k)
{
    return k % MAX;
}

void insert(hashTable *ht, int key)
{
    int index = h(key);
    int i;
    for (i = index; ht[i].key != -1;)
    {
        i = (i + 1) % MAX;
        if (i == index)
        {
            printf("OVERFLOW\n");
            exit(0);
        }
    }
    ht[i].key = key;
}

int search(hashTable *ht, int key)
{
    int index = h(key);
    int i;
    for (i = index; ht[i].key != key;)
    {
        i = (i + 1) % MAX;
        if (i == index)
            return -1;
    }
    return i;
}

void delete(hashTable *ht, int key)
{
    int pos = search(ht, key);
    if (pos != -1)
        ht[pos].key = -1;
    else
        printf("%d is not in the hash table\n",key);
}

void display(hashTable *ht)
{
    int i, n = 0;
    for (i = 0; i < MAX; i++)
    {
        if (ht[i].key != -1)
            printf("%d\t", ht[i].key);
        else
            n++;
    }
    if (n == MAX)
        printf("HASHTABLE IS EMPTY\n");
    else
        printf("\n");
}

void main()
{
    hashTable ht[MAX];
    int i;
    for (i = 0; i < MAX; i++)
        ht[i].key = -1;
    int n, x;
    printf("Enter the number of values you want to enter : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the value : ");
        scanf("%d", &x);
        insert(ht, x);
    }
    display(ht);
    printf("Enter the value you want to search for : ");
    scanf("%d", &n);
    int pos = search(ht, n);
    if (pos != -1)
        printf("%d is in the hash table at index %d\n", n, pos);
    else
        printf("%d is not in the hash table\n", n);
    printf("Enter the value you want to delete : ");
    scanf("%d", &n);
    delete (ht, n);
    display(ht);
}
