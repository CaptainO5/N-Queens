#include<iostream>
#include<cstdlib>
using namespace std;

struct position {
	int row;
	int col;
};

struct node {
	struct position data;
	struct node * next;
};

class stack {
	private:
		struct node * top;
		bool isEmpty();
	public: 
		int pop(struct position *);
		int push(struct position);
};
