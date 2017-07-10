#ifndef SORTALGOS_H
#define SORTALGOS_H

#include <iostream>
#include <string>
#include <vector>
#include <array>

#include "LinkedList.h"

using namespace std;

class SortAlgos
{
    public:
        SortAlgos();
        virtual ~SortAlgos();

        virtual int printOptions(string p_msg = " <> ");

    protected:
        vector<int> m_data = {5, 7, 0, 3, 5, 2, 6, 4};
        LinkedList m_list;

        void resetList();
        void printList(string p_msg = "");
        void swapItems(unsigned int p_left, unsigned int p_right);
        void selectionSort();
        void insertionSort();
        void quickSort(unsigned int p_startIdx, unsigned int p_endIdx);

    private:
};

#endif // SORTALGOS_H
