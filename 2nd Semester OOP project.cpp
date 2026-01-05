#include<iostream>				
#include<fstream>			//for file handling
#include<windows.h>			//For color handling 
#include<conio.h>			// For getch()
HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);	
using namespace std;


class College{			// Main Parent CLass 
	
	const string name;		// name of College
	char Apassword[20];		// password for admin login 
	char Aname[20];			//Aname for admin login 
	public:
		public:
			
		College():name("College Management System"){}	// 0 Argument constructor
		
		College(string s):name(s){}			// 1 argument constructor
		
		void title(){						// Title InterFace	Starts
			system("cls");
			
   			SetConsoleTextAttribute(H , 14);
		    cout<<"\n\t\t||================================"<<endl;
			cout<<"\t\t||------------------------------||"<<endl;
			cout<<"\t\t||  ";
			SetConsoleTextAttribute(H, 11);
			cout<<name;
			SetConsoleTextAttribute(H, 14);
			cout<<"   ||"<<endl;
			cout<<"\t\t||------------------------------||"<<endl;
			cout<<"\t\t||______________________________||"<<endl;
		
		}										// Title InterFace	Ends
		
		
	
		static void INFORMATION(){
				College c1("College Management System");
				
				c1.title();
				cout<<"Project Name : College Mangement System ."<<endl;
				Sleep(300);
				cout<<"Project Members :"<<endl;
				Sleep(200);
				cout<<"Hamza Ahmed "<<endl;
				Sleep(200);
				cout<<"Asfand Qaiser"<<endl;
				Sleep(200);
				cout<<"Abdul Rehman "<<endl;
				Sleep(200);
				cout<<"\n\n Purpose of this Project :"<<endl;
				Sleep(500);
				cout<<"The purpose of college Management System is to \n Store Data of Students and Teachers"<<endl;
				cout<<"The Project is able to store ";
				cout<<"\n\n\n";
				for(int i=0;i<50;i++){
					Sleep(80);
					cout<<"=";
				}
				cout<<"\n\n\tPress Any Key to go back to menu:";
				getch();
				system("cls");
			}							// Information Section Ends
			
			
			
void loginpassword(){
		int i;
		char c;
		string realp="password",realn="Hamza Ahmed";//Name and password of admin
	
		
		again:
			
		SetConsoleTextAttribute(H , 10);
		
			i=0;
		title();
		cout<<"\n\n\t\t\tAdministration Section \n\n\n\n";
		
		cout<<"\n\n\t\tPlease Enter your name :";
		while((c=getch())!='\r'){
			if(c=='\b'){
				if(i>0){
					cout<<"\b \b";
					i--;
				}
			}
			else{
			cout<<c;
			Aname[i]=c;
			i++;
			}
			Aname[i]='\0';
		}
		i=0;
		
		cout<<"\t \n\tEnter password :";
		while((c=getch())!='\r'){
			if(c=='\b' && i>0){
				i--;
				cout<<"\b \b";
			}
			else if(c!='\b'){
				Apassword[i]=c;
				SetConsoleTextAttribute(H , 12);
				cout<<"*";
				i++;	
			}
		
		}
		Apassword[i]='\0';
		
		if(Apassword!=realp || Aname!=realn){
			cout<<"\n";
			cout<<Aname<<"Password:"<<Apassword;
			cout<<"INvalid name or password"<<endl;
			system("pause");
			system("cls");
			Aname[0]='\0';
			Apassword[0]='\0';
			goto again;
		}
		else{
			cout<<"Access Granted :)"<<endl;
			cout<<"Press any key to continue ...";
			getch();
		Menu();
			
		}
		
}																	//Login Section Ends
	
	void Menu(){						//Menu Section Starts only for Admin
			int c;
			again:
			system("cls");
			title();
			cout<<"\n\n1)See Student Records"<<endl;
			cout<<"2)See Teacher Records"<<endl;
			cout<<"3)See Student Admission Application"<<endl;
			cout<<"4)See Job Applications."<<endl;
			cout<<"5) For logout."<<endl;
			cin>>c;
			if(c==1){
			See("StudentFile");
			system("pause");
			goto again;
			}
			else if(c==2){
			See("TeacherFile");
			system("pause");
			goto again;	
			}
			else if(c==3){
			See("AdmissionStudentFile");
			system("pause");
			system("cls");
			goto again;	
			}
			else if(c==4){
			See("JobTeacherFile");
			system("pause");
			system("cls");
			goto again;	
			}
			else if(c==5){
				system("cls");
				system("pause");		
			}
			
			else{
				cout<<"invalid choice";
				system("pause");
				goto again;
			}
			
		}										//Menu Ends
		
		
	void See(string s){							//For Admin only 1 Arg is file name read Data from all files 
	string filename;
	filename=s+".txt";
	fstream file;
	int i=0;
	string line;
	
	file.open(filename.c_str(),ios::in);
		if(file.is_open()){
			while(!file.eof()){
				getline(file,line);
				cout<<endl<<line;
				i++;
			}
		}
		file.close();		
}

	template<class T>
		static int Initialize(T obj){
			int a;
			a=obj.portal(0);
			
		}
	
	
};

class Student:public College{
	static int S_id;
	 int age,c;
	 char name[20],cnic[13];
	 string course,Address;
	 public:
	 	bool Admission(){					//bool because use in condition 
			againstore:
			cout<<"\n\tAddmission Form"<<endl;
			cout<<"\n \n Note ! Please Donot Enter Space b/w characters \n\n";
			cout<<"Enter your name:";
			cin>>name;
			cout<<"Enter your Age :";
			cin>>age;
			cout<<"Enter your Cnic:";
			cin>>cnic;
			cout<<"Enter Your Address without Spaces :";
			cin>>Address;
			again:
			cout<<"Plz Select course "<<endl;
			cout<<"1)For Fsc\n2)For Ics\n3)For Icom";
			cout<<"\n\n\t Plz Select your choice :";
			cin>>c;
			if(c==1)
			course="Fsc";
			else if(c==2)
			course="Ics";
			else if(c==3)
			course="Icom";
			else{
				cout<<"invalid choice ";
				goto again;
			}
			cout<<"Name :"<<name<<" Age :"<<age<<" cnic :"<<cnic<<"course :"<<course<<endl;
			cout<<"\n\nDo you want to store information 1 for yes 2 for again information and any other number to goto menu :";
			cin>>c;
			if(c==1){
				system("cls");
				cout<<"Information is stored successfully";
				system("pause");
				return 1;
				
			}
			else if(c==2)
				goto againstore;
			else 
			return 0;		
			
		}
		
		void SaveData(){
			ofstream file;
			if(Admission()){
				file.open("AdmissionStudentFile.txt",ios::app);
					if(file.is_open()){
						
					
					if(S_id==0){
						file<<"\t\t\tStudent File"<<endl;
						file<<"======================================================================================"<<endl;
						file<<"S_ID\tName\t\tAge\tCNIC\t\tCOURSE\tAddress\n";
						file<<"======================================================================================"<<endl;
						
						
					}
					++S_id;
					file<<S_id<<"\t"<<name<<"\t"<<age<<"\t"<<cnic<<"\t"<<course<<"\t"<<Address<<endl;
					
				}
				else
					cout<<"File is corrupted"<<endl;
					
				
				file.close();
				
			}
			
		}
		 int portal(bool b){		//1 Argument because 
			
			string scnic,line;// For Authentication 
			int id;
			if(b){
				
			cout<<"Enter your ID";
			cin>>id;
			cout<<"Enter cnic:";
			cin>>scnic;
		}
			fstream file;
			file.open("StudentFile.txt",ios::in);
			if(file.is_open()){
				getline(file,line);
				getline(file,line);
				getline(file,line);
				getline(file,line);
				while(!file.eof()){
			
			file >> S_id >>name>>age>>cnic>>course>>Address;
			if(b){
				
			
			if(id==S_id && scnic==cnic){
				cout<<S_id<<"\t"<<name<<"\t"<<age<<"\t"<<cnic<<"\t"<<course<<"\t"<<Address<<endl;
				goto end;
				}
				}	
			}
		}
		end:
		file.close();
		return S_id;
	}
	
	
		
};
int Student::S_id =College::Initialize(Student())>0 ?  Initialize(Student()):0;

class Teacher:public College{
	 static int T_id;
	 int age,c;
	 char name[20],cnic[13];
	 string Qualification,subject,P_no;
	public:
		bool Job(){
			againstore:
			cout<<"\n\n\tJob APPLICATION Form."<<endl;
			cout<<"Enter your name:";
			cin>>name;
			cout<<"Enter your Age :";
			cin>>age;
			cout<<"Enter your Cnic:";
			cin>>cnic;
			cout<<"Enter Your Phone no :";
			cin>>P_no;
			again:
			cout<<"PLz Select your qualifications ";
			cout<<"1) For Bachelors"<<endl;
			cout<<"2) For Masters ."<<endl;
			cout<<"3) For PHD .";
			cout<<"4) other"<<endl;
			cin>>c;
			if(c==1)
			Qualification="Bachelors";
			else if(c==2)
			Qualification="Masters";
			else if(c==3)
			Qualification="PHD";
			else if(c==4)
			Qualification="other";
			else{
				cout<<"Invalid Selection :)";
				goto again;
			}
			cout<<"Name :"<<name<<" Age :"<<age<<" cnic :"<<cnic<<"Qualification :"<<Qualification<<endl;
			cout<<"Do you want to store information \n1) for yes \n2) for again information and \nany other number to goto menu :";
			cin>>c;
			if(c==1){
				system("cls");
				cout<<"\nYour ID is "<<T_id+1<<" Remember Your ID"<<endl;
				cout<<"\nInformation is stored successfully\n";
				return 1;
				
			}
			else if(c==2)
				goto againstore;
			else 
			return 0;	
		}							//Job Section Ends
		
		void TSaveData(){
			ofstream file;
			if(Job()){
				file.open("JobTeacherFile.txt",ios::app);
					if(file.is_open()){
						
					
					if(T_id==0){
						file<<"\t\t\tTeacherFile"<<endl;
						file<<"======================================================================================"<<endl;
						file<<"T_ID\tName\t\tAge\tCNIC\t\tQualification Phone Number\n";
						file<<"======================================================================================"<<endl;
						
						
					}
					++T_id;
					file<<T_id<<"\t"<<name<<"\t"<<age<<"\t"<<cnic<<"\t"<<Qualification<<"\t"<<P_no<<endl;
					
				}
				else
					cout<<"Teacher File is corrupted"<<endl;
					
				
				file.close();
				
			}
		}
		
		int portal(bool b){
		 	
			string Tcnic,line;
			int id;
			if(b){
				
			cout<<"Enter your ID";
			cin>>id;
			cout<<"Enter cnic:";
			cin>>Tcnic;
		}
			fstream file;
			file.open("TeacherFile.txt",ios::in);
			if(file.is_open()){
				getline(file,line);
				getline(file,line);
				getline(file,line);
				getline(file,line);
				while(!file.eof()){
			
			file >> T_id >>name>>age>>cnic>>Qualification>>P_no;
			if(b){
				
			
			if(id==T_id && Tcnic==cnic){
				cout<<T_id<<"\t"<<name<<"\t"<<age<<"\t"<<cnic<<"\t"<<Qualification<<"\t"<<P_no<<endl;
				goto end;
			}
			}	
			}
		}
		end:
		file.close();
		return T_id;
	}
		
		
};
int Teacher::T_id =College::Initialize(Teacher())>0 ?  Initialize(Teacher()):0;

int main() {
    College c;
    int choice;
    while (true) {
        try {
        	c.title();
        	cout<<"\n\n\t\t===============Menu===============\n\n"<<endl;
            cout << "\n\t\t\t1) Login\n";
            cout << "\t\t\t2) Information\n";
            cout << "\t\t\t3) Student Menu\n";
            cout << "\t\t\t4) Teacher Menu\n";
            cout << "\t\t\t5) Exit\n";
            cout << "\n\t\tEnter your choice: ";
            cin >> choice;
            system("cls");

            switch (choice) {
                case 1:
                    c.loginpassword();
                    break;
                case 2:
                    c.INFORMATION();
                    break;
                case 3: {
                    Student s;
                    int studentChoice;

                    cout << "\n1) Admission\n";
                    cout << "2) Student Portal\n";
                    cout << "3) Back to Main Menu\n";
                    cout << "Enter your choice: ";
                    cin >> studentChoice;

                    switch (studentChoice) {
                        case 1:
                            s.SaveData();
                            break;
                        case 2:
                            s.portal(true);
                            break;
                        case 3:
                            continue;
                        default:
                            throw "Invalid choice. Please try again.";
                    }
                    break;
                }
                case 4: {
                    Teacher t;
                    int teacherChoice;
					cout<<"\t\t\n=============Menu==============="<<endl;
					cout << "\t\t\n1) Job Application\n";
                    cout << "\t\t2) Teacher Portal\n";
                    cout << "\t\t3) Back to Main Menu\n";
                    cout << "\tEnter your choice: ";
                    cin >> teacherChoice;

                    switch (teacherChoice) {
                        case 1:
                            t.TSaveData();
                            break;
                        case 2:
                            t.portal(true);
                            break;
                        case 3:
                            continue;
                        default:
                            throw "Invalid choice. Please try again.";
                    }
                    break;
                }
                case 5:
                    return 0;
                default:
                    throw string ("Invalid choice. Please try again.");
            }
        } catch (string errorMessage) {
            cout << errorMessage << "\n";
            getch();
            
        } catch (...) {
            cout << "An error occurred. Please try again.\n";
            getch();
        }
    }

    return 0;
}

