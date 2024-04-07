#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "doc.cpp"
using namespace std;

int main()
{
    int choice;
    int n;
    cout << endl
         << endl
         << internal << "<<----- WELCOME TO THE WORD CLOUD GENERATOR ----->>" << endl
         << endl;

label:
    cout << "\nEnter choose corresponding document as you want add for word cloud generator.\nEnter 1 for TEXT.\nEnter 2 for CPP.\nEnter 3 for PDF.\n";
    cin >> choice;

    if (choice != 1 && choice != 2 && choice != 3)
    {
        cout << "Enter correct number.\n";
        goto label;
    }

    cout << "Enter the number of document that you want to add in generator : ";
    cin >> n;

    string content = "", s;
    vector<string> pdfPaths;
    string outputFilePath;
    string pdfPath;
    node *head = new node;
    node list;
    int max;

    switch (choice)
    {
    case 1:

        cin.ignore();
        for (int i = 1; i <= n; i++)
        {
            cout << "Enter the path of file " << i << " : ";
            getline(cin, s);
            content += readFromFile(s);
            
        }

        if (content == "" || content == "\0")
        {
            cout << "\nYour docs content is empty.\n";
            cout << "If you want to restart Press 1.\nPress 2 to exit.\n";
            cin >> choice;

            if (choice == 1)
            {
                goto label;
            }
            else
            {
                cout << endl
                     << endl
                     << "Thank you !";
                return 0;
            }
        }

        max = store_list(content, head);

        break;

    case 2:

        cin.ignore();
        for (int i = 1; i <= n; i++)
        {
            cout << "Enter the path of file " << i << " : ";
            getline(cin, s);
            content += readFromFile(s);
            
        }

        if (content == "" || content == "\0")
        {
            cout << "\nYour docs content is empty.\n";
            cout << "If you want to restart Press 1.\nPress 2 to exit.\n";
            cin >> choice;

            if (choice == 1)
            {
                goto label;
            }
            else
            {
                cout << endl
                     << endl
                     << "Thank you !";
                return 0;
            }
        }

        max = store_list_cpp(content, head);

        break;
    case 3:

        cin.ignore();
        for (int i = 1; i <= n; i++)
        {
            cout << "Enter the path of file " << i << " : ";
            getline(cin, pdfPath);
            pdfPaths.push_back(pdfPath);
        }

        //g:\My Drive\Classroom\sample.pdf

        // Process each PDF file and accumulate content
        for (string &pdfPath : pdfPaths)
        {
            string extractedContent = extractPDFContent(pdfPath);
            if (!extractedContent.empty())
            {
                content += extractedContent;
            }
        }

        if (content == "" || content == "\0")
        {
            cout << "\nYour docs content is empty.\n";
            cout << "If you want to restart Press 1.\nPress 2 to exit.\n";
            cin >> choice;

            if (choice == 1)
            {
                goto label;
            }
            else
            {
                cout << endl
                     << endl
                     << "Thank you !";
                return 0;
            }
        }

        max = store_list(content, head);

        break;

    }
    head->display();
    cout
        << "There are total " << lenght << " distinct words.\n"
        << "How many words you want for this generator : ";
start:
    cin >> n;
    if (n > lenght or n < 1)
    {
        cout << "Please enter valid input between  1 to " << lenght << " : ";
        goto start;
    }
    head->topk(n, max);
    cout << endl
         << endl
         << "Thank you !";

    del_list(head);

    return 0;
}