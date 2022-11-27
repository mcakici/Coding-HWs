//QUIZ 2
#include<iostream>
using namespace std;

class Time{
	public:
		int hour,minutes;
		
		Time(int h,int m){
			hour = h;
			minutes = m;
		}
		~Time(){
			cout<<"At "<<hour<<":"<<minutes<<", time was deleted!"<<endl;
		}
};

class DateTime{
	private:
		int day;
		Time time;
		
	public:		
		DateTime(int d, Time t):time(t){
			day=d;
			time=t;
		}
		
		DateTime operator +(int val){
			int daynew = day, hournew = time.hour, minnew = time.minutes;
			Time newTime(time.hour,time.minutes);
			int prevmin = minnew+val;
			newTime.minutes = prevmin%60;
			
			int prevhour = hournew+prevmin/60;
			newTime.hour = prevhour%24;
			
			daynew = daynew+prevhour/24;
			
			return DateTime(daynew,newTime);
			
		}
		
		friend ostream & operator << (ostream &out, DateTime const &d){
			out<<d.day<<". days "<<d.time.hour<<":"<<d.time.minutes;
			return out;			
		}
		
		~DateTime(){
			//cout
		}
};

int main(){
	
	Time t(23,49);
	DateTime d(6,t);
	DateTime m = d+120;
	cout<<m<<endl;
	
	
	return 0;
}
