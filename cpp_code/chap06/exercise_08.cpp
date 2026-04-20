#include <iostream>
#include <string>
using namespace std;

class WordUtility
{
private:
    /* data */
public:
    int wordcnt = 0;
    WordUtility(/* args */);
    ~WordUtility();
    static int wordCount(string count);
    static int getWord(string word);
};

int WordUtility::wordCount(string count)
{
    string text(count);
    int size = text.size();

    for (int i = 0; i < size; i++)
    {
        if (text[i] == ' ')
            this->wordcnt++;
    }
}
cout << wordcnt;
return 0;
}

int WordUtility::getWord(string word)
{

    return 0;
}

WordUtility::WordUtility(/* args */)
{
}

WordUtility::~WordUtility()
{
}

int main()
{
    int n = WordUtility::wordCount("I Love C++");
    cout << "단어 개수는" << n << endl;
    // string word = WordUtility::getWord("I love C++", 3);
    // if (word == "")
    //     cout << "3번째 단어는 없습니다." << endl;
    // else
    //     cout << "3번째 단어는 " << word << endl;
    return 0;
}