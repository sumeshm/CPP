#include "LearnThreads.h"
#include "ThreadPool.cpp.h"

LearnThreads::LearnThreads()
{
    //ctor
}

LearnThreads::~LearnThreads()
{
    //dtor
}

int LearnThreads::printOptions(string p_msg)
{
    int l_feedBack = 1;
    int l_retVal = 1;
    while (l_retVal)
    {
        char l_data[20] = "";

        cout << "\nWelcome to Threads!" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Create Threads" << endl;
        cout << "2. Thread Pool" << endl;
        cout << endl << "b. Back" << endl;
        cout << "q. Exit" << endl;
        cout << "---------------------------------" << endl << endl;

        cin >> l_data;
        switch (l_data[0])
        {
        case '1':
            {

                break;
            }
        case '2':
            {
                int iterations = 2;

                // Create the queue and consumer (worker) threads
                wqueue<WorkItem*>  queue;
                ConsumerThread* thread1 = new ConsumerThread(queue);
                ConsumerThread* thread2 = new ConsumerThread(queue);
                thread1->start();
                thread2->start();

                // Add items to the queue
                WorkItem* item;
                for (int i = 0; i < iterations; i++) {
                    item = new WorkItem("abc", 123);
                    queue.add(item);
                    item = new WorkItem("def", 456);
                    queue.add(item);
                    item = new WorkItem("ghi", 789);
                    queue.add(item);
                }

                break;
            }
        case 'b':
            l_retVal = 0;
           break;
        case 'q':
            l_retVal = 0;
            l_feedBack = 0;
            break;
        default:
            cout << "'" << l_data[0] << "' is an invalid choice.....try again" << endl;
            break;
        }

        cout << endl;
    }

    return l_feedBack;
}

