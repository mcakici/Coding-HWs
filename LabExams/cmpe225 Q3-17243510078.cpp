#include<iostream>
using namespace std;

class Animal{
	protected:
		string family;
	public:
		Animal(string s):family(s){
		}
		string getFamily(){
			return family;
		}
		virtual float estimatedLifeExpectancy(){
			return 0;
		}
		virtual ~Animal(){
			cout<<"Animal that in "<<family<<" died!"<<endl;
		}
};

class Goats:public Animal{
	private:
		float weight, length;
	public:
		Goats(string s,float we,float le):Animal(s),weight(we),length(le){			
		}
		float estimatedLifeExpectancy(){
			return weight/length;
		}
		~Goats(){
			cout<<"The goat which "<<weight<<" kg and "<<length<<" meters is dead!"<<endl;
		}
};

class Bugs:public Animal{
	private:
		float colonyCount,colonyMass;
		
	public:
		Bugs(string s,float co,float ma):Animal(s),colonyCount(co),colonyMass(ma){	
		}
		float estimatedLifeExpectancy(){
			float ratio = colonyCount/colonyMass;
			if(ratio <= 1) return colonyCount/10;
			else return (colonyCount/10)/ratio;
		}
		~Bugs(){
			cout<<"The bug colony which total mass "<<colonyMass<<" gram and total count is "<<colonyCount<<" is dead!"<<endl;;
		}
};

int main(){
	Animal *ani[2];
	ani[0] = new Goats("Angora",42,1.2);
	ani[1] = new Bugs("Beatle",300,450);
	
	for(int i=0;i<2;i++)
	cout<<"Estimated life time of a/an "<<ani[i]->getFamily()<<" is "<<ani[i]->estimatedLifeExpectancy()<<" year"<<endl;
	
	for(int i=0;i<2;i++)
	delete ani[i];
	
	return -1;
}
