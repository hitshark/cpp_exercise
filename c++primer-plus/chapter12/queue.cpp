#include <cstdlib>
#include <ctime>
#include <iostream>
#include "queue.hpp"

/*
void Customer::set(long when, int thrd)
{
    arrive_ = when;
    ptm_ = std::rand() % 3 + 1;
    thrd_ = thrd;
}
*/
void Customer::set(long when, int ptm, int thrd)
{
    arrive_ = when;
    ptm_ = std::rand() % ptm + 1;
    thrd_ = std::rand() % thrd + 1;
}

Queue::Queue(int qs):qsize_(qs)
{
    front_ = rear_ = nullptr;
    items_ = 0;
}

Queue::~Queue()
{
    Node *temp;
    while(front_ != nullptr){
        temp = front_;
        front_=front_->next;
        delete temp;
    }
}

bool Queue::EnQueue(const Item &item)
{
    if(IsFull()) return false;

    Node *temp = new Node;
    temp->item = item;
    temp->next = nullptr;

    if(front_ == nullptr) front_ = rear_ = temp;
    else{
        rear_->next = temp;
        rear_ = temp;
    }
    items_++;
    return true;
}

bool Queue::DeQueue(Item &item)
{
    if(IsEmpty()) return false;
    item = front_->item;
    Node *temp = front_;
    front_ = front_->next;
    if(front_ == nullptr) rear_ = nullptr;
    items_--;
    delete temp;
    return true;
}

