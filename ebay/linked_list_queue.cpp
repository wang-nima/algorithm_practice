#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int val;
    Node *next;
};

//A queue for integer
struct Queue {
    Node *head;
    Node *tail;
    Queue() {
        head = NULL;
        tail = NULL;
    }
    void enQueue(int value) {
        Node *p = (Node*)malloc(sizeof(Node));
        p->val = value;
		p->next = NULL;			//must set next to NULL or in deQueue head->next may not be satisfied even if there is only 1 node in queue
		if (head == NULL) {
			head = p;
			tail = p;
		} else {
        	tail->next = p;
        	tail = p;
		}
    }
    void deQueue() {
		if (head->next != NULL) {
	        Node *p = head->next;
	        free(head);
    	    head = p;
		} else {
			free(head);
			head = NULL;
			tail = NULL;
		}
    }
    int front() {
        return head->val;
    }
    bool empty() {
		return head == NULL;
    }
};

int main() {
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
	q.deQueue();
	q.enQueue(5);
    while (!q.empty()) {
        cout << q.front() << endl;
        q.deQueue();
    }
    return 0;
}
