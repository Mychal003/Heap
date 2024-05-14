#include <iostream>
#include <stdexcept>
#include <chrono>

template<typename T>
class PriorityQueue {
private:
    std::pair<T, int>* heap; // Tablica przechowująca pary elementów i ich priorytetów
    int capacity; // Maksymalna pojemność kopca
    int size; // Aktualna liczba elementów w kopcu

    void expandHeap() {
        int newCapacity = capacity * 2;
        std::pair<T, int>* newHeap = new std::pair<T, int>[newCapacity];
        for (int i = 0; i < size; i++) {
            newHeap[i] = heap[i]; // Kopiowanie elementów do nowej tablicy
        }
        delete[] heap;
        heap = newHeap;
        capacity = newCapacity;
    }

    void heapifyDown(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // Szukanie większego dziecka
        if (left < size && heap[left].second > heap[largest].second) {
            largest = left;
        }
        if (right < size && heap[right].second > heap[largest].second) {
            largest = right;
        }
        // Jeśli znaleziono większe dziecko, zamień i kontynuuj heapify
        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    void heapifyUp(int index) {
        // Porównanie z rodzicem i zamiana, jeśli konieczne
        while (index != 0 && heap[(index - 1) / 2].second < heap[index].second) {
            std::swap(heap[(index - 1) / 2], heap[index]);
            index = (index - 1) / 2;
        }
    }

public:
    PriorityQueue() : capacity(10), size(0) {
        heap = new std::pair<T, int>[capacity];
    }

    ~PriorityQueue() {
        delete[] heap;
    }

    void insert(T item, int priority) {
        if (size == capacity) {
            expandHeap(); // Zwiększenie rozmiaru tablicy, gdy jest pełna
        }
        heap[size] = {item, priority};
        heapifyUp(size); // Utrzymanie właściwości kopca po dodaniu elementu
        size++;
    }

    T pop() {
        if (isEmpty()) {
            throw std::runtime_error("Heap is empty");
        }
        T item = heap[0].first;
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0); // Utrzymanie właściwości kopca po usunięciu korzenia
        return item;
    }

    T peek() {
        if (isEmpty()) {
            throw std::runtime_error("Heap is empty");
        }
        return heap[0].first; // Zwraca element z najwyższym priorytetem
    }

    bool isEmpty() const {
        return size == 0;
    }
};

int main() {
    PriorityQueue<std::string> queue;
    std::chrono::high_resolution_clock::time_point begin, end;
    std::chrono::duration<double, std::nano> time_span;

    begin = std::chrono::high_resolution_clock::now();
    queue.insert("task1", 3);
    end = std::chrono::high_resolution_clock::now();
    time_span = end - begin;
    std::cout << "Time difference for inserting task1 = " << time_span.count() << "ns" << std::endl;

    begin = std::chrono::high_resolution_clock::now();
    queue.insert("task2", 2);
    end = std::chrono::high_resolution_clock::now();
    time_span = end - begin;
    std::cout << "Time difference for inserting task2 = " << time_span.count() << "ns" << std::endl;

    begin = std::chrono::high_resolution_clock::now();
    queue.insert("task3", 1);
    end = std::chrono::high_resolution_clock::now();
    time_span = end - begin;
    std::cout << "Time difference for inserting task3 = " << time_span.count() << "ns" << std::endl;

    begin = std::chrono::high_resolution_clock::now();
    queue.insert("task4", 4);
    end = std::chrono::high_resolution_clock::now();
    time_span = end - begin;
    std::cout << "Time difference for inserting task4 = " << time_span.count() << "ns" << std::endl;

    std::cout << "Peek: " << queue.peek() << std::endl;
    std::cout << "Pop: " << queue.pop() << std::endl;
    std::cout << "After pop, Peek: " << queue.peek() << std::endl;
    std::cout << "*********************************************************************************************************************" <<std::endl;
//*****************************************************************************************************************************8
    //Dla int
//******************************************************************************************************************************
    PriorityQueue<int> queueInt;
    // Używaj różnych nazw zmiennych dla każdego pomiaru czasu, aby uniknąć konfliktu
    std::chrono::high_resolution_clock::time_point begin1, end1;
    std::chrono::duration<double, std::nano> time_span1;

    begin1 = std::chrono::high_resolution_clock::now();
    queueInt.insert(10, 3);
    end1 = std::chrono::high_resolution_clock::now();
    time_span1 = end1 - begin1;
    std::cout << "Time difference for inserting int 10 with priority 3 = " << time_span1.count() << "ns" << std::endl;

    std::chrono::high_resolution_clock::time_point begin2, end2;
    std::chrono::duration<double, std::nano> time_span2;

    begin2 = std::chrono::high_resolution_clock::now();
    queueInt.insert(20, 2);
    end2 = std::chrono::high_resolution_clock::now();
    time_span2 = end2 - begin2;
    std::cout << "Time difference for inserting int 20 with priority 2 = " << time_span2.count() << "ns" << std::endl;

    std::chrono::high_resolution_clock::time_point begin3, end3;
    std::chrono::duration<double, std::nano> time_span3;

    begin3 = std::chrono::high_resolution_clock::now();
    queueInt.insert(30, 1);
    end3 = std::chrono::high_resolution_clock::now();
    time_span3 = end3 - begin3;
    std::cout << "Time difference for inserting int 30 with priority 1 = " << time_span3.count() << "ns" << std::endl;

    std::chrono::high_resolution_clock::time_point begin4, end4;
    std::chrono::duration<double, std::nano> time_span4;

    begin4 = std::chrono::high_resolution_clock::now();
    queueInt.insert(40, 4);
    end4 = std::chrono::high_resolution_clock::now();
    time_span4 = end4 - begin4;
    std::cout << "Time difference for inserting int 40 with priority 4 = " << time_span4.count() << "ns" << std::endl;
std::cout << "*********************************************************************************************************************" <<std::endl;
//********************************************************************************************************************************
    //Dla typu float
//********************************************************************************************************************************

    PriorityQueue<float> queueFloat;
    std::chrono::high_resolution_clock::time_point beginF1, endF1;
    std::chrono::duration<double, std::nano> time_spanF1;

    beginF1 = std::chrono::high_resolution_clock::now();
    queueFloat.insert(10.1f, 3);
    endF1 = std::chrono::high_resolution_clock::now();
    time_spanF1 = endF1 - beginF1;
    std::cout << "Time difference for inserting float 10.1 with priority 3 = " << time_spanF1.count() << "ns" << std::endl;

    std::chrono::high_resolution_clock::time_point beginF2, endF2;
    std::chrono::duration<double, std::nano> time_spanF2;

    beginF2 = std::chrono::high_resolution_clock::now();
    queueFloat.insert(20.2f, 2);
    endF2 = std::chrono::high_resolution_clock::now();
    time_spanF2 = endF2 - beginF2;
    std::cout << "Time difference for inserting float 20.2 with priority 2 = " << time_spanF2.count() << "ns" << std::endl;

    std::chrono::high_resolution_clock::time_point beginF3, endF3;
    std::chrono::duration<double, std::nano> time_spanF3;

    beginF3 = std::chrono::high_resolution_clock::now();
    queueFloat.insert(30.3f, 1);
    endF3 = std::chrono::high_resolution_clock::now();
    time_spanF3 = endF3 - beginF3;
    std::cout << "Time difference for inserting float 30.3 with priority 1 = " << time_spanF3.count() << "ns" << std::endl;

    std::chrono::high_resolution_clock::time_point beginF4, endF4;
    std::chrono::duration<double, std::nano> time_spanF4;

    beginF4 = std::chrono::high_resolution_clock::now();
    queueFloat.insert(40.4f, 4);
    endF4 = std::chrono::high_resolution_clock::now();
    time_spanF4 = endF4 - beginF4;
    std::cout << "Time difference for inserting float 40.4 with priority 4 = " << time_spanF4.count() << "ns" << std::endl;
    return 0;
}
