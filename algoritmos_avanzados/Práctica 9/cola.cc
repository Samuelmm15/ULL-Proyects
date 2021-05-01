/**
 * @file cola.cc
 * @author Samuel Martín Morales (alu0101359526@ull.edu.es)
 * @brief Clase cola
 * @version 0.1
 * @date 2021-05-01
 * 
 * @copyright Copyright (c) 2021
 * 
 */
 
#include <iostream>
using namespace std;

struct Node {
    int date;
    Node *next;
};

template<typename K>
class Queue {
    private:
    Node *front;
    Node *end;
    public:
    Queue();
    void insert(Node *&, Node *&, int);
    bool empty(Node *);
    int extract(Node *, Node *);
};

template<typename K>
Queue<K>::Queue() {
    front = NULL;
    end = NULL;
};

template<typename K>
void Queue<K>::insert(Node *&front, Node *&end, int number) {
    Node *new_node = new Node();
    new_node->date = number;
    new_node->next = NULL;

    if (empty(front)) {
        front = new_node;
    }
    else {
        end->next = new_node;
    }
    end = new_node;
};

template<typename K>
bool Queue<K>::empty(Node *front) {
    if (front == NULL) {
        return true;
    }
    else {
        return false;
    }
};

template<typename K>
int Queue<K>::extract(Node *front, Node *end) {
    Node *aux;
    int number = 0;

    aux = front;
    number = aux->date;
    front = front->next;
    delete(aux);

    return number;
};