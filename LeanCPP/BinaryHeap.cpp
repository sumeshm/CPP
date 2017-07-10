#include "BinaryHeap.h"

BinaryHeap::BinaryHeap()
{
    m_heapType = MAX_HEAP;
}

BinaryHeap::~BinaryHeap()
{
    clean();
}

void BinaryHeap::clean()
{
    for (vector<TreeNode*>::iterator itr = m_heap.begin(); itr != m_heap.end(); itr++)
    {
        TreeNode* p_node = *itr;
        delete p_node;
    }

    m_heap.clear();
}

bool BinaryHeap::addNewNode(int p_data)
{
    cout << "Adding node: " << p_data << endl;
    bool l_retVal = false;

    TreeNode* p_newNode = new TreeNode(p_data);
    m_heap.push_back(p_newNode);

    heapifyUp();

    return l_retVal;
}

int BinaryHeap::getRoot()
{
    int p_retVal = -1;
    if (m_heap.size() > 1)
    {
        TreeNode* p_node = m_heap.front();
        p_retVal = p_node->getData();

        TreeNode* p_lastNode = m_heap.back();
        m_heap.pop_back();
        p_node->setData(p_lastNode->getData());
        delete p_lastNode;

        heapifyDown();

        printTree();
    }
    else if (m_heap.size() == 1)
    {
        TreeNode* p_node = m_heap.front();
        p_retVal = p_node->getData();
        m_heap.pop_back();
        delete p_node;
    }

    return p_retVal;
}

void BinaryHeap::heapifyUp()
{
    int l_currIndex = m_heap.size() - 1;

    while (l_currIndex > 0)
    {
        int l_parentIndex =  (l_currIndex - 1) / 2;
        TreeNode* l_currNode = m_heap[l_currIndex];
        TreeNode* l_parentNode = m_heap[l_parentIndex];

        if (l_parentNode->getData() < l_currNode->getData())
        {
            int l_temp = l_parentNode->getData();
            l_parentNode->setData(l_currNode->getData());
            l_currNode->setData(l_temp);
            l_currIndex = l_parentIndex;
        }
        else
        {
            break;
        }
    }
}

// swap if A < B
bool BinaryHeap::swapNodeData(TreeNode* p_nodeA, TreeNode* p_nodeB)
{
    cout << "Swap:" << p_nodeA->getData() << " & " << p_nodeB->getData();
    bool l_retVal = false;
    if (p_nodeA && p_nodeB && p_nodeA->getData() < p_nodeB->getData())
    {
        int l_temp = p_nodeA->getData();
        p_nodeA->setData(p_nodeB->getData());
        p_nodeB->setData(l_temp);
        l_retVal = true;
    }

    cout << (l_retVal ? " =PASS" : " =FAIL") << endl;

    return l_retVal;
}

void BinaryHeap::heapifyDown()
{
    int l_currIndex = 0;
    int l_leftIndex =  0;
    int l_rightIndex =  0;
    int l_max = m_heap.size();
    bool l_nodeSwapped = false;
    TreeNode* l_leftNode = NULL;
    TreeNode* l_currNode = NULL;
    TreeNode* l_rightNode = NULL;

    while (l_currIndex < l_max)
    {
        l_nodeSwapped = false;
        l_currNode = m_heap[l_currIndex];
        l_leftNode = l_rightNode = NULL;
        l_leftIndex = (l_currIndex * 2) + 1;
        l_rightIndex = (l_currIndex * 2) + 2;

        if (l_leftIndex < l_max) { l_leftNode = m_heap[l_leftIndex]; }
        if (l_rightIndex < l_max) { l_rightNode = m_heap[l_rightIndex]; }

        if (l_leftNode && l_rightNode && l_leftNode->getData() > l_rightNode->getData())
        {
            l_nodeSwapped = swapNodeData(l_currNode, l_leftNode);
            if (l_nodeSwapped) { l_currIndex = l_leftIndex; }
        }
        else if (l_leftNode && l_rightNode && l_leftNode->getData() < l_rightNode->getData())
        {
            l_nodeSwapped = swapNodeData(l_currNode, l_rightNode);
            if (l_nodeSwapped) { l_currIndex = l_rightIndex; }
        }
        else if (l_leftNode)
        {
            l_nodeSwapped = swapNodeData(l_currNode, l_leftNode);
            if (l_nodeSwapped) { l_currIndex = l_leftIndex; }
        }
        else if (l_rightNode)
        {
            l_nodeSwapped = swapNodeData(l_currNode, l_rightNode);
            if (l_nodeSwapped) { l_currIndex = l_rightIndex; }
        }

        if (!l_nodeSwapped)
        {
            break;
        }
    }
}

void BinaryHeap::printHeap()
{
    cout << "HEAP:";
    for (vector<TreeNode*>::iterator itr = m_heap.begin(); itr != m_heap.end(); itr++)
    {
        TreeNode* p_node = *itr;
        cout << " --> " << p_node->getData();
    }
    cout << endl;
}

void BinaryHeap::printTree(unsigned int p_index)
{
    if (p_index < m_heap.size())
    {
        TreeNode* l_node = m_heap[p_index];
        if (l_node)
        {
            cout << "Node: " << l_node->getData() << endl;
            unsigned int l_leftIndex = (2 * p_index) + 1;
            if (l_leftIndex < m_heap.size() && m_heap[l_leftIndex])
            {
                TreeNode* l_leftNode = m_heap[l_leftIndex];
                cout << "....Left: " << l_leftNode->getData() << endl;
            }

            unsigned int l_rightIndex = (2 * p_index) + 2;
            if (l_rightIndex < m_heap.size() && m_heap[l_rightIndex])
            {
                TreeNode* l_rightNode = m_heap[l_rightIndex];
                cout << "....Right: " << l_rightNode->getData() << endl;
            }

            printTree(l_leftIndex);
            printTree(l_rightIndex);
        }
    }
}

void BinaryHeap::addNodeUtil(string p_msg)
{
    string l_dataArray = "";
    int l_nodeValue;

    getline(cin, l_dataArray);
    cout << p_msg << endl;
    getline(cin, l_dataArray);

    istringstream l_stream(l_dataArray);
    while (l_stream >> l_nodeValue)
    {
        addNewNode(l_nodeValue);
    }

    printTree();
}

int BinaryHeap::printOptions(string p_msg)
{
    int l_feedBack = 1;
    int l_retVal = 1;
    while (l_retVal)
    {
        cout << "Welcome to binary heap!" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Build Min-Heap tree" << endl;
        cout << "2. Build Max-Heap tree" << endl;
        cout << "3. Get-Root" << endl;
        cout << "4. Add Node" << endl;
        cout << "5. Remove Node" << endl;
        cout << endl << "b. Back" << endl;
        cout << "q. Exit" << endl;
        cout << "---------------------------------" << endl << endl;

        char l_data[20] = "";
        cin >> l_data;
        switch (l_data[0])
        {
        case '1':
            m_heapType = MIN_HEAP;
            clean();
            addNodeUtil("Enter the elements of MIN-HEAP separated by space:");
            break;
        case '2':
            m_heapType = MAX_HEAP;
            clean();
            addNodeUtil("Enter the elements of MAX-HEAP separated by space:");
            break;
        case '3':
            cout << "ROOT=" << getRoot() << endl;
            break;
        case '4':
            addNodeUtil("Enter the new elements, separated by space:");
            break;
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

