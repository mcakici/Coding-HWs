/* CMPE-226 _ HW-1 _ MÇ 19244710068 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <cassert>
using namespace std;

template <typename T>
struct Node{
	T data;
	Node<T> *next;
};

template <typename T>
class LinkedList{
	protected:
		Node<T> *head,*last;
		int count;
	public:
		LinkedList();
		~LinkedList();
		bool isEmpty();
		int length();
		T back();
		T front();
		void destroyList();
		Node<T>* search(T&);
		void insertFirst(T&);
		void insertLast(T&);
		void deleteNode(T&);
		void prioritized_insert(T&); //IMPLEMENTATION

		friend ostream & operator << (ostream &os, const LinkedList<T> &list){
			Node<T> *p = list.head;
			while(p!=NULL){
				os<<p->data;
				p=p->next;
			}
			return os;
		}
		
};

//IMPLEMENTATION
template <typename T> 
void LinkedList<T>::prioritized_insert(T& new_item){
	//create a new Node
	Node<T> *newProcess = new Node<T>;
	newProcess->data=new_item;
	newProcess->next=NULL;
	
	if(head==NULL){ //if linkedlist was empty
		//insertFirst(new_item); //OR
		last = head = newProcess;
		
	}else{ //if not empty
		Node<T> *p = head;
		Node<T> *pPrev = NULL;
		bool done = false;
		
		while(!done && p != NULL){
			//check our data is greater than p->data
			if(p->data <= new_item){
				
				if(head == p){
					//insertFirst(new_item); //OR
					newProcess->next = p;
					p = head = newProcess;					
				}else{
					newProcess->next=p;
					//if there is a previous node set that next node to our new node
					if(pPrev != NULL) pPrev->next = newProcess;	

				}
				done = true;
			
			}else{
				pPrev = p;
				p=p->next;
			}
		}
		if(!done){
			//insertLast(new_item); //OR
			last->next = newProcess;
			last = newProcess;
		}
	}
	count++;
}


template <typename T>
LinkedList<T>::LinkedList(){
	head=last=NULL;
	count=0;
}

template <typename T>
LinkedList<T>::~LinkedList(){
	destroyList();
}

template <typename T>
bool LinkedList<T>::isEmpty(){
	return head == NULL;
}

template <typename T>
int LinkedList<T>::length(){
	return count;
}

template <typename T>
Node<T>* LinkedList<T>::search(T &item){
	bool found=false;
	Node<T> *p=head;
	while(p!=NULL && !found){
		if(p->data == item){
			found=true;
		}else{
			p = p->next;
		}
	}
	return p;
}

template <typename T>
void LinkedList<T>::insertFirst(T &item){
	Node<T> *p=new Node<T>;
	p->data=item;
	p->next=head;
	head=p;
	count++;
	if(last==NULL) last=p;
}

template <typename T>
void LinkedList<T>::insertLast(T &item){
	Node<T> *p = new Node<T>;
	p->data=item;
	p->next=NULL;
	
	if(head==NULL){
		last = head = p;
	}else{
		last->next=p;
		last=p;
	}
	count++;
}

template <typename T>
void LinkedList<T>::destroyList(){
	Node <T> *p;
	while(head != NULL){
		p=head;
		head=head->next;
		delete p;
	}
	last=NULL;
	count=0;
}

template <typename T>
T LinkedList<T>::front(){
	assert(head!=NULL && "Hata-front()");
	return head->data;
}

template <typename T>
T LinkedList<T>::back(){
	assert(last!=NULL && "Hata-back()");
	return last->data;
}

template <typename T>
void LinkedList<T>::deleteNode(T &item){
	Node<T> *p,*q;
	bool found = false;
	if(head == NULL){
		cerr<<"List is empty";
	}else{
		if(head->data==item){
			p=head;
			head=head->next;
			delete p;
			count--;
			if(head == NULL) last = NULL;
		}else{
			p=head;
			q=head->next;
			while(q!=NULL && !found){
				if(q->data==item){
					found=true;
				}else{
					p=q;
					q=q->next;
				}
			}
			if(found){
				p->next=q->next;
				count--;
				if(q==last) last=p;
				delete q;
			}
		}
	}
}

#endif
