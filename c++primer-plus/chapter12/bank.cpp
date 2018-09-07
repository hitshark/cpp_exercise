#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.hpp"

const int CYCLE_PER_HR = 60;
bool newcustomer(double x){return (std::rand()*x/RAND_MAX < 1);}

int main(int argc, char *argv[])
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    std::srand(std::time(0));
    cout << "case study: bank of heather automatic teller\n";
    cout << "enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);

    cout << "enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = CYCLE_PER_HR * hours;

    cout << "enter the average number of customers per hour: ";
    double perhour;
    cin >> perhour;
    double min_per_cust = CYCLE_PER_HR / perhour;

    // the main function loop
    Item temp;
    long turnaways = 0;
    long leaves = 0;
    long customers = 0;
    long served = 0;
    long sum_line = 0;
    long wait_time = 0;
    long line_wait = 0;
    int idle = 1;

    for(int cycle=0; cycle<cyclelimit; cycle++)
    {
        // customer calls for a number
        if(newcustomer(min_per_cust)){
            if(!line.IsFull()){
                temp.set(cycle);
                line.EnQueue(temp);
                customers++;
                idle = 0;
            }
            else{
                turnaways++;
            }
        }
        // servicing
        if(wait_time<=0 && !line.IsEmpty()){
            line.DeQueue(temp);
            while((cycle-temp.when()) > temp.mtime()){
                leaves++;
                if(!line.DeQueue(temp)){
                    idle = 1;
                    break;
                }
            }
            if(!idle){
                wait_time = temp.ptime();
                line_wait += cycle-temp.when();
                served++;
            }
        }
        // waiting
        if(wait_time>0) wait_time--;
        sum_line+=line.QueueCount();
    }

    // result
    if(customers > 0){
        cout << "customers accepted: " << customers << endl;
        cout << "  customers served: " << served << endl;
        cout << "         turnaways: " << turnaways << endl;
        cout << "            leaves: " << leaves << endl;
        cout << "average queue size: ";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double) sum_line/cyclelimit << endl;
        cout << "average wait time: ";
        cout << (double) line_wait/served << " cycles\n";
    }
    else{cout << "no customers\n";}

    return 0;
}

