#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;


/*PASS BY REFERENCE*/
int dubRef(int &i) {
    i = i + i;
}
int dubPoint(int *i) {
    *i = *i + *i;
}

int dubVal(int i) {
    i = i + i;
}

/*CLASSES*/
class Person {
private:
    int height, weight;
public:
    string EyeColor, Gender, Name;

    /*Person(string ec, string g, string n, int h, int w) {
        EyeColor = ec;
        Gender = g;
        Name = n;
        height = h;
        weight = w;
        if(ec == "boy")
            EyeColor = "Purple";
        else
            EyeColor = "Majenta";
    }*/

    Person(string ec, string g, string n, int h, int w): Gender(g), Name(n), height(h), weight(w) {
        cout << "I was instantiated!" << endl;
        if(ec == "boy")
            EyeColor = "Purple";
        else
            EyeColor = "Majenta";

    }

    void tellInformation() {
        cout << "My name is " << Gender << ", my height is " << height;
        cout << " inches, and my weight is " << weight << " pounds." << endl;
    }
};

void tellPersonInfo(Person p) {
    p.tellInformation();
}

/*TEMPLATING*/
template <typename T>
class DataClass {
private:
    T data;
public:
    DataClass(T data) {
        this->data = data;
    }

    T getData() {
        return this->data;
    }
};

template <typename T>
void printOut(T data) {
    cout << data << ", ";
}

void printOut(int data) {
    cout << data << ", ";
}

/*ALGORITHMS LIBRARY*/

bool compare(int i,int j) {
    return (i<j);
}

int main() {
    // Input and Output
    int var;
    cin >> var;
    cout << var << "\n" << endl;

    //USING standard library
    std::cin >> var;
    std::cout << var << endl << endl;
    cin >> var;
    cout << var << endl << endl;

    //Strings
    string namer = "riley";
    if(namer == "riley")
        cout << "nice" << endl;

    cout << "AND HIS NAME IS " << namer << endl;

    //Pass by Reference
    int test1 = 9, test2 = 8;
    cout << "The original value of test1 is " << test1 << endl;
    dubVal(test1);
    cout << "The value of test1 after passing by value is " << test1 << endl;
    dubRef(test1);
    cout << "The value of test1 after passing by reference is " << test1 << endl;

    cout << "The original value of test2 is " << test2 << endl;
    dubPoint(&test2);
    cout << "The value of test2 after passing by pointer is " << test2 << endl;

    //Class
    Person b = Person("Blue", "Boy", "RJ", 73, 135);
    b.tellInformation();
    Person g = Person("Red", "Girl", "Stacy", 60, 110);
    Person z = Person("Green", "Zer", "Ztacy", 60, 110);

    vector<Person> people = vector<Person>({b, g, z});
    for(auto p : people)
        p.tellInformation();

    //Templates
    DataClass<int> i = DataClass<int>(5);
    DataClass<string> s = DataClass<string>("NICE!");
    cout << i.getData() << endl << s.getData() << endl;

    //Algorithms
    vector<int> v = {33, 23, 2, 1};
    v.push_back(33);
    v.push_back(23);
    v.push_back(2);
    v.push_back(1);
    for_each(v.begin(), v.end(), printOut<int>);
    cout << endl << endl;
    for_each(v.begin(), v.end(), dubRef);
    for_each(v.begin(), v.end(), printOut<int>);
    cout << endl << endl;

    for_each(v.begin(), v.end(), printOut<int>);
    cout << endl << endl;
    sort(v.begin(), v.end(), compare);
    for_each(v.begin(), v.end(), printOut<int>);
    cout << endl << endl;


    vector<int> needles = {33, 22, 2};
    for(auto needle: needles){
        if(binary_search(v.begin(), v.end(), needle))
            cout << "Found the value " << needle << "! :)" << endl;
        else
            cout << "Did not find the value " << needle << "! >:(" << endl;
    }
}
