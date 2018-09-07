#ifndef _QUEUE_H_
#define _QUEUE_H_

class Customer
{
    public:
        Customer(){arrive_ = ptm_ = thrd_ = 0;};
        void set(long when, int ptm = MAX_PTM, int thrd = MAX_TM);
        long when() const{return arrive_;}
        int ptime() const{return ptm_;}
        int mtime() const{return thrd_;}

    private:
        enum {
            MAX_TM = 100,
            MAX_PTM = 5
        };
        long arrive_;
        int ptm_;
        int thrd_;      // the max time a customer can stand;
};

typedef Customer Item;
class Queue
{
    private:
        struct Node{
            Item item;
            struct Node *next;
        };
        enum {Q_SIZE = 10};

    public:
        Queue(int qs = Q_SIZE);
        ~Queue();
        bool IsEmpty() const{return (items_ == 0);};
        bool IsFull() const{return (items_ == qsize_);};
        int QueueCount() const{return items_;};

        bool EnQueue(const Item & item);
        bool DeQueue(Item & item);

    private:
        Node *front_;
        Node *rear_;
        int items_;
        const int qsize_;

        Queue(const Queue & q):qsize_(0){}
        Queue & operator=(const Queue & q){return *this;}
};

#endif

