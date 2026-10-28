#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabela_hash.h"

typedef struct hash_table {
    int size;
    int elements;
    Node** table; // TODO: decidir como será a tabela de listas
};


void freeHash(HashTable* table) {

}

void isEmpty(HashTable* table) {
    return table->elements == 0;
}

float loadFactor(HashTable* table) {
    return table->elements / table->size;
}

long hash(HashTable* table, long key) {

}

void remove(HashTable* table, long key) {

}

char* get(HashTable* table, long key) {

}

void put(HashTable* table, long key, char* value) {

}

void newHashTable() {

}

