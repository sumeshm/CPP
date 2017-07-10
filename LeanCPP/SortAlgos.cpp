#include "SortAlgos.h"
#include "BinaryHeap.h"

SortAlgos::SortAlgos()
{

}

SortAlgos::~SortAlgos()
{
}

void SortAlgos::resetList()
{
    // hard reset of data to {5, 7, 0, 3, 5, 2, 6, 4}
    m_data[0] = 5;
    m_data[1] = 7;
    m_data[2] = 0;
    m_data[3] = 3;
    m_data[4] = 5;
    m_data[5] = 2;
    m_data[6] = 6;
    m_data[7] = 4;
}

void SortAlgos::printList(string p_msg)
{
    cout << p_msg << endl;
    for(const int& l_item : m_data)
    {
        cout << " . " << l_item;
    }
    //cout << "\n" << endl;
}


void SortAlgos::selectionSort()
{
    for (auto l_itr = m_data.begin(); l_itr != m_data.end(); l_itr++)
    {
        m_list.addNewNode(*l_itr);
    }


    m_list.printList("Data to sort in List:");

    //printList("\n\nSelection Sort Done:");
}

void SortAlgos::insertionSort()
{
    int l_currentIndex = 0;
    for (auto l_currentItr = m_data.begin(); l_currentItr != m_data.end(); l_currentItr++, l_currentIndex++)
    {
        vector<int>::iterator l_itr;
        for (l_itr = m_data.begin(); l_itr != l_currentItr; l_itr++)
        {
            if (*l_currentItr <= *l_itr)
            {
                m_data.insert(l_itr, *l_currentItr);
                l_currentItr = m_data.begin() + l_currentIndex + 1;
                m_data.erase(l_currentItr);
                l_currentItr = m_data.begin() + l_currentIndex;
                printList();
                break;
            }
        }
    }

    printList("\nInsertion sort result:");
}

void SortAlgos::swapItems(unsigned int p_left, unsigned int p_right)
{
    int l_temp = m_data.at(p_left);
    m_data.at(p_left) = m_data.at(p_right);
    m_data.at(p_right) = l_temp;
}

void SortAlgos::quickSort(unsigned int p_startIdx, unsigned int p_endIdx)
{
    int l_pivotIndex = p_endIdx;
    int l_leftIdx = p_startIdx - 1;
    int l_rightIdx  = p_endIdx;
    int l_pivotValue = m_data.at(l_pivotIndex);

    do
    {
        do { l_leftIdx++;  } while (l_leftIdx < l_rightIdx && m_data.at(l_leftIdx) < l_pivotValue) ;
        do { l_rightIdx--; } while (l_rightIdx > l_leftIdx && m_data.at(l_rightIdx) > l_pivotValue);

        if (l_leftIdx < l_rightIdx) { swapItems(l_leftIdx, l_rightIdx); }

    } while (l_leftIdx < l_rightIdx);

    swapItems(l_leftIdx, l_pivotIndex);

    if ((p_startIdx - l_leftIdx) > 0)
    {
        quickSort(p_startIdx, l_leftIdx - 1);
    }
    if ((p_endIdx - l_leftIdx) > 0)
    {
        quickSort(l_leftIdx + 1, p_endIdx);
    }
}

int SortAlgos::printOptions(string p_msg)
{
    int l_feedBack = 1;
    int l_retVal = 1;
    while (l_retVal)
    {
        char l_data[20] = "";

        cout << "\nWelcome to Sorting!" << endl;
        cout << "---------------------------------" << endl;
        resetList();
        printList("Data to sort:");
        cout << endl;
        cout << "1. Selection Sort" << endl;
        cout << "2. Insertion Sort" << endl;
        cout << "3. Quick Sort" << endl;
        cout << "4. Merge Sort" << endl;
        cout << "5. Binary Heap Sort" << endl;
        cout << endl << "b. Back" << endl;
        cout << "q. Exit" << endl;
        cout << "---------------------------------" << endl << endl;

        cin >> l_data;
        switch (l_data[0])
        {
        case '1':
            {
                selectionSort();
                break;
            }
        case '2':
            {
                insertionSort();
                break;
            }
        case '3':
            {
                quickSort(0, m_data.size() - 1);
                printList("\n\nQuick Sort Done:");
                break;
            }
        case '4':
            {
                //printList("\n\nMerge Sort Done:");
                break;
            }
        case '5':
            {
                BinaryHeap l_heap;
                l_heap.printOptions();
                break;
            }
        case '6':
            {
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

        cout << endl;
    }

    return l_feedBack;
}
