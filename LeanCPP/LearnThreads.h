#ifndef LEARNTHREADS_H
#define LEARNTHREADS_H


#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <pthread.h>
#include <list>
#include <stdio.h>
#include <stdlib.h>


// example:
// https://vichargrave.github.io/articles/2013-01/multithreaded-work-queue-in-cpp


using namespace std;

template <typename T> class wqueue
{
    list<T>   m_queue;
    pthread_mutex_t m_mutex;
    pthread_cond_t  m_condv;

public:
    wqueue() {
        pthread_mutex_init(&m_mutex, NULL);
        pthread_cond_init(&m_condv, NULL);
    }
    ~wqueue() {
        pthread_mutex_destroy(&m_mutex);
        pthread_cond_destroy(&m_condv);
    }
    void add(T item) {
        pthread_mutex_lock(&m_mutex);
        m_queue.push_back(item);
        pthread_cond_signal(&m_condv);
        pthread_mutex_unlock(&m_mutex);
    }
    T remove() {
        pthread_mutex_lock(&m_mutex);
        while (m_queue.size() == 0) {
            pthread_cond_wait(&m_condv, &m_mutex);
        }
        T item = m_queue.front();
        m_queue.pop_front();
        pthread_mutex_unlock(&m_mutex);
        return item;
    }
    int size() {
        pthread_mutex_lock(&m_mutex);
        int size = m_queue.size();
        pthread_mutex_unlock(&m_mutex);
        return size;
    }
};


class WorkItem
{
    string m_message;
    int    m_number;

  public:
    WorkItem(const char* message, int number)
          : m_message(message), m_number(number) {}
    ~WorkItem() {}

    const char* getMessage() { return m_message.c_str(); }
    int getNumber() { return m_number; }
};

class Thread
{
  private:
    ptw32_handle_t  m_tid;
    int             m_running;
    int             m_detached;

  public:
    //void* (*start_routine)(void *);
    virtual void* run(void* p_data) = 0;

    Thread() : m_running(0), m_detached(0)
    {
         m_tid.x = 0;
    }

    virtual ~Thread()
    {
        if (m_running == 1 && m_detached == 0) {
            pthread_detach(m_tid);
        }
        if (m_running == 1) {
            pthread_cancel(m_tid);
        }
    }

    int start()
    {
        void* (*p_run)(void*);
        p_run = run;

        int result = pthread_create(&m_tid, NULL, p_run, NULL);
        if (result == 0) {
            m_running = 1;
        }
        return result;
    }

    int join()
    {
        int result = -1;
        if (m_running == 1) {
            result = pthread_join(m_tid, NULL);
            if (result == 0) {
                m_detached = 1;
            }
        }
        return result;
    }

    int detach()
    {
        int result = -1;
        if (m_running == 1 && m_detached == 0) {
            result = pthread_detach(m_tid);
            if (result == 0) {
                m_detached = 1;
            }
        }
        return result;
    }

    pthread_t self() {
        return m_tid;
    }

};

class ConsumerThread : public Thread
{
    wqueue<WorkItem*>& m_queue;

  public:
    ConsumerThread(wqueue<WorkItem*>& queue) : m_queue(queue) {}

    void* run(void* p_data) {
        // Remove 1 item at a time and process it. Blocks if no items are
        // available to process.
        for (int i = 0;; i++) {
//            cout << "thread " << self() << ", loop " << i << " - waiting for item..." << endl;
            WorkItem* item = (WorkItem*)m_queue.remove();
//            cout << "thread " << self() << ", loop " << i << " - got for item..." << endl;
//            cout << "thread " << self() << ", loop " << i << " - item: message - " << endl;
//            cout << "thread " << self() << ", loop " << i << " - item: message - " << item->getMessage() << ", number - " << item->getNumber() << endl;

            delete item;
        }
        return NULL;
    }
};



class LearnThreads
{
    public:
        LearnThreads();
        virtual ~LearnThreads();

        virtual int printOptions(string p_msg = " <> ");
    protected:
    private:
};


/*
#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

class LearnThreads
{
    public:
        LearnThreads();
        virtual ~LearnThreads();

        virtual int printOptions(string p_msg = " <> ");
    protected:
    private:
};
*/

#endif // LEARNTHREADS_H
