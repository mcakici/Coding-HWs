#define STACK_H
#include <iostream>
#include <cassert>

template<typename T>
struct Node{
	T data;
	Node<T> *next;
};

template<typename T>
class Stack{
	private:
		Node<T> *pTop;

	public:
		Stack(){
			pTop = NULL;
		}
		~Stack(){
			destroy();
		}
		bool isEmpty(){
			return (pTop==NULL);
		}
		T top(){
			assert(!isEmpty());
			return pTop->data;
		}
		T pop(){
			assert(!isEmpty());
			Node<T> *p;
			T item;
			p=pTop;
			pTop = pTop->next;
			item=p->data;
			delete p;
			return item;
		}
		void push(const T &item){
			Node<T> *newNode = new Node<T>;
			newNode->data = item;
			newNode->next = pTop;
			pTop=newNode;
		}
		void destroy(){ 
			Node<T> *tmp;
			while(pTop != NULL){
				tmp=pTop;
				pTop=pTop->next;
				delete tmp;
			}
		}
	
};
