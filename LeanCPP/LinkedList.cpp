#include "LinkedList.h"

LinkedList::LinkedList()
{
    m_headNode = NULL;
}

LinkedList::~LinkedList()
{
    if (m_headNode)
    {
        delete m_headNode;
    }
}

void LinkedList::addNewNode(int p_data)
{
    cout << "adding...[" << p_data << "], to the list" << endl;

    if (!m_headNode)
    {
        m_headNode = new LLNode();
        m_headNode->m_data = p_data;
        m_headNode->m_next = NULL;
    }
    else
    {
        LLNode* p_currNode = m_headNode;
        while (p_currNode->m_next)
        {
            p_currNode = p_currNode->m_next;
        }

        p_currNode->m_next = new LLNode();
        p_currNode->m_next->m_data = p_data;
        p_currNode->m_next->m_next = NULL;
    }
}

bool LinkedList::removeNode(int p_data)
{
    bool l_retVal = false;
    string l_msg = "Pre removal of ";
    l_msg += p_data + " from the list";
    printList(l_msg);

    if (m_headNode)
    {
        LLNode* l_deleteNode = NULL;
        if (m_headNode->m_data == p_data)
        {
            l_deleteNode = m_headNode;
            m_headNode = m_headNode->m_next;
        }
        else
        {
            LLNode* p_currNode = m_headNode;
            LLNode* p_nextNode = p_currNode->m_next;
            while (p_nextNode)
            {
                if (p_data == p_nextNode->m_data)
                {
                    l_deleteNode = p_nextNode;
                    p_currNode->m_next = p_nextNode->m_next;
                    break;
                }
                p_currNode = p_nextNode;
                p_nextNode = p_nextNode->m_next;
            }
        }

        if (l_deleteNode)
        {
            l_retVal = true;
            delete l_deleteNode;

            printList("Post Removal");
        }
    }

    return l_retVal;
}

bool LinkedList::insertNode(int p_newData, int p_insertNodeData)
{
    bool l_retVal = false;
    LLNode* l_insertNode = NULL;
    string l_msg = "Pre inserting";
    l_msg += p_newData + " @ " + p_insertNodeData;
    printList(l_msg);

    if (m_headNode)
    {
        if (m_headNode->m_data == p_insertNodeData)
        {
            l_insertNode = new LLNode();
            l_insertNode->m_data = p_newData;
            l_insertNode->m_next = m_headNode;

            m_headNode = l_insertNode;
        }
        else
        {
            LLNode* p_currNode = m_headNode;
            LLNode* p_nextNode = p_currNode->m_next;
            while (p_nextNode)
            {
                if (p_insertNodeData == p_nextNode->m_data)
                {
                    l_insertNode = new LLNode();
                    l_insertNode->m_data = p_newData;
                    l_insertNode->m_next = p_nextNode;

                    p_currNode->m_next = l_insertNode;
                    break;
                }
                p_currNode = p_nextNode;
                p_nextNode = p_nextNode->m_next;
            }
        }
    }

    if (l_insertNode)
    {
        l_retVal = true;
        printList("Post inserting");
    }

    return l_retVal;
}

void LinkedList::reverseList()
{
    cout << "Reversing list.." << endl;
    LLNode* p_prevNode = NULL;
    LLNode* p_currNode = m_headNode;
    LLNode* p_nextNode = NULL;

    while (p_currNode)
    {
        p_nextNode = p_currNode->m_next;
        p_currNode->m_next = p_prevNode;

        if (p_nextNode)
        {
            p_prevNode = p_currNode;
            p_currNode = p_nextNode;
        }
        else
        {
            break;
        }

    }

    m_headNode = p_currNode;
    printList("Post reversing");
}

void LinkedList::printList(string p_msg)
{
    LLNode* p_currNode = m_headNode;
    cout << (p_msg.empty() ? "Printing list.." : p_msg) << endl;
    while (p_currNode)
    {
        cout << " . " << p_currNode->m_data;
        p_currNode = p_currNode->m_next;
    }
    cout << "\n" << endl;
}

int LinkedList::printOptions(string p_msg)
{
    int l_feedBack = 1;
    int l_retVal = 1;

    while (l_retVal)
    {
        char l_data[20] = "";
        string l_dataArray;
        int l_nodeValue;
        int l_nodeValue2;

        cout << "Welcome to linked list!" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Add element" << endl;
        cout << "2. Delete element" << endl;
        cout << "3. Insert element" << endl;
        cout << "4. Reverse list" << endl;
        cout << "9. Print List" << endl;
        cout << endl << "b. Back" << endl;
        cout << "q. Exit" << endl;
        cout << "---------------------------------" << endl << endl;

        cin >> l_data;
        switch (l_data[0])
        {
        case '1':
            {
                getline(cin, l_dataArray);
                cout << "Enter the elements separated by space:" << endl;
                std::getline(cin, l_dataArray);

                istringstream l_stream(l_dataArray);
                while (l_stream >> l_nodeValue)
                {
                    addNewNode(l_nodeValue);
                }

                printList("Created a linked list...");
            }
            break;
        case '2':
            cout << "Enter an int value for the node" << endl;
            cin >> l_nodeValue;
            cout << "Remove " << (removeNode(l_nodeValue) ? "PASS" : "FAIL") << endl;
            break;
        case '3':
            cout << "Enter an int value for the new node" << endl;
            cin >> l_nodeValue;

            cout << "...now enter the node where insertion is needed" << endl;
            cin >> l_nodeValue2;

            cout << "Insert " << (insertNode(l_nodeValue, l_nodeValue2) ? "PASS" : "FAIL") << endl;
            break;
        case '4':
            reverseList();
            break;
        case '9':
            printList();
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
