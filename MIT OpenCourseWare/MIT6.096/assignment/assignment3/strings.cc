#include <iostream>
#include <string>

using namespace std;

const string vowels = "aeiou";

string pigLatinify(string english)
{
    string newstring;
    if(english.size() == 0)
        return english;


    if(english.find("qu")==0)
    {
        newstring = english.substr(2,english.size()-1) + "-" + english.substr(0,2) +"ay";
    }
    else if(vowels.find(english[0]) != string::npos)
    {
        newstring = english + "way";
    }
    else
    {
        newstring = english.substr(1,english.size()-1) + "-" + english[0] + "ay";
    }

    return newstring;
}


int main()
{
    string s1 = "question";
    string s2 = "beast";
    string s3 = "dough";
    string s4 = "happy";
    cout << pigLatinify(s1) << endl;
    cout << pigLatinify(s2) << endl;
    cout << pigLatinify(s3) << endl;
    cout << pigLatinify(s4) << endl;


}
