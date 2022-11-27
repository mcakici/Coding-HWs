#include<iostream>
using namespace std;

class Room{
	protected:
		float grossArea;
		float innerArea;
	
	public:
		Room(){
		}
		virtual void writeInfo(){
			cout<<"Room's gross area = "<<grossArea<<",  inner area = "<<innerArea<<endl;
		}
		virtual ~Room(){
			cout<<"Room Destroyed!"<<endl;
		}
};

class CircleShapeRoom:public Room{
	private:
		float innerRadius;
		float pi;
		
	public:
		CircleShapeRoom(float a):innerRadius(a),pi(3.14f){
			Room::grossArea = outerArea();
			Room::innerArea = innerArea();
		}
		float innerArea(){
			return pi*innerRadius*innerRadius;
		}
		float outerArea(){
			return (innerRadius+10)*(innerRadius+10);
		}
		void writeInfo(){
			cout<<"Circular Room's gross area = "<<Room::grossArea<<",  inner area = "<<Room::innerArea<<endl;
		}
		~CircleShapeRoom(){
			cout<<"Circular Room Destroyed!"<<endl;
		}
};

class RectangularShapeRoom:public Room{
	private:
		float height,width;
	
	public:
		
		RectangularShapeRoom(float w,float h):height(h),width(w){
			Room::grossArea = outerArea();
			Room::innerArea = innerArea();
		}
		float innerArea(){
			return width*height;
		}
		float outerArea(){
			return (width+10)*(height+10);
		}
		void writeInfo(){	
			cout<<"Rectangular Room's gross area = "<<Room::grossArea<<",  inner area = "<<Room::innerArea<<endl;
		}
		~RectangularShapeRoom(){
			cout<<"Rectangular Room Destroyed!"<<endl;
		}
};




int main(){
	CircleShapeRoom cs(5);
	cs.writeInfo();
	
	RectangularShapeRoom rs(5,4);
	rs.writeInfo();
	
	
	return 1;
}
