#ifndef LEARNCPP_H
#define LEARNCPP_H

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <queue>

using namespace std;

class LearnCpp
{
    public:
        LearnCpp(const char* p_name);
        virtual ~LearnCpp();

        // constructor and operator overloads
        LearnCpp() {}
        LearnCpp(const LearnCpp& other);
        LearnCpp& operator=(const LearnCpp& p_other);
        void* operator new(size_t p_size);
        void operator delete(void* p_obj);

        char* getName() {   return m_name;              }
        void toStrng()  {   cout << "name=" << m_name << endl;  }

        void testPriorityQueueForObjects();

        virtual int printOptions(string p_msg = " <> ");
    protected:
    private:
        char* m_name = NULL;
        void deepCopy(const char* p_name);
};


class Toast
{
public:
	int bread;
	int butter;

	Toast(int bread, int butter) :
	    bread(bread),
	    butter(butter)
	{
	    cout << "\tToast created: bread=" << bread << ", butter=" << butter << endl;
	}

    bool operator()(const Toast &t1, const Toast &t2) const
	{
		int t1value = t1.bread * 1000 + t1.butter;
		int t2value = t2.bread * 1000 + t2.butter;
		return t1value < t2value;
	}

    bool operator < (const Toast& t) const
    {
        int t1value = bread * 1000 + butter;
        int t2value = t.bread * 1000 + t.butter;
        return t1value < t2value;
    }

    class ToastCompare
    {
        public:
        bool operator()(const Toast &t1, const Toast &t2) const
        {
            int t1value = t1.bread * 1000 + t1.butter;
            int t2value = t2.bread * 1000 + t2.butter;
            return t1value < t2value;
        }
    };
};


#endif // LEARNCPP_H
