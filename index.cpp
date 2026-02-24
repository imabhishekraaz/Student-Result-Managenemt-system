// #include <iostream>
// #include <vector>
// #include <map>
// using namespace std;

// map that store the key value pairs

// int main(void){
//     map <string , int> names;
//     names["5"] =89;
//     names["2"] = 78;
//     names["3"] = 87;
//     names["4"] = 67;

//     for(auto it : names){
//         cout<<it.first<<":"<<it.second<<endl;
//     }
// }

// map methods--->

// int main(void)
// {

    // store the value

    // map<string, int> names;
    // map<string, int> names1;

    // names["Abhishek"] = 21;
    // names["Abhishek"] = 22;
    // auto value = names.begin();
    // names.clear();
    // cout<<names.size()<<endl;
    // auto value = names.count("Abhishek");
    // auto value = names.crbegin();
    // cout<<value<<endl;
    // auto value = names.emplace("Abhishek");
    // cout<<value<<endl;
    // auto value = names.empty();
    // cout<<value <<endl;
    // auto value = names.end();
    // cout<<value<<endl;
    // auto value = names.value_comp();
    // cout<<value<<endl;
    // names.erase("Abhishek");
    // auto value = names.find("Abhishek");
    // cout<<value<<endl;
    // names.insert({"Ankush",22});
    // auto value = names.lower_bound("Abhishek");
    // cout<<value<<endl;
    // auto value = names.max_size();
    // cout<<value<<endl;

    // if(names.empty()!=1){
    //     for (auto name : names){
    //         cout<<name.first <<" : "<<name.second<<endl;
    //     }
    // }else{
    //     cout<<"No Data Found!"<<endl;
    // }

// #include <iostream>
// #include <map>
// #include <string>

//     using namespace std;

//     class Student
//     {
//     public:
//         string name;
//         int age;

//         Student() {}
//         Student(string n, int a)
//         {
//             name = n;
//             age = a;
//         }

//         void display()
//         {
//             cout << "\nName: " << name;
//             cout << "\nAge: " << age << endl;
//         }
//     };

//     class StudentManagementSystem
//     {

//     private:
//         map<int, Student> students;

//     public:
//         void add_student()
//         {
//             int id, age;
//             string name;

//             cout << "Enter ID: ";
//             cin >> id;

//             cout << "Enter Name: ";
//             cin >> name;

//             cout << "Enter Age: ";
//             cin >> age;

//             students[id] = Student(name, age);
//         }

//         void display_students()
//         {
//             for (auto &s : students)
//             {
//                 cout << "\nID: " << s.first;
//                 s.second.display();
//                 cout << "------------------";
//             }
//         }
//     };

//     int main()
//     {

//         StudentManagementSystem system;

//         system.add_student();
//         system.display_students();

//         return 0;
//     }

// #include<iostream>
// using namespace std;


// class Animal{
//     protected:
//         string name = "Abhishek Raj";
//         int age = 20;
//     string greeting(){
//         return "Congratulation";
//     }    
//     public:
//         void greet(){
//             cout<<greeting()<<endl;
//         }
//         Animal(){
//             cout<<"this is Animal Constructor"<<endl;
//         }
//         void bark(string name){
//             cout<<name<<" is Barking"<<endl;
//         }
// };
// //single inheritance
// class Dog{
//     public:
//         Dog(){
//             cout<<"Dog Constructor"<<endl;
//         }   
//         //dog class eating function
//         void eat(string name){
//             cout<<name<<" is Eating..."<<endl;
//         }
// };
// class Cat : public Animal,public Dog{
//     public:
//         Cat(){
//             cout<<"cat Constructor..."<<endl;
//         }
// };

// int swap_numbers(int,int);

// int main(){
    
    // Cat *c = new Cat;
    // c->eat("hello");
    // c->bark("hello");

    // string names[4] = {"Abhishek Raj","Ankush Raj","arun Chauhan","Brajwasi Singh"};
    // for(int i=0;i<=names->length(); i++){
    //     cout<<i<<" : "<<names[i]<<endl;
    // }
    // for(string &n : names){
    //     cout<<n<<endl;
    // }
    // swap_numbers(2,4);
// }
//function prototype
// int swap_numbers(int a,int b){
//     cout<<"a: "<<a<<" b: "<<b<<endl;
//     int demo = a;
//     a= b;
//     b= demo;
//     cout<<"a: "<<a<<" b: "<<b<<endl;
// }
 //friend function ------>

#include<iostream>
using namespace std;

class Student{
    private:
        string names = "Abhishek Raj";
        int salarys = 200000;
        void greeting(){
            cout<<"welcome "<<names<<endl;
        }
    public:
        Student(string name,int salary){
            names = name;
            salarys= salary;
        }
        friend void getdetails(Student s);
};
void getdetails(Student s){
    //why am i unable to access the private function od the class using the friend function
    cout<<"Name: "<<s.names<<"Salary: "<<s.salarys<<"Greet:\n\t"<<s.greeting()<<endl;

}
int main(void){
    Student s("Abhishek",209090);
    // displayDetails(s);
    getdetails(s);
}