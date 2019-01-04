// Gerard Lawrence
// Program: C++
// The purpose of this program is to write out a paragraph about the user after they enter their information.
// The program was used to learn getline.


#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    string city;
    int age;
    string college;
    string profession;
    string animal;
    string petName;
    
    cout << "What is your name? ";
    getline(cin, name);
    
    cout << "What city do you live in? ";
    cin >> city;
    
    cout << "How old are you? ";
    cin >> age;
    cin.ignore();
    
    cout << "Where did you go to college? ";
    getline (cin, college);
    
    cout << "What is your profession? ";
    getline (cin, profession);
    
    cout << "What kind of Animal is it? ";
    getline (cin, animal);
    
    cout << "What is the pet's name? ";
    getline (cin, petName);
    
    cout << "There once was a person named " << name << " who lived in " << city << "." << endl;
    cout << "At the age of " << age << ", " << name << " went to college at " << college << ". " << endl;
    cout << name << " graduated and went to work as a(n) " << profession << ". " << endl;
    cout << "Then, " << name << " adopted a(n) " << animal << " named " << petName << ". " << endl;
    cout << "They both lived happily ever after!" << endl;
    
    return 0;
}
