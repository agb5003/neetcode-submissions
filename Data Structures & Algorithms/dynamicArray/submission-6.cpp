#include <iostream>

class DynamicArray {
private:
    int* head;
    int size = 0;
    int capacity;
public:
    DynamicArray(int capacity) {
        this->capacity = capacity;
        head = (int*)malloc(sizeof(int) * capacity);
    }

    int get(int i) {
        return head[i];
        // return *(head + sizeof(int) * i);
    }

    void set(int i, int n) {
        if (i > size-1) size = i; // Update size if i is bigger than current size
        head[i] = n;
    }

    void pushback(int n) {
        if (size == capacity) resize();
        head[size] = n;
        size++;
    }

    int popback() {
        int temp = head[size-1];
        size--;
        return temp;
    }

    void resize() {
        // Double capacity
        head = (int*)realloc(head, 2*capacity*sizeof(int));
        capacity *= 2;
    }

    int getSize() {
        return size;   
    }

    int getCapacity() {
        return capacity;
    }
};