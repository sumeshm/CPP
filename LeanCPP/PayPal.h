#ifndef PAYPAL_H
#define PAYPAL_H

#include <iostream>
#include <string>

using namespace std;

class PayPal
{
    public:
        PayPal();
        virtual ~PayPal();

        void memoryTrcakerDemo();
        void printArr(int arr[], int n, int sum);
        bool isSubsetSum (int arr[], int n, int sum);

        // Returns true if arr[] can be partitioned in two subsets of
        // equal sum, otherwise false
        bool findPartiion (int arr[], int n);
        bool findPartiionDy(int arr[], int n);
        int dictionaryContains(string word);
        bool wordBreak(string str);
        void paypal();

        /*
        void* operator new(size_t s, const char *file, int line)
        {
            void* mem = malloc(s);
            memData.insert(mem);
            cout << "--> mem_new :" << mem << " @ " << file << "::" << line << ": " << s << " bytes" << endl;

            //if (!mem) puts("out");
            return mem;
        }

        void operator delete(void* mem)
        {
            cout << "--> mem_del @ " << mem << " : " << sizeof(mem) << " bytes" << endl;
            memData.erase(mem);
            free(mem);
        }

        #define new new(__FILE__, __LINE__)
        */



    protected:

    private:
};

#endif // PAYPAL_H

