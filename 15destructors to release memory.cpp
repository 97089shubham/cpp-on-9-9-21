#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
using namespace std;


class human{
    private:
        string *name;
        int *age;
    public:
        human(string iname,int iage){
            name=new string;
            age = new int;
            *name=iname;
            *age=iage;
        }
        void display(){
            cout<<"hi i am "<<*name<<" my age is "<<*age;
        }
        ~human(){
            delete name;
            delete age;
            cout<<endl<<"destructor";
        }
};


int main()
{
    human *a=new human("shubham",18);
    a->display();
    delete a;
}

// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <stack>
// #include <vector>
// using namespace std;


// class human{
//     public:
//         static int human_count;
//         human(){
//             human_count++;
//         }
//         void humantotal(){
//             cout<<human_count<<endl;
//         }

//         static void humancount(){
//             cout<<human_count<<endl;
//         }
// };
// int human::human_count=0;

// int main()
// {
//     human a;
//     human b;
//     human c;
//     b.humancount();
// }