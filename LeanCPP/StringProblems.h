#ifndef STRINGPROBLEMS_H
#define STRINGPROBLEMS_H

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <set>
#include <queue>

using namespace std;

class StringProblems
{
    public:
        StringProblems();
        virtual ~StringProblems();

        virtual int printOptions(string p_msg = " <> ");

    protected:
        virtual int myAtoI();
        virtual void charCombinations(char* p_data, int p_curIdx, int p_length);
        virtual string palindromicSubsequence(string s);
        virtual string palindromicSubstring(string s);
        virtual string commonSubsequence(string s1, string s2);
        virtual bool isStringPalindrome(string s);


    private:
        void swapChar(char* p_left, char* p_right)
        {
            char temp;
            temp = *p_left;
            *p_left = *p_right;
            *p_right = temp;
        }

        int findMin(int* p_arr, int p_first, int p_last);
};

#endif // STRINGPROBLEMS_H
