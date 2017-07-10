#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "TreeNode.h"
#include "IMenu.h"

using namespace std;

class BinaryHeap : public IMenu
{
    public:
        BinaryHeap();
        virtual ~BinaryHeap();

        enum {MIN_HEAP, MAX_HEAP};

        virtual int getRoot();
        virtual int printOptions(string p_msg = " <> ");
        virtual bool addNewNode(int p_data);

    protected:
        int m_heapType;
        vector<TreeNode*> m_heap;

        virtual void clean();
        virtual void addNodeUtil(string p_msg);
        virtual void printHeap();
        virtual void printTree(unsigned int p_index = 0);
        virtual void heapifyUp();
        virtual void heapifyDown();
        virtual bool swapNodeData(TreeNode* p_nodeA, TreeNode* p_nodeB);

    private:
};

#endif // BINARYHEAP_H
