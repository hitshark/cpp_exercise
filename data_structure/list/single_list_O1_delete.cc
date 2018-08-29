#include <iostream>

using Node_t = struct Node {
    int dat;
    Node *next;
    Node(int i = 0, Node *nt=nullptr) : dat(i), next(nt) {}
};

void list_del(Node_t *head, Node_t *del_node) {
    if(head == nullptr || del_node == nullptr) {
        std::cout<<"wrong arguments\n";
        abort();
    }
    else {
        Node_t *tmp = del_node->next;
        if(nullptr == tmp) {
            std::cout<<"last node to delete\n";
            abort();
        }
        else {
            del_node->dat = tmp->dat;
            del_node->next = tmp->next;
        }
    }
}

void disp(Node_t *head) {
    while(head->next != nullptr) {
        std::cout<<head->next->dat<<std::endl;
        head = head->next;
    }
}

int main()
{
    Node_t *head = new Node_t();
    Node_t *del_node;
    for(int i=1; i<10; i++) {
        Node_t *tmp = new Node_t(i, nullptr);
        tmp->next = head->next;
        head->next = tmp;
        if(i == 5) del_node = tmp;
    }
    list_del(head, del_node);
    disp(head);

    return 0;
}
