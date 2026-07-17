#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class DocumentEditor
{
    vector<string> documentElements;
    string renderedDocument;

public:
    void addImage(string image)
    {
        documentElements.push_back(image);
    }
    void addText(string text)
    {
        documentElements.push_back(text);
    }
    string renderDocument()
    {
        string result;

        for (auto &it : documentElements)
        {
            if (it.size() > 4 &&
                (it.substr(it.size() - 4) == ".jpg" ||
                 it.substr(it.size() - 4) == ".png"))
            {
                result += "Image: [" + it + "]\n";
            }
            else
            {
                result += it + "\n";
            }
        }

        renderedDocument = result;
        return renderedDocument;
    }

    void saveToDB()
    {
        ofstream file("document.txt");
        if (file.is_open())
        {
            file << renderDocument();
            file.close();
        }
        else
            throw runtime_error("Document can't be opened");
    }
};

int main()
{

    DocumentEditor *document = new DocumentEditor();
    document->addText("hello, my name is Ishan");
    document->addImage("ishansphoto.jpg");
    document->renderDocument();
    document->saveToDB();

    return 0;
}