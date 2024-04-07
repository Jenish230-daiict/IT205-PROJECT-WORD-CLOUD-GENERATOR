#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int lenght = 0;
class node
{

private:
    string data;
    node *tail;
    node *next;
    int frequency = 1;

public:
    node()
    {
        tail = nullptr;
        next = nullptr;
    }
    
    friend void del_list(node *&head);
    int insert(string s)
    {
         
        if (tail == nullptr)
        {

            this->data = s;
            tail = this;
            return 1;
        }

        node *tmp = this;

        while (tmp->next != nullptr)
        {
            if (tmp->data == s)
            {
                tmp->frequency++;

                return tmp->frequency;
            }
            tmp = tmp->next;
        }

        if (tmp->data == s)
        {
            tmp->frequency++;

            return tmp->frequency;
        }
        node *newnode = new node();
        newnode->data = s;
        tmp->next = newnode;
        tail = newnode;
        return 1;
    }

    

    

    int display()
    {
        node *tmp = this;
        cout << endl
             << endl;

        while (tmp != NULL)
        {
            lenght++;
            //cout << lenght << " : " << tmp->data << "  :  " << tmp->frequency << endl;

            
            tmp = tmp->next;
        }
        return lenght;
    }
    int freq()
    {
        return frequency;
    }

    void topk(int k, int max)
    {
        int c = 0;
        node *tmp;
        node *tp;
        for (int i = max; i >= 1; i--)
        {
            tmp = this;
            while (tmp != nullptr)
            {
                if (tmp->frequency == i)
                {
                    c++;
                    cout << endl
                         << setw(3) << left
                         << c << " : " << setw(15) << left << tmp->data << " : " << tmp->frequency << " times";
                         tmp = tmp->next;
                    if (c == k)
                    {
                        break;
                    }
                }
                else
                {
                    tmp = tmp->next;
                }
            }
            if (c == k)
            {
                break;
            }
        }
    }
};

void del_list(node *&head)
{
    node *current = head;
    node *nxt;

    while (current != nullptr)
    {
        nxt = current->next;
        delete current;
        current = nxt;
    }

    head = nullptr; 
}
