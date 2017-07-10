#ifndef BTREE_H
#define BTREE_H

#include "TreeNode.h"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class BTree
{
    protected:
        TreeNode* m_rootNode;

        virtual bool insertNode(TreeNode* p_currentNode, int p_data);
        virtual void addNodeUtil(string p_msg);
        virtual TreeNode* getMinRight(TreeNode* p_currNode);
        virtual TreeNode* getMaxLeft(TreeNode* p_currNode) { return NULL; }

        virtual TreeNode* deleteNode(TreeNode* p_currNode, int p_data);

        virtual void printTree(TreeNode* p_node);
        virtual void printPreOrder(TreeNode* p_node);
        virtual void printInOrder(TreeNode* p_node);
        virtual void printPostOrder(TreeNode* p_node);
        virtual void printLevelOrder(vector<TreeNode*> l_nodes, unsigned p_index = 0);

        virtual void mirrorTree(TreeNode* p_node);
        virtual void printLeftView(TreeNode* p_node, int* p_treeLevel, int l_nodeLevel);

    public:
        BTree() { m_rootNode = NULL; }
        virtual ~BTree() { if (m_rootNode) { delete m_rootNode; } }

        virtual int printOptions(string p_msg = " <> ");

        virtual bool addNewNode(int p_data);
        virtual TreeNode* deleteNode(int p_data)
        {
            m_rootNode = deleteNode(m_rootNode, p_data);
            return m_rootNode;
        }
        virtual void balanceTree();

        virtual void printTree()        { printTree(m_rootNode); }
        virtual void printPreOrder()    { printPreOrder(m_rootNode); }
        virtual void printInOrder()     { printInOrder(m_rootNode); }
        virtual void printPostOrder()   { printPostOrder(m_rootNode); }
        virtual void printLevelOrder()
        {
            if (m_rootNode)
            {
                vector<TreeNode*> l_levelOrder;
                printLevelOrder(l_levelOrder);
            }
        }

        virtual void updateBalance(TreeNode* p_currNode);
        virtual void mirrorTree()
        {
            if (m_rootNode)
            {
                mirrorTree(m_rootNode);
            }
        }
        virtual void printLeftView()
        {
            if (m_rootNode)
            {
                int l_level = 0;
                printLeftView(m_rootNode, &l_level, 1);
            }
        }
};

#endif // BTREE_H
