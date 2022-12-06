template <typename T>
class Stack
{
    private:
        class Node
        {
            public:
                T data;
                Node *next;
        };
        Node *head;
    public:
        Stack() { head = nullptr; }  
        ~Stack() 
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
            temp->next = head;
            head = temp;
        }
        T pop()
        {
            Node *temp = head;
            T data = head->data;
            head = head->next;
            delete temp;
            return data;
        }
        bool isEmpty() {return head == nullptr;}
};     
