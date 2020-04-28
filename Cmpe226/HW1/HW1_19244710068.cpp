/* CMPE-226 _ HW-1 _ MÇ 19244710068 */
#include "Process.hpp"
//You can use one of LinkedList. "LinkedList.hpp" one in moodle or my own "myLinkedList.hpp"
#include "LinkedList.hpp"
//#include "myLinkedList.hpp"
using namespace std;

int main(){
	LinkedList<Process> proc;
	
	/* 
	//MANUEL PREDEFINED VALUES
	
	Process p1("Process 0", 54);
	cout<<"Inserting ->\n"<<p1<<endl;
	proc.prioritized_insert(p1);
	
	Process p2("Process 1", 24);
	cout<<"Inserting ->\n"<<p2<<endl;
	proc.prioritized_insert(p2);
	
	Process p3("Process 2", 45);
	cout<<"Inserting ->\n"<<p3<<endl;
	proc.prioritized_insert(p3);
	
	Process p4("Process 3", 63);
	cout<<"Inserting ->\n"<<p4<<endl;
	proc.prioritized_insert(p4);
	
	Process p5("Process 4", 14);
	cout<<"Inserting ->\n"<<p5<<endl;
	proc.prioritized_insert(p5);
	*/
	
	/*
	Process p1 = Process(NULL, 54);
	cout<<"Inserting ->\n"<<p1<<endl;
	proc.prioritized_insert(p1);
	
	Process p2 = Process(NULL, 24);
	cout<<"Inserting ->\n"<<p2<<endl;
	proc.prioritized_insert(p2);
	*/
	
	int predefined_processes[] = {54,24,45,63,14};
	for(int x=0;x<5;x++){
		Process p(NULL, predefined_processes[x]);
		cout<<"Inserting ->\n"<<p<<endl;
		proc.prioritized_insert(p);
	}

	cout<<"------------------------------------------------------------------------\n";
	cout<<"Currently there are "<< proc.length() << " processes in the linked list.\n";
	cout<<"------------------------------------------------------------------------\n";
	cout<<"Processes in the linked list that are sorted by their priorities are as follows:\n\n";
	cout<<proc;
	
	cout<<"\nIf you can see this text, program worked well and there is no syntax error. PogChamp!"<<endl;

	return 0;
}
