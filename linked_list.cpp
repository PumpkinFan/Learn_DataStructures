#include <iostream>

struct Node {
    int data;
    Node *link;  // pointer to a node
};


class LinkedList {
    private:
        Node *head, *tail;  // head = ptr to first node, tail = ptr to last node
    public:
        LinkedList() {
            head = nullptr;
            tail = nullptr;
        }

        // copy constructor
        LinkedList(const LinkedList &ell) {
            head = ell.head;
            tail = ell.tail;
        }

        Node* get_head() {
            return head;
        }

        Node* get_tail() {
            return tail;
        }

        void add_node(int n) {
            Node *tmp = new Node;
            tmp->data = n;
            tmp->link = nullptr;
            if (head == nullptr) {
                head = tmp;
                tail = tmp;
            }
            else {
                tail->link = tmp;
                tail = tail->link;
            }
        }
        
        void print_node(int i) {
            Node *tmp_ptr = head; 
            for (auto itr = 0; itr < i; itr++) {
                // std::cout << itr << std::endl;
                tmp_ptr = tmp_ptr->link;
                if (tmp_ptr == nullptr) {
                    break;
                }
            }
            if (tmp_ptr == nullptr) {
                std::cout << "Index too large. Not in range of list." << std::endl;
            }
            else {
                std::cout << tmp_ptr->data << std::endl;
            }
            
        }

        void display() {
            Node *temp = new Node;
            temp = head;
            while (temp != nullptr) {
                std::cout << temp->data << std::endl;
                temp = temp->link;
            }
        }

        void insert_at_start(int val) {
            Node *new_ptr = new Node;
            new_ptr->data = val;
            new_ptr->link = head;
            head = new_ptr;
        }

        void insert(int val, unsigned int ind) {
            // does not work properly
            Node *new_ptr = new Node;
            new_ptr->data = val;
            new_ptr->link = head;
            head = new_ptr;
            Node *prev_ptr;
            for (unsigned int i = 0; i <= ind; ++i) {
                if (head == new_ptr) {
                    prev_ptr = head;
                    head = new_ptr->link;
                }
                Node *next_link = new_ptr->link->link;
                prev_ptr->link = new_ptr;
                prev_ptr = new_ptr->link;
                new_ptr->link = next_link;
            }
        }

        void concat_list(LinkedList target_list) {
            auto target_head = target_list.get_head();
            tail->link = target_head;
        }

        static LinkedList concatenate (LinkedList list1, LinkedList list2) {
            LinkedList result;
            result = list1;
            result.tail->link = list2.get_head();
            return result;
        }
};

int main() {
    LinkedList a;
    a.add_node(1);
    a.add_node(10);
    a.add_node(3);
    a.add_node(92);
    a.display();

    std::cout << "\n";

    a.insert(1024, 1);
    a.display();
    // LinkedList b;
    // b.add_node(314);
    // b.add_node(420);

    // auto c = LinkedList::concatenate(a, b);
    // c.print_node(0);
    // c.print_node(4);
    // return 0;
}

/* attempt at insert anywhere

            unsigned int i = 0;
            while (i < ind && new_ptr->link != nullptr) {
                if (head == new_ptr) {
                    head = new_ptr->link;  // reset head to old first element
                }
                Node *next_link = new_ptr->link->link;
                new_ptr->link->link = new_ptr;
                new_ptr->link = next_link;
                i++;
            }
*/