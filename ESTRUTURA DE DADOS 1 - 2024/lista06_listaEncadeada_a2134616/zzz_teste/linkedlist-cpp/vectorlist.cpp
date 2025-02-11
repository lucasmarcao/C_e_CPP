#include "vectorlist.h"
#include <cstdio>

VectorList::VectorList() {
    this->size = 0;
    this->capacity = 5;
    this->data = new int[this->capacity];

    printf("> VectorList criada.\n");
}

VectorList::~VectorList() {
    delete[] this->data;

    printf("> VectorList destruida.\n");
}

bool VectorList::resize(int new_size) {
    int* new_vec = new int[new_size];
    if (new_vec == nullptr) 
        return false;

    // copiar os elementos do list->data para new_vec
    for (int i = 0; i < this->size; i++) {
       new_vec[i] = this->data[i];
    }
    delete[] this->data;
    this->data = new_vec;
    this->capacity = new_size;

    return true;
}

bool VectorList::push_back(int elem) {
    if (this->size == this->capacity) {
        if (resize(this->capacity * 2) == false)
            return false;
    }
    this->data[this->size] = elem;
    this->size++;
    return true;
}

bool VectorList::pop_back() {
    if (this->size <= 0) 
        return false;

    this->size--;
    return true;
}

int VectorList::get(int pos) {
    if (pos < 0 || pos >= this->size) 
        printf("VectorList: element not found at pos %d\n", pos);
        return -1;

    return this->data[pos];
}

void VectorList::print() {
    printf("(%d/%d) ", this->size, this->capacity);
    for (int i = 0; i < this->size; i++) {
        printf("%d ", this->data[i]);
    }
    printf("\n");
}