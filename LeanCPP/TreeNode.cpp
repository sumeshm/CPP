#include "TreeNode.h"

TreeNode::TreeNode(int p_data)
{
    m_data = p_data;
    m_height = 1;
    m_parentNode = NULL;
    m_leftNode = NULL;
    m_rightNode = NULL;
}

TreeNode::~TreeNode()
{
    clean();
}

void TreeNode::addLeftNode(int p_data)
{
    m_leftNode = new TreeNode(p_data);
    m_leftNode->addParentNode(this);
    updateHeight();
}

void TreeNode::removeLeftNode()
{
    if (m_leftNode)
    {
        delete m_leftNode;
        m_leftNode = NULL;

        updateHeight();
    }
}

void TreeNode::addRightNode(int p_data)
{
    m_rightNode = new TreeNode(p_data);
    m_rightNode->addParentNode(this);
    updateHeight();
}

void TreeNode::removeRightNode()
{
    if (m_rightNode)
    {
        delete m_rightNode;
        m_rightNode = NULL;

        updateHeight();
    }
}

void TreeNode::clean()
{
    if (m_leftNode)
    {
        //delete m_leftNode;
        m_leftNode = NULL;
    }
    if (m_rightNode)
    {
        //delete m_rightNode;
        m_rightNode = NULL;
    }

    m_height = 0;
    removeParentNode();
}

void TreeNode::updateHeight()
{
    int l_height = 0;
    int l_leftHeight = -1;
    int l_rightHeight = -1;

    if (m_leftNode)
    {
        l_leftHeight = m_leftNode->getHeight();
    }
    else if (m_rightNode)
    {
        l_rightHeight = m_rightNode->getHeight();
    }

    l_height = (l_leftHeight >= l_rightHeight) ? l_leftHeight : l_rightHeight;
    m_height = l_height + 1;

    // update balance
    if (l_leftHeight > l_rightHeight && (l_leftHeight - l_rightHeight) > 1)
    {
        if ((l_leftHeight - l_rightHeight) == 1)
        {
            m_balance = LEFT_HEAVY;
        }
        if ((l_leftHeight - l_rightHeight) > 1)
        {
            m_balance = LEFT_UNBALANCED;
        }
    }
    else if (l_leftHeight < l_rightHeight && (l_rightHeight - l_leftHeight) > 1)
    {
        if ((l_rightHeight - l_leftHeight) == 1)
        {
            m_balance = RIGHT_HEAVY;
        }
        if ((l_rightHeight - l_leftHeight) > 1)
        {
            m_balance = RIGHT_UNBALANCED;
        }
    }

    if (m_parentNode)
    {
        m_parentNode->updateHeight();
    }
}

string TreeNode::toString()
{
    string l_data("");

    l_data += m_data;
    l_data += " .......h=";
    l_data += m_height;

    return l_data;
}
