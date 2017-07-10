#include "LearnCpp.h"
#include "LearnException.h"
#include "LearnTemplates.h"
#include "TestInheritance.h"

LearnCpp::LearnCpp(const char* p_name)
{
    cout << "\t LearnCpp(char*): " << p_name << endl;
    deepCopy(p_name);
}

LearnCpp::~LearnCpp()
{
    cout << "\t~LearnCpp(): ";
    if (m_name)
    {
        cout << "m_name=" << m_name;
        delete m_name;
    }

    cout << endl;
}

LearnCpp::LearnCpp(const LearnCpp& p_other)
{
    cout << "\t LearnCpp(const LearnCpp&): name=" << endl;

    deepCopy(p_other.m_name);
}

LearnCpp& LearnCpp::operator=(const LearnCpp& p_rhs)
{
    cout << "\t LearnCpp::operator =: " << endl;

    if (this != &p_rhs)
    {
        deepCopy(p_rhs.m_name);
    }

    return *this;
}

void* LearnCpp::operator new(size_t p_size)
{
    cout << "\t LearnCpp::new(): " << p_size << endl;
    void* l_retVal = malloc(p_size);
    if (!l_retVal)
    {
        bad_alloc l_allocError;
        throw l_allocError;
    }

    return l_retVal;
}

void LearnCpp::operator delete(void* p_obj)
{
    cout << "\t LearnCpp::delete(): " << endl;
    LearnCpp* l_obj = (LearnCpp*) p_obj;
    free(l_obj->getName());
    free(l_obj);
}

void LearnCpp::deepCopy(const char* p_name)
{
    if (p_name && strlen(p_name) > 0)
    {
        if (m_name)
        {
            delete m_name;
        }

        //m_name = (char*) malloc(strlen(p_name) * sizeof(char));
        m_name = new char[strlen(p_name)];
        if (m_name)
        {
            strcpy(m_name, p_name);
        }
    }
}

void LearnCpp::testPriorityQueueForObjects()
{
    Toast toast1(2, 200);
	Toast toast2(1, 30);
	Toast toast3(1, 10);
	Toast toast4(3, 1);

	//priority_queue<Toast, vector<Toast>, Toast::ToastCompare> queue;
    priority_queue<Toast> queue;

	queue.push(toast1);
	queue.push(toast2);
	queue.push(toast3);
	queue.push(toast4);

    cout << "\tPriority Toast:" << endl;
	while (!queue.empty())
	{
		Toast t = queue.top();
		cout << "\tbread " << t.bread << " butter " << t.butter << std::endl;
		queue.pop();
	}

    cout << endl;
}


int LearnCpp::printOptions(string p_msg)
{
    int l_feedBack = 1;
    int l_retVal = 1;
    string l_msg = p_msg + "LEARN_CPP";
    while (l_retVal)
    {
        char l_data[20] = "";

        cout << "\n" << l_msg << endl;
        cout << "Welcome to CPP internals!" << endl;
        cout << "---------------------------------" << endl;
        cout << "1. Object creation with 'new'" << endl;
        cout << "2. Copy and Assignment operator" << endl;
        cout << "3. Priority Queue for Objects" << endl;
        cout << "4. Exception Handling" << endl;
        cout << "5. Templates" << endl;
        cout << "6. Inheritance" << endl;
        cout << endl << "b. Back" << endl;
        cout << "q. Exit" << endl;
        cout << "---------------------------------" << endl << endl;

        cin >> l_data;
        switch (l_data[0])
        {
        case '1':
            {
                cout << "new and delete:" << endl;
                LearnCpp* l_obj = new LearnCpp("Using_New");
                delete l_obj;
                break;
            }
        case '2':
            {
                LearnCpp obj1("Dummy_1");
                cout << "Copy Constructor:" << endl;
                LearnCpp obj2 = obj1;

                cout << "Assignment Operator:" << endl;
                LearnCpp obj3("Dummy_3");
                obj3 = obj1;

                break;
            }
        case '3':
            {
                testPriorityQueueForObjects();
                break;
            }
        case '4':
            {
                LearnException learnException;
                l_retVal = learnException.printOptions(l_msg + " <> ");
                l_feedBack = l_retVal;
                break;
            }
        case '5':
            {
                LearnTemplates l_templates;
                l_retVal = l_templates.printOptions(l_msg + " <> ");
                l_feedBack = l_retVal;
                break;
            }
        case '6':
            {
                TestInheritance l_testInheritance;
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


