#include<iostream>
using namespace std;
class Matter{
	private:
		float mass;
		
	public:
		Matter(){}
		Matter(float m):mass(m){}
		float getMass(){
			return mass;
		}
		virtual float CalculateDensity(){
			return 0;
		}
};

class Solid:public Matter{
	private:
		float volume;
	public:
		Solid(){
			volume = 0;
		}
		Solid(float m,float vol):Matter(m){
			volume = vol;
		}
		float CalculateDensity(){
			return getMass()/volume;
		}
};

class Gas:public Matter{
	private:
		int molesOfGas;
		float temperature;
		float pressure;
		static const float gasConstant = 0.0821;
		
		float MolecularMass(){
			return getMass()/molesOfGas;
		}
		
	public:		
		Gas(float mas,int mol,float atm,float temp):Matter(mas){
			molesOfGas = mol;
			pressure = atm;
			temperature = temp;
		}
		float CalculateDensity(){
			return ((getMass()/molesOfGas)*pressure) / (gasConstant*temperature);
		}
};

int main(){
	Solid s(64,32);
	cout<<"Density of solid="<<s.CalculateDensity()<<endl;
	Gas g(64,2,5,300);
	cout<<"Density of gas="<<g.CalculateDensity()<<endl;	
	return 1;
}
