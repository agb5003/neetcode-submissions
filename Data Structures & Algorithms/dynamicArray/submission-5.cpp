class DynamicArray {
private:
    int capacity;
    int size = 0;
    int *payload;
public:

    DynamicArray(int capacity) {
        this->capacity = capacity;
        this->payload = (int *)malloc(capacity * sizeof(int));
    }

    int get(int i) {
        return payload[i];
    }

    void set(int i, int n) {
        if (i >= this->size) this->size = i+1;
        payload[i] = n;
    }

    void pushback(int n) {
        if (this->size == this->capacity) resize();
        payload[size] = n;
        size++;
    }

    int popback() {
        int retval = payload[this->size - 1];
        this->size--;
        return retval;
    }

    void resize() {
        // Allocate new array 2x old capacity
        payload = (int *)realloc(payload, 2 * this->capacity * sizeof(int));
        this->capacity *= 2;
    }

    int getSize() {
        return this->size;
    }

    int getCapacity() {
        return this->capacity;
    }
};
