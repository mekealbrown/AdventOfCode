#include <iostream>
template <typename T>
class Queue
{
    private:
        class Node
        {
            public:
                T data;
                Node *next;
        };
        Node *head;
        Node *tail;
    public:
        Queue() { head = NULL; tail = nullptr;}  
        ~Queue() 
        {                         
            Node *current = head;
            while (current != nullptr) 
            {
                Node *next = current->next; 
                delete current;
                current = next;
            }
        }
        void push(const T &x)
        {
            Node *temp = new Node;
            temp->data = x;
            if (tail == nullptr)
            {
                head = temp;
                tail = temp;
                return;
            }
            tail->next = temp;
            tail = temp;
        }
        T pop()
        {
            Node *temp = head;
            T data = temp->data;
            head = temp->next;
            delete temp;
            return data;
        }
        bool isEmpty() {return tail == nullptr || head == nullptr;}
        void print()
        {
            Node *temp = head;
            while (temp != nullptr)
            {
                std::cout << temp->data << " - ";
                temp = temp->next;
            }
        }
};     
