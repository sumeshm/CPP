#include "BTree.h"

bool BTree::insertNode(TreeNode* p_currentNode, int p_data)
{
    bool l_retVal = false;

    if (p_currentNode)
    {
        if (p_data < p_currentNode->getData())
        {
            if (p_currentNode->getLeftNode())
            {
                l_retVal = insertNode(p_currentNode->getLeftNode(), p_data);
            }
            else
            {
                p_currentNode->addLeftNode(p_data);
                l_retVal = true;
                updateBalance(p_currentNode);
            }
        }
        else if (p_data > p_currentNode->getData())
        {
            if (p_currentNode->getRightNode())
            {
                l_retVal = insertNode(p_currentNode->getRightNode(), p_data);
            }
            else
            {
                p_currentNode->addRightNode(p_data);
                l_retVal = true;
                updateBalance(p_currentNode);
            }
        }
    }

    return l_retVal;
}

bool BTree::addNewNode(int p_data)
{
    cout << "Adding node: " << p_data << endl;
    bool l_retVal = false;
    if (!m_rootNode)
    {
        m_rootNode = new TreeNode(p_data);
        l_retVal = true;
    }
    else
    {
        l_retVal = insertNode(m_rootNode, p_data);
    }

    return l_retVal;
}

TreeNode* BTree::deleteNode(TreeNode* p_currNode, int p_data)
{
    TreeNode* l_retVal = NULL;

    if (p_currNode)
    {
        if (p_data < p_currNode->getData())
        {
            l_retVal = deleteNode(p_currNode->getLeftNode(), p_data);
            p_currNode->addLeftNode(l_retVal);
            l_retVal = p_currNode;
        }
        else if (p_data > p_currNode->getData())
        {
            l_retVal = deleteNode(p_currNode->getRightNode(), p_data);
            p_currNode->addRightNode(l_retVal);
            l_retVal = p_currNode;
        }
        else
        {
            // found the node in the tree
            if (p_currNode->isLeafNode())               // no child
            {
                cout << "found (leaf): [" << p_currNode->getData() << "] .. deleting it" << endl;
                updateBalance(p_currNode->getParentNode());
                l_retVal = nullptr;
                delete p_currNode;
            }
            else if (p_currNode->isBalancedNode())      // both children
            {
                TreeNode* p_minRight = getMinRight(p_currNode->getRightNode());
                p_currNode->setData(p_minRight->getData());
                l_retVal = deleteNode(p_currNode->getRightNode(), p_minRight->getData());
                p_currNode->addRightNode(l_retVal);

                l_retVal = p_currNode;
            }
            else if (p_currNode->getLeftNode())         // only left
            {
                cout << "found (lsh): [" << p_currNode->getData() << "] .. deleting it" << endl;
                l_retVal = p_currNode->getLeftNode();
                delete p_currNode;
            }
            else if (p_currNode->getRightNode())        // only right
            {
                cout << "found (rhs): [" << p_currNode->getData() << "] .. deleting it" << endl;
                l_retVal = p_currNode->getRightNode();
                delete p_currNode;
            }
        }
    }

    return l_retVal;
}

void BTree::balanceTree()
{

}

void BTree::printTree(TreeNode* p_node)
{
    if (p_node)
    {
        cout << "Node: " << p_node->getData() << " .... h=" << p_node->getHeight() << endl;
        if (p_node->getLeftNode())
        {
            cout << "....Left: " << p_node->getLeftNode()->getData() << endl;
            //cout << "....Left: " << p_node->getLeftNode()->toString() << endl;
        }
        if (p_node->getRightNode())
        {
            cout << "....Right: " << p_node->getRightNode()->getData() << endl;
            //cout << "....Right: " << p_node->getRightNode()->toString() << endl;
        }

        printTree(p_node->getLeftNode());
        printTree(p_node->getRightNode());
    }
}

void BTree::printPreOrder(TreeNode* p_node)
{
    if (p_node)
    {
        cout << " --> " << p_node->getData();
        if (p_node->getLeftNode())
        {
            printPreOrder(p_node->getLeftNode());
        }
        if (p_node->getRightNode())
        {
            printPreOrder(p_node->getRightNode());
        }
    }
}

void BTree::printInOrder(TreeNode* p_node)
{
    if (p_node)
    {
        if (p_node->getLeftNode())
        {
            printInOrder(p_node->getLeftNode());
        }

        cout << " --> " << p_node->getData();

        if (p_node->getRightNode())
        {
            printInOrder(p_node->getRightNode());
        }
    }
}

void BTree::printPostOrder(TreeNode* p_node)
{
    if (p_node)
    {
        if (p_node->getLeftNode())
        {
            printPostOrder(p_node->getLeftNode());
        }
        if (p_node->getRightNode())
        {
            printPostOrder(p_node->getRightNode());
        }

        cout << " --> " << p_node->getData();
    }
}

void BTree::printLevelOrder(vector<TreeNode*> l_nodes, unsigned p_index)
{
    TreeNode* l_node = NULL;
    if (p_index == 0)
    {
        l_node = m_rootNode;
        l_nodes.push_back(l_node);
        cout << " --> " << l_node->getData() << endl;
    }
    else if (p_index < l_nodes.size())
    {
        l_node = l_nodes[p_index];
    }

    if (l_node)
    {
        if (p_index == 1 || p_index == 3 || p_index == 7 || p_index == 15 || p_index == 31)
        {
            cout << endl;           // move down one level and print
        }
        if (l_node->getLeftNode())
        {
            l_nodes.push_back(l_node->getLeftNode());
            cout << " --> " << l_node->getLeftNode()->getData();
        }
        if (l_node->getRightNode())
        {
            l_nodes.push_back(l_node->getRightNode());
            cout << " --> " << l_node->getRightNode()->getData();
        }

        printLevelOrder(l_nodes, p_index + 1);
    }
}

void BTree::mirrorTree(TreeNode* p_node)
{
    if (p_node)
    {
        TreeNode* l_leftNode = p_node->getLeftNode();
        TreeNode* l_rightNode = p_node->getRightNode();

        p_node->addLeftNode(l_rightNode);
        p_node->addRightNode(l_leftNode);

        mirrorTree(l_leftNode);
        mirrorTree(l_rightNode);
    }
}

void BTree::printLeftView(TreeNode* p_node, int* p_treeLevel, int p_nodeLevel)
{
    if (p_node != NULL)
    {
        if (*p_treeLevel < p_nodeLevel)
        {
            cout << " - " << p_node->getData();
            *p_treeLevel = p_nodeLevel;
        }

        printLeftView(p_node->getLeftNode(), p_treeLevel, p_nodeLevel + 1);
        printLeftView(p_node->getRightNode(), p_treeLevel, p_nodeLevel + 1);
    }
}

TreeNode* BTree::getMinRight(TreeNode* p_currNode)
{
    if (p_currNode->getLeftNode())
    {
        return getMinRight(p_currNode->getLeftNode());
    }

    cout << "getMinRight=" << p_currNode->getData() << endl;
    return p_currNode;
}

void BTree::updateBalance(TreeNode* p_currNode)
{
    cout << "Updating tree balance:" << endl;

    if (p_currNode != NULL)
    {
        switch (p_currNode->getBalance())
        {
            case TreeNode::LEFT_UNBALANCED:
            {
                cout << "Node is LEFT_UNBALANCED" << endl;
                break;
            }
            case TreeNode::RIGHT_UNBALANCED:
            {
                cout << "Node is RIGHT_UNBALANCED" << endl;
                break;
            }
        }
    }
}

void BTree::addNodeUtil(string p_msg)
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

    //printTree(m_rootNode);
    printLevelOrder();
}

int BTree::printOptions(string p_msg)
{
    int l_feedBack = 1;
    int l_retVal = 1;
    while (l_retVal)
    {
        char l_data[20] = "";
        string l_dataArray = "";
        int l_nodeValue;

        cout << "Welcome to binary tree!" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Build tree" << endl;
        cout << "2. Delete node" << endl;
        cout << "3. Pre-Order traversal" << endl;
        cout << "4. In-Order traversal" << endl;
        cout << "5. Post-Order traversal" << endl;
        cout << "6. Level-Order traversal" << endl;
        cout << "7. Balance the tree" << endl;
        cout << "8. Mirror the tree" << endl;
        cout << "9. Left-View of the tree" << endl;
        cout << endl << "b. Back" << endl;
        cout << "q. Exit" << endl;
        cout << "---------------------------------" << endl << endl;

        cin >> l_data;
        switch (l_data[0])
        {
        case '1':
            addNodeUtil("Enter the elements separated by space:");
            break;
        case '2':
            cout << "Enter the value of the node to remove" << endl;
            cin >> l_nodeValue;

            deleteNode(l_nodeValue);
            printTree(m_rootNode);
            break;
        case '3':
            cout << "PRE ORDER:";
            printPreOrder();
            break;
        case '4':
            cout << "IN ORDER:";
            printInOrder();
            break;
        case '5':
            cout << "POST ORDER:";
            printPostOrder();
            break;
        case '6':
            cout << "LEVEL ORDER:";
            printLevelOrder();
            break;
        case '7':
            cout << "TREE BALANCED:";
            balanceTree();
            break;
        case '8':
            {
                cout << "TREE:" << endl;
                printLevelOrder();

                cout << "\nMIRROR of the TREE:" << endl;
                mirrorTree();
                printLevelOrder();
                break;
            }
        case '9':
            {
                cout << "TREE:" << endl;
                printLevelOrder();

                cout << "\nLEFT VIEW:" << endl;
                printLeftView();
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

        cout << "\n" << endl;
    }

    return l_feedBack;
}

