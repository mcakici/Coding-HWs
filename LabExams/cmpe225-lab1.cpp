#include<iostream>
using namespace std;

class Person{
	private:
		string name;
		string surname;
		int age;
		int starvationRate;
		
	public:
		Person(string n,string s,int a){
			name = n; surname = s; age = a;
		}
		string getName(){
			return name;
		}
		string getSurname(){
			return surname;
		}
		string getFullname(){
			return name+" "+surname;
		}
		int getAge(){
			return age;
		}
		void setAge(int a){
			age = a;
		}
		int getStarvationRate(){
			return starvationRate;
		}
		void setStarvationRate(int a){
			starvationRate = a;
		}
		bool checkStarvation(){
			return (starvationRate < 20 ? true : false);
		}
		~Person(){
			cout<<name<<" "<<surname<<" is left the hospital";
		}
};

class Patient:public Person{
	private:
		string illnessName;
	public:
		Patient(string n,string s,int a,string il):Person(n,s,a),illnessName(il){
		}
		
		void setIllnessName(string s){
			illnessName = s;
		}
		bool checkStarvation(){
			return (starvationRate < 20 ? true : false);
		}
		void takeACare(){
			
		}
		~Patient(){
			cout<<name<<" "<<surname<<" is left the hospital.";
		}
};

class Employee:public Person{
	private:
		int employeeID;
		
	public:
		Patient(string a, string a, int a, int b){
			
		}
		
		int getEmployeeID(){
			return employeeID;
		}
		bool checkStarvation(){
			
		}
		void checkPatient(Patient p){
			p.setStarvationRate( 	p.getStarvationRate()-5 );
			cout<<"The patient named "<<p.getName()<<" "<<p.getSurname()<<" is checking.";
			if(p.checkStarvation()){
				cout<<p.getName()<<" "<<p.getSurname()<<" is starving!";
			}
		}
		~Employee(){
			cout<<name<<" "<<surname<<" is quit the job!";
		}
};

class Nurse:public Employee{
	public:
		Nurse(string,string,int,int){
			
		}
		void checkPatient(Patient p){
			p.setStarvationRate( 	p.getStarvationRate()-10 );
			cout<<"The patient named "<<p.getName()<<" "<<p.getSurname()<<" is checking.";
			p.takeACare();
			cout<<p.getName()<<" "<<p.getSurname()<<" took care of the patient.";
			if(p.checkStarvation()){
				cout<<p.getName()<<" "<<p.getSurname()<<" is starving!";
			}
		}
		~Nurse(){
			cout<<name<<" "<<surname<<" is quit beign Nurse!";
		}
};

class Doctor:public Employee{
	public:
		Doctor(string,string,int,int){
			
		}
		void checkPatient(Patient p){
			p.setStarvationRate( 	p.getStarvationRate()-5 );
			cout<<"The patient named "<<p.getName()<<" "<<p.getSurname()<<" is checking.";
			p.takeACare();
			cout<<p.getName()<<" "<<p.getSurname()<<" gives medicine to patient.";
			if(p.checkStarvation()){
				cout<<p.getName()<<" "<<p.getSurname()<<" is starving!";
			}
		}
		~Doctor(){
			cout<<name<<" "<<surname<<" is quit beign Doctor!";
		}
};


int main(){
	Doctor d("Jodie","Whittaker",36,160717);
	Nurse n("Claire","Temple",39,951979);
	Patient p("Robert","Broke",32,"something");
	
	
	return 1;
}
