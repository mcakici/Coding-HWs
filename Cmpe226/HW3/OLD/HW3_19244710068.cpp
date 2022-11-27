/* CMPE-226 _ HW-3 _ MÇ 19244710068 */
#include<fstream>
#include "binarysearchtree.h"
#include <sstream> 
using namespace std;

class Student{
	public:
		int id;
		string firstname;
		string surname;
		float grade;
		Student():id(0),grade(0){}
};

int main() {
    BinarySearchTree<Student> tree;
    
    ifstream inp("hw3_text.csv");
	if(inp == NULL){
		printf("'hw3_text.csv' file does not exist..\n\n");
		exit(0);
	}
	while(!inp.eof()){ //will turn for all lines
		string str,tmp;
		int order=0;
		getline(inp,str); //get one line and put into str variable.
		Student p; //temporary student object
		
		//turn for each char in this line
		for(int i=0;i<str.length()+1;i++){
			//if this char is ','(char) or '\0' (endline) use type cast and set value into object variable.
			//order variable will keep which one we use next.
			if(str[i] == ',' || str[i] == '\0'){
				//cout<<tmp<<endl;
				if(order == 0){
					int id;	
					stringstream num(tmp); 
					num >> id;  //type casting for id
					p.id = id; 
				}else if(order == 1){
					p.firstname = tmp; 
				}else if(order == 2){
					p.surname = tmp;
				}else if(order == 3){
					float grade;
					stringstream numg(tmp); 
					numg >> grade;  //type casting for grade
					p.grade = grade;
				}
				order++;
				tmp = "";
			}else{
				//if there is no ',' or '\0' character then just add char to tmp's end.
				tmp += str[i];
			}
		}
		//insert into tree if grade and id variables are exist.
		if(p.grade != 0 && p.id != 0){
			tree.insert(p);
		}
		//cout<<"=========="<<endl;
	}
	
	//output - binary search tree postorder traversal
	tree.postorder();
	//You can try inorder and preorder too.
	//tree.inorder(); 
	//tree.preorder();

    return 0; 
}
