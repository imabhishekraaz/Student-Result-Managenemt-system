#include<iostream>
#include<map>
#include<string>
#include<windows.h>
#include<vector>

using namespace std;


class StudentManagementSystem {
    public:
    struct user_details{
        string student_name;
        int student_age;
        int password;
        map<string, float> subject_marks;
    };
    map<int,user_details> student;
        
  
};

class Student : public StudentManagementSystem{
    private:
        map <string,int> teacherPanel = {
            {"Abhishek", 1234}
        };
        
    public:
    user_details user;
    //add student details
    void add_student_detail(int id,string name, int age,int password){
        user.student_name = name;
        user.student_age = age;
        user.password = password;
        student[id] = user;
    }
    //delete student 
    void delete_student(string name,int id){
        string student_name = name;
        int student_id = id;
        for(auto std : student){
            Sleep(2000);
            if(std.first==student_id && std.second.student_name==student_name){
                student.erase(student_id);
                cout<<"Deleted Sucessfully"<<endl;
            }else{
                cout<<"Not Founded"<<endl;
            }
        }
    }
    //add student marks
    void add_student_marks(){
        string subjects[5] = {"Hindi","English","Mathematics","Chemistry","Physics"};
        float subject_marks;
        for(string subject : subjects){
            cout<<"Enter "<<subject<<" Marks: ";
            cin>>subject_marks;
            user.subject_marks[subject] = subject_marks;
        }
        cout<<"Added Succesfully"<<endl;
    }
    //get student marks
    void get_student_marks(){
        for(auto marks : user.subject_marks){
            cout<<marks.first<<" : "<<marks.second<<endl;
        }
    }
    //geting the student details ig: Name,Age,ID
    void studentProfile(){
        for(auto name : student){
            cout<<"Id: "<<name.first <<"\nName: "<<name.second.student_name<<"\nAge: "<<name.second.student_age<<endl;
        }
    }
    //for searching the student
    void search_student(string name, int id){
        for(auto std : student){
            cout<<"Searching"<<endl;
            Sleep(2000);
            if(std.second.student_name==name && std.first==id){
                cout<<"Founded"<<endl;
            }else{
                cout<<"Not Founded"<<endl;
            }
        }
    }
    //teacher portal for check the teacher is real or not
    void teacherPortal(){
        
        string teacherName;
        int password;
        cout<<"Welcome to teacher panel: "<<endl;
        cout<<"Enter the Username: ";
        cin>>teacherName;
        cout<<"Enter the password: ";
        cin>>password;
        for(auto teacher : teacherPanel){
            if(teacher.first == teacherName && teacher.second== password){
                Sleep(2000);
                cout<<"Login Sucessfully"<<endl;
                controlsForTeacher();
            }
            else{
                cout<<"Something went wrong"<<endl;
                teacherPortal();
            }
        }
    };
    //control panel for teacher where the teacher can Add,Delete,search,Add Marks,
    void controlsForTeacher(){
        bool is_running = true;
        while(is_running){
            int userOption;
            //also add a section where teacher can update the marks (UpdateMarks)
            cout<<"1.Add_student\n2.Delete Student\n3.Search Student\n4.Add Marks\n5.Menu\n6.Exits"<<endl;
            cout<<"Enter the Option: ";
            cin>>userOption;

            if(userOption == 1){
                string name;
                int age,id,password;
                cout<<"Enter Student ID: ";
                cin>>id;
                cout<<"Enter Student Name: ";
                cin>>name;
                cout<<"Enter "<<name<<"'s Age: ";
                cin>>age;
                cout<<"Enter password: ";
                cin>>password;
                add_student_detail(id,name,age,password);
                cout<<"Done ✔"<<endl;
            }else if(userOption == 2){
                string name;
                int id;
                cout<<"Enter the Student ID: ";
                cin>>id;
                cout<<"Enter Student Name: ";
                cin>>name;
                delete_student(name,id);
            }else if(userOption ==3){
                string name;
                int id;
                cout<<"Enter Student Name: ";
                cin>>name;
                cout<<"Enter Student ID: ";
                cin>>id;
                search_student(name,id);
            }
            else if(userOption==4){
                add_student_marks();
            }
            else if(userOption==5){
                menu();
            }
            else if(userOption==6){
                cout<<"Exiting..."<<endl;
                Sleep(2000);
                cout<<"Exit Succesfully"<<endl;
                break;
            }else{
                cout<<"Invalid Option!"<<endl;
            }
        }
    }
    //student portal where student can login and check his details 
    void studentPortal(){
        int id,password;
        bool is_running= true;
        cout<<"Welcome to Student Poratl\n"<<endl;
        while(is_running){
            int userOption;
            cout<<"1.Login\n2.Exit"<<endl;
            cout<<"Enter the Option: ";
            cin>>userOption;
            if(userOption==1){
                cout<<"Enter your ID: ";
                cin>>id;
                cout<<"Enter you password(D-O-B): ";
                cin>>password;
                for(auto it: student){
                    if(id==it.first && password==it.second.password){
                        controlsForStudent();
                    }else{
                        cout<<"Contact to Teacher"<<endl;
                        break;
                    }
                }
            }else if(userOption==2){
                Sleep(2000);
                cout<<"Exited"<<endl;
                break;
            }
        }
    }
    void controlsForStudent(){
        int userOption;
        bool is_running = true;
        while(is_running){
            cout<<"1.Profile\n2.Result\n3.Update Password\n4.Menu\n5.Exit"<<endl;
            cout<<"Enter the option: ";
            cin>>userOption;
            if(userOption==1){
                studentProfile();
            } else if(userOption==2){
                get_student_marks();
            } else if(userOption==3){
                int password,id,newPassword;
                cout<<"Enter ID: ";
                cin>>id;
                cout<<"Enter the old password: ";
                cin>>password;
                for(auto &user: student){
                    if(id==user.first && password== user.second.password){
                        cout<<"Enter the New Password: ";
                        cin>>newPassword;
                        user.second.password=newPassword;
                        cout<<"Updated"<<endl;
                    }
                }
            }else if(userOption==4){
                menu();
            }else if(userOption==5){
                Sleep(2000);
                cout<<"Exited"<<endl;
            }else{
                cout<<"Invalid Option"<<endl;
            }
        }
    }
//menu section
    void menu(){
        bool is_running = true;
        int userOption;
        cout<<"1.Teacher Panel\n2.Student Panel\n3.Exits"<<endl;
        cout<<"Enter the Option: ";
        cin>>userOption;
        switch (userOption){
            case 1:
                teacherPortal();
                break;
            case 2:
                studentPortal();
                break;       
            case 3:
                Sleep(2000);
                cout<<"Exited"<<endl;
                break;
            default :
                cout<<"Invalid Option"<<endl;
            }
        }
};
int main(void){
    Student std;
    std.menu();
    
    return 0;
}


