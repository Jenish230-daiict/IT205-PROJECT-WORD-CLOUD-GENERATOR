#include <SFML\Graphics.hpp>
#include <string>
#include <vector>
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept> 
#include <random>
#include <Windows.h>
using namespace std;
//System:: String^ final(int t, int n, string s, int k);
//void del_list(node* &head);

int lenght = 0;
int max = 1;
class node
{


public:
    string data;
    node* tail;
    node* next;
    int frequency = 1;
    node()
    {
        tail = nullptr;
        next = nullptr;
    }

    friend void del_list(node*& head);
    friend System::String^ final( int n, string s, int k);

    int insert(string s)
    {

        if (tail == nullptr)
        {
            lenght++;
            this->data = s;
            tail = this;
            return 1;
        }

        node* tmp = this;

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
        node* newnode = new node();
        lenght++;
        newnode->data = s;
        tmp->next = newnode;
        tail = newnode;
        return 1;
    }

    void topk(int k, int max, node*& head)
    {
        int c = 0;
        node* tmp;
        node* tp;
        for (int i = max; i >= 1; i--)
        {
            tmp = this;
            while (tmp != nullptr)
            {
                if (tmp->frequency == i)
                {
                    c++;
                    head->insert(tmp->data);

                    if (c == 1) {
                        tp = head;
                        head->frequency = tmp->frequency;
                    }
                    else {
                        tp = tp->next;
                        tp->frequency = tmp->frequency;
                    }

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

node* head1 = new node;
node* head2 = new node;
node* newhead = new node;
node* head3 = new node;;
void generateWordCloud2(node* head,string s);
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

void main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	$safeprojectname$::MyForm form;
	Application::Run(% form);
}





string content;
vector<string> pdfPaths;
string outputFilePath;
string pdfPath;



void del_list(node*& head)
{
    node* current = head;
    node* nxt;

    while (current != nullptr)
    {
        nxt = current->next;
        delete current;
        current = nxt;
    }

    head = nullptr;
}
string readFromFile(const string& filename)
{
    ifstream fin(filename);
    if (!fin.is_open())
    {
       
        return "";
    }

    string content;
    string line;
    while (getline(fin, line))
    {
        content += line; // Append line with newline character
    }

    content += " ";

    fin.close();

    return content;
}

int store_list(string& content, node*& head)
{

    if (content == "")
    {
        cout << "Your File is / are empty !" << endl;
        return 0;
    }
    string word = "";
    int max = 0;
    for (int i = 0; i < content.length(); i++)
    {

        if (content[i] >= 'A' && content[i] <= 'Z')
        {
            content[i] += 32;
            // convert all character to small
        }

        if (content[i] == ' ' || content[i] == '\t' || content[i] == '\n' || content[i] == '.' || content[i] == ',' || content[i] == '?' || content[i] == '!' || content[i] == '\"' || content[i] == '\'' || content[i] == '(' || content[i] == '{' || content[i] == '[' || content[i] == ')' || content[i] == '}' || content[i] == ']')
        {
            if ((word == ",") || (word == ".") || (word == " ") || (word == ";") || (word == "") || (word == "is") || (word == "i") || (word == "a") || (word == "my") || (word == "were") || (word == "has") || (word == "we") || (word == "every") || (word == "an") || (word == "the") || (word == "of") || (word == "from") || (word == "to") || (word == "when") || (word == "will") || (word == "be") || (word == "but") || (word == "in") || (word == "and") || (word == "for") || (word == "you") || (word == "are") || (word == "if") || (word == "while") || (word == "not") || (word == "been") || (word == "other") || (word == "need") || (word == "also") || (word == "it") || (word == "without") || (word == "itself") || (word == "etc") || (word == "which") || (word == "common") || (word == "commonly") || (word == "with") || (word == "like") || (word == "so") || (word == "may") || (word == "as") || (word == "this") || (word == "it") || (word == "||") || (word == "that") || (word == "more") || (word == "any") || (word == "many") || (word == "with") || (word == "some") || (word == "have") || (word == "am") || (word == "their") || (word == "only") || (word == "these") || (word == "on") || (word == "they") || (word == "there") || (word == "was") || (word == "her") || (word == "she") || (word == "upon") || (word == "once") || (word == "at") || (word == "about") || (word == "than") || (word == "our") || (word == "through") || (word == "them") || (word == "then") || (word == "by") || (word == "can") || (word == "s"))
            {
                word = "";
                continue;
            }

            if (word.length() == 1 || word.length() == 0)
            {
                word = "";
                continue;
            }

        start:
            int tmp = head->insert(word);
            max = (max > tmp) ? max : tmp;
            word = "";
            continue;
        }

        if (content[i] == 'e' && content[i + 1] == 's' && content[i + 2] == 's' && !((content[i + 3] >= 'a' && content[i + 3] <= 'z') || (content[i + 3] >= 'A' && content[i + 3] <= 'Z')))
        {
            // Condition 2 - "es" at the end (e.g., houses -> house)
            word += content[i];
            i++;
            word += content[i];
            i++;
            word += content[i];
            i++;
            goto start;
        }

        if (content[i - 1] == content[i] && content[i + 1] == 'e' && content[i + 2] == 's' && (!((content[i + 3] >= 'a' && content[i + 3] <= 'z') || (content[i + 3] >= 'A' && content[i + 3] <= 'Z'))))
        {
            // Condition 3 - Doubled consonant before "es" (e.g., glasses -> glass)
            word += content[i];
            i++;
            i++;
            goto start;
        }

        if (content[i] == 'v' && content[i + 1] == 'e' && content[i + 2] == 's')
        {
            // Condition 4 - "ves" to "f" || "fe"
            if ((content[i - 1] == 'i') && content[i - 2] != 'r')
            {
                word += "fe";
                i++;
                i++;
                goto start;
            }
            else if ((content[i - 1] == 'l' || content[i - 1] == 'o' || content[i - 1] == 'e' || content[i - 1] == 'a' || content[i - 1] == 'r') && content[i - 2] != 'o')
            {
                word += "f";
                i++;
                i++;
                goto start;
            }
            else
            {
                word += content[i];
                i++;
                word += content[i];
                i++;
                goto start;
            }
        }

        if (content[i] == 'i' && content[i + 1] == 'e' && content[i + 2] == 's' && (!((content[i + 3] >= 'a' && content[i + 3] <= 'z') || (content[i + 3] >= 'A' && content[i + 3] <= 'Z'))))
        {
            // Condition 5 - "ies" to "y" (e.g., flies -> fly)
            if (content[i - 1] == 'b' || content[i - 1] == 'c' || content[i - 1] == 'd' || content[i - 1] == 'f' || content[i - 1] == 'g' || content[i - 1] == 'l' || content[i - 1] == 'm' || content[i - 1] == 'n' || content[i - 1] == 'p' || content[i - 1] == 's' || content[i - 1] == 't' || content[i - 1] == 'a' || content[i - 1] == 'e' || content[i - 1] == 'i' || content[i - 1] == 'o' || content[i - 1] == 'u')
            {
                word += "y";
                i++;
                i++;
                goto start;
            }
        }

        if ((content[i] == 's' && (!((content[i + 1] >= 'a' && content[i + 1] <= 'z') || (content[i + 1] >= 'A' && content[i + 1] <= 'Z'))) && (content[i - 1] >= 'a' && content[i - 1] <= 'z') && (content[i - 1] == 't' || content[i - 1] == 'y' || content[i - 1] == 'k' || content[i - 1] == 'n' || content[i - 1] == 'd' || content[i - 1] == 'g' || content[i - 1] == 'o' || content[i - 1] == 'l' || content[i - 1] == 'w' || content[i - 1] == 'm' || content[i - 1] == 'e' || content[i - 1] == 'r')))
        {
            goto start;
        }

        

            if (content[i] == '\0')
            {
                break;
            }

        word += content[i];
    }
    return max;
}

int store_list_cpp(string& content, node*& head)
{
    string word = "\0";

    if (content == "\0")
    {
        cout << "Your document is empty.\n";
        return 0;
    }

    int max = 1;
    for (int i = 0; i < content.length(); i++)
    {
        if ((int)content[i] < 0 && (int)content[i] >= 128)
        {
            continue;
        }
        // Convert capital to small for better conversation
        if (content[i] >= 'A' && content[i] <= 'Z')
        {

            // cout << "\nCondition 1";
            content[i] += 32;
        }

        if ((content[i] == '\'') && (content[i + 1] == 's'))
        {
            i++;
            continue;
        }

        if ((content[i + 1] == ';') && !((content[i] == '\t') || (content[i] == '(') || (content[i] == ')') || (content[i] == ';') || ((int)content[i] < 0) || ((int)content[i] >= 128) || (content[i] == '}') || (content[i] == '"')))
        {
            // cout << "\nCondition 17";
            word += content[i];
            goto start;
        }

        if (content[i + 1] == ';')
        {
            if (content[i] != ')' && content[i] != '}' && content[i] != '"' && content[i] == '(' && content[i] == ')' && content[i] == ';' && content[i] == '<')
            {
                word += content[i];
                goto start;
            }
            else
            {
                goto start;
            }
        }

        if ((content[i] == '\t') || content[i] == '\'' || content[i] == ')' || ((int)content[i] < 0) || ((int)content[i] >= 128) || (content[i] == '}') || (content[i] == '"') || (content[i] == '_') || ((content[i] == '>' || content[i] == '<') && (content[i + 1] != '<' || content[i - 1] == '<' || content[i + 1] != '>' || content[i - 1] == '>')))
        {
            // cout << "\nCondition 2";
            continue;
        }

        // Adding word in node if { is detected
        if (content[i + 1] == '{')
        {
            // cout << "\nCondition 13";
            word += content[i];
            goto start;
        }

        // If derefernce symbol detects

        if (content[i] == '-' && content[i + 1] == '>')
        {
            // cout << "\nCondition 3";
            goto start;
        }

        // Adding derefernce symbol
        if (content[i - 1] == '-' && content[i] == '>')
        {
            // cout << "\nCondition 4";
            word += content[i - 1] + content[i];
            goto start;
        }

        if (content[i] == 'e' && content[i + 1] == 's' && content[i + 2] == 's' && !((content[i + 3] >= 'a' && content[i + 3] <= 'z') || (content[i + 3] >= 'A' && content[i + 3] <= 'Z')))
        {
            // Condition 2 - "es" at the end (e.g., houses -> house)
            word += content[i];
            i++;
            word += content[i];
            i++;
            word += content[i];
            i++;
            goto start;
        }

        if (content[i - 1] == content[i] && content[i + 1] == 'e' && content[i + 2] == 's' && (!((content[i + 3] >= 'a' && content[i + 3] <= 'z') || (content[i + 3] >= 'A' && content[i + 3] <= 'Z'))))
        {
            // Condition 3 - Doubled consonant before "es" (e.g., glasses -> glass)
            word += content[i];
            i++;
            i++;
            goto start;
        }

        if (content[i] == 'v' && content[i + 1] == 'e' && content[i + 2] == 's')
        {
            // Condition 4 - "ves" to "f" || "fe"
            if ((content[i - 1] == 'i') && content[i - 2] != 'r')
            {
                word += "fe";
                i++;
                i++;
                goto start;
            }
            else if ((content[i - 1] == 'l' || content[i - 1] == 'o' || content[i - 1] == 'e' || content[i - 1] == 'a' || content[i - 1] == 'r') && content[i - 2] != 'o')
            {
                word += "f";
                i++;
                i++;
                goto start;
            }
            else
            {
                word += content[i];
                i++;
                word += content[i];
                i++;
                goto start;
            }
        }

        if (content[i] == 'i' && content[i + 1] == 'e' && content[i + 2] == 's' && (!((content[i + 3] >= 'a' && content[i + 3] <= 'z') || (content[i + 3] >= 'A' && content[i + 3] <= 'Z'))))
        {
            // Condition 5 - "ies" to "y" (e.g., flies -> fly)
            if (content[i - 1] == 'b' || content[i - 1] == 'c' || content[i - 1] == 'd' || content[i - 1] == 'f' || content[i - 1] == 'g' || content[i - 1] == 'l' || content[i - 1] == 'm' || content[i - 1] == 'n' || content[i - 1] == 'p' || content[i - 1] == 's' || content[i - 1] == 't' || content[i - 1] == 'a' || content[i - 1] == 'e' || content[i - 1] == 'i' || content[i - 1] == 'o' || content[i - 1] == 'u')
            {
                word += "y";
                i++;
                i++;
                goto start;
            }
        }

        if ((content[i] == 's' && (!((content[i + 1] >= 'a' && content[i + 1] <= 'z') || (content[i + 1] >= 'A' && content[i + 1] <= 'Z'))) && (content[i - 1] >= 'a' && content[i - 1] <= 'z') && (content[i - 1] == 't' || content[i - 1] == 'y' || content[i - 1] == 'k' || content[i - 1] == 'n' || content[i - 1] == 'd' || content[i - 1] == 'g' || content[i - 1] == 'o' || content[i - 1] == 'l' || content[i - 1] == 'w' || content[i - 1] == 'm' || content[i - 1] == 'e' || content[i - 1] == 'r')))
        {
            goto start;
        }

        // Adding ++ >> << --
        if ((content[i] == '>' || content[i] == '<' || content[i] == '+' || content[i] == '-') && (content[i + 1] == '>' || content[i + 1] == '<' || content[i + 1] == '+' || content[i + 1] == '-'))
        {
            // cout << "\nCondition 10";
            word += content[i];
            i++;
            word += content[i];
            goto start;
        }

        // Adding operators
        if ((content[i] == ';') || (content[i] == '+') || (content[i] == '=') || (content[i] == '-') || (content[i] == '*') || (content[i] == '/') && ((content[i + 1] != '+') && (content[i - 1] == '+') || ((content[i - 1] != '-') && (content[i + 1] == '-'))))
        {
            // cout << "\nCondition 11";
            word += content[i];
            goto start;
        }

        // Adding whole content of [] braces
        if (content[i] == '[')
        {
            // cout << "\nCondition 12";
            for (; content[i] != ']'; i++)
            {
                word += content[i];
            }
        }

        // Adding {} brackets
        if (content[i] == '{')
        {
            // cout << "\nCondition 14";
            word = "{}";
            goto start;
        }

        // Adding \n in node
        if (content[i - 1] == '\\' && content[i] == 'n')
        {
            word += content[i];
            goto start;
        }

        // Add word in node if next character is not an alphabet
        if ((content[i] >= 'a' && content[i] <= 'z') && !((content[i + 1] >= 'a' && content[i + 1] <= 'z') || (content[i + 1] >= 'A' && content[i + 1] <= 'Z')))
        {
            // cout << "\nCondition 15";
            word += content[i];
            goto start;
        }

        // Adding () brackets
        if (content[i] == '(')
        {
            // cout << "\nCondition 16";
            word += "()";
            goto start;
        }

        // Adding word in node if ; is detected
        if ((content[i + 1] == ';') && !((content[i] == '\t') || (content[i] == '(') || (content[i] == ')') || (content[i] == ';') || ((int)content[i] < 0) || ((int)content[i] >= 128) || (content[i] == '}') || (content[i] == '"')))
        {
            // cout << "\nCondition 17";
            word += content[i];
            goto start;
        }

        // Adds : and = in word
        if (content[i] == ':' || content[i] == '=')
        {
            // cout << "\nCondition 18";
            word += content[i];
            goto start;
        }

        // Skipping new line character
        if ((content[i] == '\n') || (((content[i] >= 'a' && content[i] <= 'z')) && (content[i + 1] == '\n')))
        {
            // cout << "\nCondition 19";
            i++;
            continue;
        }

        // Remove . and , from word
        if ((content[i] == '.' || content[i] == ',') && ((content[i + 1] == ' ')) && (!(i == (content.length() - 1))))
        {
            // cout << "\nCondition 20";
            i++;
            goto start;
        }

        // Add character in word until space character detected
        if ((content[i] != ' ') || ((content[i] == '.')))
        {
            // cout << "\nCondition 21";
            word += content[i];
        }

        // Special condition for last element.
        if (((content[i] == '.' || content[i] == ',') && (i == (content.length() - 1))) || ((content[i] == '.' || content[i + 1] == '\n')))
        {
            // cout << "\nCondition 22";
            for (int j = 0; j < word.length(); j++)
            {

                if (word[j] == '.' || word[j] == '(' || word[j] == ',' || word[j] == '\'' || word[j] == '`' || word[j] == '\t' || word[j] == '_')
                {

                    word.erase(j, 1);
                    j--; // Adjust for potential changes in string length
                }
            }

            goto start;
        }

        // Add word(word) to node when space character detected
        if ((content[i] == ' ') || ((content[i] == '.')) || ((content[i] >= 'a' && content[i] <= 'z')) && (i == (content.length() - 1) || (content[i + 1] == '\t')))
        {
        start:
            content[i] += '\0';

            // Removal of not important words
            if (!(((word == ",") || (word == ".") || (word == " ") || (word == "\0") || (word == "is") || (word == "my") || (word == "were") || (word == "has") || (word == "we") || (word == "an") || (word == "the") || (word == "of") || (word == "from") || (word == "to") || (word == "when") || (word == "often") || (word == "will") || (word == "also") || (word == "be") || (word == "but") || (word == "in") || (word == "without") || (word == "it") || (word == "also") || (word == "and") || (word == "you") || (word == "are") || (word == "etc") || (word == "which") || (word == "common") || (word == "commonly") || (word == "with") || (word == "like") || (word == "so") || (word == "been") || (word == "may") || (word == "as") || (word == "this") || (word == "it") || (word == "||") || (word == "that") || (word == "other") || (word == "more") || (word == "any") || (word == "many") || (word == "with") || (word == "some") || (word == "not") || (word == "itself") || (word == "have") || (word == "am") || (word == "their") || (word == "only") || (word == "these") || (word == "on") || (word == "they") || (word == "there") || (word == "was") || (word == "her") || (word == "she") || (word == "alway") || (word == "always") || (word == "upon") || (word == "once") || (word == "at") || (word == "without") || (word == "own") || (word == "about") || (word == "than") || (word == "our") || (word == "through") || (word == "them") || (word == "then") || (word == "by") || (word == "can"))))
            {

                int tmp = head->insert(word);
                max = (max > tmp) ? max : tmp;
            }

            word = "\0";
        }
    }

    return max;
}



string extractPDFContent(string &pdfpath)
{
    // Use system call to extract text using pdftotext (assuming it's installed)
    pdfPath[pdfPath.length() - 1] = 't';
    pdfPath[pdfPath.length() - 2] = 'x';
    pdfPath[pdfPath.length() - 3] = 't';

    string temp = pdfpath;

    string command = "pdftotext " + temp + pdfpath;


    temp = readFromFile(pdfpath);
    return temp;
}

void process_path( string& path)
{
    content += readFromFile(path);
    content += " ";
}
void process_path2( string& path)
{
    pdfPaths.push_back(path);
    for ( string& pdfPath : pdfPaths)
    {
        string extractedContent = extractPDFContent(pdfPath);
        if (!extractedContent.empty())
        {
            content += extractedContent;
        }
    }
}

void separate_and_call(const string& data_string)
{
    istringstream iss(data_string);
    string path;

    while (getline(iss, path))
    {
        process_path(path);
    }
}

void separate_and_call2(const string& data_string)
{
    istringstream iss(data_string);
    string path;

    while (getline(iss, path))
    {
        process_path2(path);
    }
}





System::String^ final( int n, string s, int k) {
   
    System::String^ result = "";
    string path="";
    int i,j,c;
	 
         j = 0;
         c = 0;
        separate_and_call(s);
      
       
int max = store_list(content, head1);
        
        head1->topk(k, max, newhead);
       del_list(head1);
		
    
    head1 = newhead;
    i = 0;
   while (head1 != nullptr) {
        i++;
       result += i;
        result += " ";
        result += msclr::interop::marshal_as<System::String^>(head1->data);
        result += " : ";
        result += head1->frequency;
        result += "\n";
        head1 = head1->next;
   }

  
    return result ;
}





void generateWordCloud2(node* head, string s) {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Word Cloud Generator");

    std::map<std::string, int> wordFrequency;
    node* current = head;
    while (current != nullptr) {
        wordFrequency.insert(pair<std::string,int>(current->data, current->frequency));
        

        current = current->next;
    }

    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\jenis\\Downloads\\AmaticSC-Regular.ttf")) {
        std::cerr << "Error loading font file." << std::endl;
        return;
    }
    //"C:\Users\jenis\Downloads\super_toast\""C:\Users\jenis\Downloads\"

    int maxFontSize = 200; // Max font size for word cloud
    int minFontSize = 30; // Min font size for word cloud

    int maxFrequency = 0;
    for (const auto& pair : wordFrequency) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
        }
    }

    sf::Text text;
    text.setFont(font);

    std::vector<sf::FloatRect> usedPositions;
    window.clear(sf::Color::White);
    
    int i = 0;
    for (const auto& pair : wordFrequency) {
        
        text.setString(pair.first);
        float fontSize = minFontSize + (maxFontSize - minFontSize) * (pair.second / static_cast<float>(maxFrequency));
        text.setCharacterSize(static_cast<int>(fontSize));
        switch (i) {
        case 0:text.setFillColor(sf::Color::Red);
            break;
        case 1:text.setFillColor(sf::Color::Green);
            break;
        case 2:text.setFillColor(sf::Color::Blue);
            break;
        case 3:text.setFillColor(sf::Color::Black);
            break;
        case 4:text.setFillColor(sf::Color::Yellow);
            break;
        case 5:text.setFillColor(sf::Color::Magenta);
            break;
        case 6:text.setFillColor(sf::Color::Cyan);
            break;
        }
      text.Bold;
     
     
        i++;
        if (i == 6) {
            i = 1;
        }
        sf::FloatRect Wind(0, 0, window.getSize().x - 50, window.getSize().y - 50);
        bool overlapping = true;
        while (overlapping) {
            float posX = rand() % 1200;
            float posY = rand() % 1000;
            text.setPosition(posX, posY);

            overlapping = false;
            sf::FloatRect textBounds = text.getGlobalBounds();
            for (const auto& usedPosition : usedPositions) {
                if (textBounds.intersects(usedPosition)||!textBounds.intersects(Wind)) {
                    overlapping = true;
                    break;
                }
            }
        }

        usedPositions.push_back(text.getGlobalBounds());
        window.draw(text);
    }

    //window.display();

    sf::Texture texture;
    texture.create(window.getSize().x, window.getSize().y);
    texture.update(window);
    string Outputpng = s + "\\Output.png";
    if (texture.copyToImage().saveToFile(Outputpng)) {
        ShellExecute(NULL, "open", Outputpng.c_str(), NULL, NULL, SW_SHOWNORMAL);
    }
    window.close();
}


