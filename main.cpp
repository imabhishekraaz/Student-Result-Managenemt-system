#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

class StudentResultManagementSystem{

public: 

vector <string> subjectNames = {"Math","English","physics","Chemistry","Hindi"};
vector <string> studentsNames;
vector <int> studentAges;
vector <int> marks;


StudentResultManagementSystem (){
    ifstream file("data.json");
}

void savedData(){
    ofstream file("data.json", ios::app);
    // file>>
}

// void 

void AddStudentDetails(){
    string name;
    int age;

    cout<<"Enter te Student Name: ";
    cin>>name;

    cout<<"Enter the "<<name<<" age:";
    cin>>age;
    
    if(name.empty()|| age<=0){
        cout<<"Invalid input"<<endl;
    } else {
        // studentsNames.push_back(name);
        // studentAges.push_back(age);
        cout<<"hello"<<endl;

    }
    
}

void AddSubjectMarks(){
    int mark;
    for (int i =0; i<subjectNames.size(); i++){
        cout<<subjectNames[i] <<" Marks: ";
        try{
            cin>>mark;
            if(mark>100){
                throw "number can't be Higher than 100";
            } else if (mark<0){
                throw "Number can't be less than Zero";
            } else {
                 marks.push_back(mark);
            }

        } catch (const string* var){
            cout<<var<<endl;
        }
    }
}

void displayDetails(){

    int totalMarks =0;
    int avg = 0;
    int percentage = 0;
    for (int mark : marks){
        totalMarks+=mark;
    }
    avg = totalMarks / marks.size();
    
    percentage = ( avg * 100 ) / 500;

    if (percentage >=90){
        cout<<"Grade A"<<endl;
    } else if (90>percentage<=70){
        cout<<"Grade B"<<endl;
    } else if(70>percentage<=50) {
        cout<<"Grade C"<<endl;
    } else if (60>percentage <= 33){
        cout<<"Grade D"<<endl;
    } else {
        cout<<"Fail"<<endl;
    }

    cout<<"Student marks: "<<endl;
    for(int j =0; j<subjectNames.size(); j++){
        cout<<subjectNames[j]<<" : "<<marks[j]<<endl;
    }
}


};

int main(void) {
    StudentResultManagementSystem s;
    bool isRunning = true;
    int option;

    while(isRunning){
        cout<<"1. Add Student \n2. Add Marks \n3. Display marks \n4. Exit"<<endl;
        cout<<"Enter the option: ";
        cin>>option;

        if (option == 1){
            s.AddStudentDetails();
        } else if(option == 2) {
            s.AddSubjectMarks();
        } else if(option == 3){
            s.displayDetails();
        } else if(option == 4){
            cout<<"Data Saved Succesfully"<<endl;
            break;
        } else {
            cout<<"Invalid Option"<<endl;
        }
    }

    return 0;
}