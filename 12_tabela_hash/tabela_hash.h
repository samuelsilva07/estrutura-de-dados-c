#ifndef HASH_H
#define HASH_H

typedef struct _hash_table HashTable;
typedef struct _node Node;

void freeHash(HashTable* table);
void isEmpty(HashTable* table);
float loadFactor(HashTable table);
long hash(HashTable* table, long key);
void remove(HashTable* table, long key);
char* get(HashTable* table, long key);
void put(HashTable* table, long key, char* value);
void newHashTable();

#endif
