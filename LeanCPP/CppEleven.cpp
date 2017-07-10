#include "CppEleven.h"

CppEleven::CppEleven()
{

    /*
    -> auto
    -> Range-based for loops
    -> nullptr
    -> Override and final
    -> Strongly-typed enums
            enum class Color {RED, GREEN, BLUE};
            enum class Colors : char { RED = 1, GREEN = 2, BLUE = 3 };

    -> static_assert and type traits
    -> non-member begin() and end() for non STL containers
            int arr[] = {1,2,3,4,5};
            for (auto it = begin(arr); it != end(arr); ++it) { cout << *it << endl; }

    -> Smart pointers
    -> Lambdas
    -> Move semantics, Move constructor and Move  assignment operator for handling rvalue ref
            Dummy (Dummy&& rValRef)
            Dummy& operator= (Dummy&& rValRef)
            std::move(pointer)

    -> Initializer List:
            vector<MyClass*> l_list = {0, 1, 2};
            vector<MyClass*> l_list(0, 1, 2);

    -> Uniform Initialization:
        Aggregate Initialization (existing):
        struct MyStruct
        {
            int a;
            cahar c;
        };

        MyStruct myStruct = {1, 'a'};
        MyStruct myStruct(1, 'a');

        This extended to class is Uniform Initialization:
             - given that the class has a constructor that takes those params
            class MyClass
            {
                MyClass(int a, char c) {...}
            }

            MyStruct myClass = {1, 'a'};
            MyStruct myClass(1, 'a');

        Initialization Priority for compiler:
            Initializer List Constructor > other Constructor matching initializer List > Aggregate Initialization


    -> foreach

    delegating constructor
    constexpr
    New string literals
    Keyword delete  (to delete default functions)
    Keyword default (for default constructor)

    smart pointers:
        unique_ptr:
            should be used when ownership of a memory resource does not have to be shared
            (it doesn't have a copy constructor), but it can be transferred to another unique_ptr
            (move constructor exists).
        shared_ptr:
            should be used when ownership of a memory resource should be shared (hence the name).
        weak_ptr:
            holds a reference to an object managed by a shared_ptr, but does not contribute to
            the reference count; it is used to break dependency cycles (think of a tree where
            the parent holds an owning reference (shared_ptr) to its children, but the children
            also must hold a reference to the parent; if this second reference was also an owning
            one, a cycle would be created and no object would ever be released).

    */

    reBuild();
    cout << "CppEleven created" <<endl;
}

CppEleven::~CppEleven()
{
    cout << "CppEleven deleted" <<endl;
}


void CppEleven::reBuild()
{
    m_dataArray.clear();
    m_dataArray.push_back(0);
    m_dataArray.push_back(1);
    m_dataArray.push_back(2);
    m_dataArray.push_back(3);
    m_dataArray.push_back(4);
}

int CppEleven::printOptions(string p_msg)
{
    int l_feedBack = 1;
    int l_retVal = 1;
    while (l_retVal)
    {
        char l_data[20] = "";
        l_feedBack = 1;

        cout << "Welcome to features of C++ 11.0!" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. 'auto'" << endl;
        cout << "2. range-based for loops" << endl;
        cout << "3. strongly typed Enum" << endl;
        cout << "4. static assert" << endl;
        cout << "5. lambda" << endl;
        cout << "6. smart pointer" << endl;
        cout << "7. non-member begin and end for non STL containers" << endl;
        cout << endl << "b. Back" << endl;
        cout << "q. Exit" << endl;
        cout << "---------------------------------" << endl << endl;

        cin >> l_data;
        switch (l_data[0])
        {
        case '1':
            {
                // auto
                string l_msg = "";
                for (auto itr = m_dataArray.begin(); itr != m_dataArray.end(); itr++)
                {
                    cout << " --> " << *itr << endl;
                }
            }
            break;
        case '2':
            {
                // range-based for loops
                cout << "for (int l_data : m_dataArray) \n{ \n\t cout << l_data; \n}" << endl;
                for (int l_data : m_dataArray)
                {
                    cout << "\t --> " << l_data << endl;
                }
            }
            break;
        case '3':
            {
                // strongly typed Enum
                cout << "Enum for class" << endl;
                cout << "\tenum class Color {RED, GREEN, BLUE};" << endl;
                cout << "\tenum class Colors : char { RED = 1, GREEN = 2, BLUE = 3 };" << endl;
                break;
            }
            break;
        case '4':
            {
                // static assert
                cout << "static_assert(l_data < 10, \"static assert failed\");" << endl;
                break;
            }
        case '5':
            {
                // anonymous function / lambda
                auto func = [] (int a, int b) { return (a+b); };
                cout << "Lambda_addition_function=" << func(2, 3) << endl;

                // custom deleter for shared pointer array
                cout << "\nCreated shared_ptr array(3), with custom labmda deleter:" << endl;
                cout << "\n\tshared_ptr<CppEleven> p_data(new CppEleven[3], [](CppEleven* p){ delete[] p;} );" << endl;
                shared_ptr<CppEleven> p_data(new CppEleven[3], [](CppEleven* p){ delete[] p;} );
                break;
            }
        case '6':
            {
                // smart pointer
                cout << "\nCreated shared_ptr :" << endl;
                cout << "\t shared_ptr<CppEleven> l_sharedPtr1 = make_shared<CppEleven>();" << endl;
                shared_ptr<CppEleven> l_sharedPtr1 = make_shared<CppEleven>();  // faster, exception safe
                cout << "\t shared_ptr<CppEleven> l_sharedPtr1(new CppEleven());" << endl;
                shared_ptr<CppEleven> l_sharedPtr2(new CppEleven());

                cout << "\t unique_ptr<CppEleven> l_uniqePtr1(new CppEleven());" << endl;
                unique_ptr<CppEleven> l_uniqePtr1(new CppEleven());
                cout << "\t unique_ptr<CppEleven> l_uniqePtr2 = move(l_uniqePtr1);" << endl;
                unique_ptr<CppEleven>  l_uniqePtr2 = move(l_uniqePtr1);

                // weak_ptr

                break;
            }
        case '7':
            {
                // non-member begin and end
                cout << "int arr[] = {1,2,3,4,5}; \nfor (auto it = begin(arr); it != end(arr); ++it) \n{ \n\tcout << *it << endl; \n}" << endl;
                int l_array[] = {1,2,3,4,5};
                for (auto l_itr = begin(l_array); l_itr != end(l_array); l_itr++)
                {
                    cout << " --> " << *l_itr << endl;
                }
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

        reBuild();
        cout << endl;
    }

    return l_feedBack;
}

