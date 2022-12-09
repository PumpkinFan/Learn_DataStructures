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
        LinkedList(const LinkedList &original_list) {
            head = original_list.head;
            tail = original_list.tail;
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

        void insert_at_beginning(int val) {
            Node *new_ptr = new Node;
            new_ptr->data = val;
            new_ptr->link = head;
            head = new_ptr;
        }

        void insert(int val, unsigned int idx) {
            Node *new_ptr = new Node;
            new_ptr->data = val;
            new_ptr->link = nullptr;

            if (idx == 0) {
                new_ptr->link = head;
                head = new_ptr;
                return;
            }

            // check empty list (all point to NULL)
            if (!head && !tail && !new_ptr->link) {
                std::cout << "Insert failed. Index out of list range." << std::endl;
                return;
            }

            Node *before_ptr = head;
            for (auto itr = 0; itr < idx - 1; itr++) {
                before_ptr = before_ptr->link;
                if (before_ptr == nullptr) {
                    std::cout << "Insert failed. Index out of list range." << std::endl;
                    return;
                }
            }

            new_ptr->link = before_ptr->link;
            before_ptr->link = new_ptr; 

            if (new_ptr->link == nullptr) {
                tail = new_ptr;
            }
            
        }

        void remove_node(unsigned int idx) {
            // delete node currently at position idx

            if (!head && !tail) {
                std::cout << "Remove failed. List is empty." << std::endl;
                return;
            }

            if (idx == 0) {
                head = head->link;
                return;
            }

            Node *before_ptr = head;
            for (auto itr = 0; itr < idx - 1; ++itr) {
                before_ptr = before_ptr->link;
                if (before_ptr->link == nullptr) {
                    std::cout << "Remove failed. Index out of list range." << std::endl;
                    return;
                }
                
            }

            before_ptr->link = before_ptr->link->link;
            
            if (before_ptr->link == nullptr) {
                tail = before_ptr;
            }
        }

        void insert_old(int val, unsigned int idx) {
            // start by placing new node at beginning of linked list 
            Node *new_ptr = new Node;
            new_ptr->data = val;
            new_ptr->link = head;
            head = new_ptr;
            
            Node *prev_ptr;  // keep track of ptr to previous node in list
            unsigned int i = 1;

            // each iteration moves new node one place forward in list
            while (i <= idx) {

                if (new_ptr->link == nullptr) {
                    std::cout << "insertion failed; index larger than size of list" << std::endl;
                    prev_ptr->link = nullptr;
                    break;
                }
                // reset previous node (head for first iteration)
                if (i == 1) {
                    head = new_ptr->link;
                }
                else {
                    prev_ptr->link = new_ptr->link;
                }
                
                prev_ptr = new_ptr->link;  // update previous node pointer
                
                Node *nxt_link = new_ptr->link->link;  // store next link for new node
                new_ptr->link->link = new_ptr;  // point current link to new node
                                
                new_ptr->link = nxt_link;  // update new node link

                ++i;                    
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

    // TEST GENERAL USE INSERT FUNCTION
    // LinkedList a;
    // a.add_node(1);
    // a.add_node(10);
    // a.add_node(3);
    // a.add_node(92);
    //
    // std::cout << "\n";
    //
    // a.insert(1024, 4);
    // a.display();
    //
    // std::cout << "\n" << a.get_tail()->data << std::endl;

    LinkedList test_list;
    test_list.add_node(12);
    test_list.add_node(14);
    test_list.add_node(17);
    test_list.add_node(365);
    test_list.remove_node(3);

    test_list.display();

    std::cout << "\n";
    LinkedList b;
    b.insert(42, 10);
    b.display();
}
