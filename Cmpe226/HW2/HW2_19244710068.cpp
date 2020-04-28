/* CMPE-226 _ HW-2 _ MÇ 19244710068 */
#include <fstream>
#include "stack.h"
#include "queue.h"
#include <sstream> 
using namespace std;

class Expression{
	public:
		string exp;
};

int getpriority(char op){
	return (op == '*' || op == '/' ? 2 : 1);
}

float evalprefix(const string str){
	float tmp,val1,val2;
	Stack<char> operators;
	Stack<float> operands;
	string digits = "";

	for(int i=str.length(); i>=0; i--){ //reverse
		char ch = str[i];	

		if(isdigit(ch) && ch >= '0' && ch <= '9'){
			//merge digits into string to get full number
			digits = ch + digits;
		}else if(digits.length() > 0 && (ch == ' ')){
			//Type casting using sstream library (string to float)
			stringstream num(digits); 
			num >> tmp; 

			operands.push(tmp);
			digits = "";
			
		}else if(ch=='+' || ch=='/' || ch =='-' || ch=='*'){
			val1 = operands.pop();
			val2 = operands.pop();
			switch(ch){
				case '+': tmp = val1+val2; break;
				case '-': tmp = val1-val2; break;
				case '*': tmp = val1*val2; break;
				case '/': tmp = val1/val2; break;
			}
			//cout<<"First val:"<<val1<<" Second val:"<<val2<<" Opr:"<<ch<<" Total:"<<tmp<<endl;
			operands.push(tmp);
		}
	}
	return operands.top();
}

string infix_to_prefix(const string infix_str){
	Stack<char> operators;
	Stack<char> out;
	string output = "";

	for(int i=infix_str.length(); i>=0; i--){ //reverse
		char ch = infix_str[i]; //get a char
		
		if(!isdigit(ch) && ch != ' '){
			out.push(' ');
		}else if(isdigit(ch)){			
			out.push(ch);
		}
			
		if(ch=='+' || ch=='/' || ch =='-' || ch=='*'){
			int isDone = 0;
			while(!isDone){
				if(operators.isEmpty() || getpriority(ch) >= getpriority(operators.top())){
					operators.push(ch);	
					isDone = 1;
				}else{
					out.push(operators.pop());
					out.push(' ');
				}
			}
		}
	}
	//if there is any operator left then unload them
	while(!operators.isEmpty()){
		out.push(' ');
		out.push(operators.pop());
	}
	
	//unload out stack
	while(!out.isEmpty()){
		output += out.pop();
	}
	return output;
}

int main(){
	//queue list
	Queue<Expression> que(100);
	string exp;
	Expression tmp;
	
	ifstream inp("questions.txt");
	if(inp == NULL){
		printf("'question.txt' file does not exist..\n\n");
		exit(0);
	}
	while(!inp.eof()){
		getline(inp,tmp.exp);
		
		if(tmp.exp.length() > 0) 
			que.push(tmp);
	}


	while(!que.isEmpty()){ //102464
		tmp = que.pop();
		exp = tmp.exp;
		cout<<"Infix Form: "<<exp<<endl;
		
		string prefix = infix_to_prefix(exp);
		cout<<"Prefix Form: "<<prefix<<endl;
		cout<<"Result: "<<(int)evalprefix(prefix)<<endl;
		
		cout<<"============================"<<endl;
	}
	
	cout<<"The program is ended."<<endl;
	
	return 0;
}
