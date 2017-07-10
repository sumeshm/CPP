#ifndef PROBLEMSOLVING_H
#define PROBLEMSOLVING_H

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <set>
#include <queue>

using namespace std;

enum {FIB_MEMOISE, FIB_RECURSE};

class Tower;
class CompareTower;

class ProblemSolving
{
    public:
        ProblemSolving();
        virtual ~ProblemSolving();

        virtual int printOptions(string p_msg = " <> ");
    protected:
        virtual int printFibonacchiRecurse(int p_max, int p_current);
        virtual void printFibonacchi(int p_approach);
        virtual void towerOfHanoi(int p_count, Tower& p_towerA, Tower& p_towerB, Tower& p_towerC);
        virtual void printTowers(Tower& p_towerA, Tower& p_towerB, Tower& p_towerC);
        virtual void learnArrays();
        virtual void funWithBits();
        virtual void reverseNumber();
        virtual void minOfRotatedArray();

    private:
        int findMin(int* p_arr, int p_first, int p_last);
};

class Tower
{
private:
    set<int>    m_discs;
    int         m_number;

    public:
        Tower() {}
        Tower(int p_number, int p_total = 0) : m_number(p_number)
        {
            int i = 1;
            while (i <= p_total)
            {
                addDisc(i++);
            }
        }

        void addDisc(int p_count)               {   m_discs.insert(p_count);    }
        void removeDisc(int p_count)            {   m_discs.erase(p_count);     }
        int getNumber()                         {   return m_number;            }

        string toString()
        {
            string l_retVal;
            l_retVal.append("<");
            for (set<int>::iterator itr = m_discs.begin(); itr != m_discs.end(); itr++)
            {
                l_retVal += '0' + *itr;
                l_retVal.append(", ");
            }
            l_retVal.append(">");

            return l_retVal;
        }

        bool operator() (Tower& p_tower1, Tower& p_tower2)
        {
            return (p_tower1.getNumber() > p_tower2.getNumber());
        }
};


#endif // PROBLEMSOLVING_H
