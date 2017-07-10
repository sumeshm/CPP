#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

using namespace std;


class TreeNode
{
    private:

    protected:
        int         m_data;
        int         m_height;
        int         m_balance;
        TreeNode*   m_parentNode;
        TreeNode*   m_leftNode;
        TreeNode*   m_rightNode;

        void clean();
        void updateHeight();

    public:
        TreeNode(int p_data);
        virtual ~TreeNode();

        enum {LEFT_HEAVY, RIGHT_HEAVY, LEFT_UNBALANCED, RIGHT_UNBALANCED};

        int getData()                         { return m_data;            }
        void setData(int p_data)              { m_data = p_data;          }

        int getHeight()                       { return m_height;          }
        int getBalance()                      { return m_balance;         }

        TreeNode* getParentNode()             { return m_parentNode;      }
        void addParentNode(TreeNode* p_node)  { m_parentNode = p_node;    }
        void removeParentNode()               { m_parentNode = NULL;      }

        TreeNode* getLeftNode()               { return m_leftNode;        }
        void addLeftNode(int p_data);
        void addLeftNode(TreeNode* p_node)    { m_leftNode = p_node;      }
        void removeLeftNode();

        TreeNode* getRightNode()              { return m_rightNode;       }
        void addRightNode(int p_data);
        void addRightNode(TreeNode* p_node)   { m_rightNode = p_node;     }
        void removeRightNode();

        bool isBalancedNode()                 { return (m_leftNode && m_rightNode);   }
        bool isLeafNode()                     { return (!m_leftNode && !m_rightNode); }

        string toString();

};

#endif // TREENODE_H
