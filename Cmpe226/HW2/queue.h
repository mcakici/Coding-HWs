#define QUEUE_H
#include <iostream>
#include <cassert>

template <typename T>
class Queue{
	private:
		int maxsize;
		int count;
		int front,rear;
		T *data;

	public:
		Queue(int sz=100){
			maxsize = sz;
			data = new T[maxsize];
			front = 0;
			rear = maxsize-1;
			count = 0;
		}
		~Queue(){
			delete[] data;
		}
		bool isEmpty(){
			return count==0;
		}
		bool isFull(){
			return count==maxsize;
		}
		T getFront(){
			assert(!isEmpty());
			return data[front];
		}
		T getRear(){
			assert(!isEmpty());
			return data[rear];
		}
		void push(const T &item){
			if(!isFull()){
				rear = (rear+1) % maxsize;
				data[rear] = item;
				count++;
			}else{
				std::cout<<"Queue is full";
			}
		}
		T pop(){
			assert(!isEmpty());
			T tmp = data[front];
			front = (front+1)%maxsize;
			count--;
			return tmp;
		}
		int size(){
			return count;
		}
		int capacity(){
			return maxsize;
		}
		void destroyQueue(){
			front=count=0;
			rear=maxsize-1;
		}
	
};
