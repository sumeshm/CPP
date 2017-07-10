#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
#include <sstream>


using namespace std;

typedef struct LLNode
{
    int m_data;
    struct LLNode* m_next;
} LLNode;

class LinkedList
{
    public:
        LinkedList();
        virtual ~LinkedList();

        int printOptions(string p_msg = " <> ");
        void addNewNode(int p_data);
        bool removeNode(int p_data);
        bool insertNode(int p_newData, int p_insertNodeData);
        void reverseList();
        void printList(string p_msg = "");

        LLNode* getHeadNode() { return m_headNode; }

    protected:
    private:
        LLNode* m_headNode;
};

#endif // LINKEDLIST_H
