#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum number of elements in the priority queue

typedef struct {
    int priority; // Priority of the element
    int value;    // Value of the element
} Element;

typedef struct {
    Element heap[MAX_SIZE];
    int size; // Current size of the heap
} PriorityQueue;

// Function to swap two elements
void swap(Element* a, Element* b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree rooted at index `i`
void heapify(PriorityQueue* pq, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < pq->size && pq->heap[left].priority > pq->heap[largest].priority)
        largest = left;

    if (right < pq->size && pq->heap[right].priority > pq->heap[largest].priority)
        largest = right;

    if (largest != i) {
        swap(&pq->heap[i], &pq->heap[largest]);
        heapify(pq, largest);
    }
}

// Function to insert an element into the priority queue
void insert(PriorityQueue* pq, int value, int priority) {
    if (pq->size == MAX_SIZE) {
        printf("Priority Queue is full!\n");
        return;
    }

    // Insert the new element at the end of the heap
    pq->heap[pq->size].value = value;
    pq->heap[pq->size].priority = priority;
    int i = pq->size;
    pq->size++;

    // Fix the heap property if it is violated
    while (i != 0 && pq->heap[(i - 1) / 2].priority < pq->heap[i].priority) {
        swap(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to remove and return the highest-priority element
Element remove_max(PriorityQueue* pq) {
    if (pq->size <= 0) {
        printf("Priority Queue is empty!\n");
        return (Element){-1, -1};
    }

    if (pq->size == 1) {
        pq->size--;
        return pq->heap[0];
    }

    // Store the maximum value and remove it from the heap
    Element root = pq->heap[0];
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;

    // Heapify the root
    heapify(pq, 0);

    return root;
}

// Function to print the elements of the priority queue
void print_priority_queue(PriorityQueue* pq) {
    printf("Priority Queue:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("Value: %d, Priority: %d\n", pq->heap[i].value, pq->heap[i].priority);
    }
}

// Testing the priority queue
int main() {
    PriorityQueue pq = {.size = 0};

    printf("Inserting elements into the priority queue:\n");
    insert(&pq, 10, 1);
    insert(&pq, 20, 2);
    insert(&pq, 30, 3);
    insert(&pq, 40, 4);
    insert(&pq, 50, 5);
    print_priority_queue(&pq);

    printf("\nRemoving elements from the priority queue:\n");
    while (pq.size > 0) {
        Element max = remove_max(&pq);
        printf("Removed: Value = %d, Priority = %d\n", max.value, max.priority);
        print_priority_queue(&pq);
        printf("\n");
    }

    return 0;
}
