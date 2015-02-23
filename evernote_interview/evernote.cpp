#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <locale>
#include <algorithm>
using namespace std;

const unsigned int Letter = 26;
const char Delime[] = " \n.,1234567890!@#$%^&*()[]{}-=_+;:'\"<>/?\\~`";
const unsigned int maxWordLength = 100; 

struct freqNode {
	string str;
	unsigned int freq;
};

struct trieNode {
	trieNode *child[Letter];
	trieNode *parent;			//to get the whole string
	unsigned int freq;			//if freq > 0 the trieNode is the end
	char c;
	int indexInHeap;
	trieNode(trieNode *p, char c) {
        for(int i = 0; i < Letter; i++)
            child[i] = NULL;
		parent = p;
        freq = 0;
		this->c = c;
		indexInHeap = -1;
    }
};

trieNode *root = new trieNode(NULL, 0);
int wordCount = 0;
vector<trieNode*> heap;			//min_heap
int k;

bool cmp(trieNode *a, trieNode *b) {
	return a->freq > b->freq;
}

void heapifyDown(int index) {
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int largest = index;
	if(left < k && heap[largest]->freq > heap[left]->freq) {
		largest = left;
	}
	if(right < k && heap[largest]->freq > heap[right]->freq) {
		largest = right;
	}
	if(index != largest) {
		heap[index]->indexInHeap = largest;
		heap[largest]->indexInHeap = index;
		swap(heap[index], heap[largest]);
		heapifyDown(largest);
	}
}

void build(char* s) {
    trieNode* p = root;
	int temp;
    for(int i = 0; s[i] != '\0'; i++) {
		temp = tolower(s[i]) - 'a';
        if(p->child[temp] == NULL)
            p->child[temp] = new trieNode(p, s[i]);
        p = p->child[temp];
    }
	p->freq++;
	if(heap.size() < k) {
		if(p->indexInHeap == -1) {		
			heap.push_back(p);
			p->indexInHeap = -2;		//-2 represent p already in the heap
		}
		if(heap.size() == k) {
			make_heap(heap.begin(), heap.end(), cmp);
			for(int i = 0; i < k; i++) {
				heap[i]->indexInHeap = i;
			}
		}
	} else {
		if(p->indexInHeap >= 0) {		//alreay in the heap
			heapifyDown(p->indexInHeap);		//because it is min heap increase value will go down
		} else {						//not in heap
			if(p->freq > heap[0]->freq) {
				heap[0]->indexInHeap = -1;	//extract from heap
				p->indexInHeap = 0;
				heap[0] = p;
				heapifyDown(0);
			}
		}
	}
}

string nodeToString(trieNode *p) {
	string ret = "";
	while(p != root) {
		ret += p->c;
		p = p->parent;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

vector<freqNode> mostPopularWord() {
	vector<freqNode> ret;
	vector<trieNode*>::iterator it;
	freqNode temp;
	sort(heap.begin(), heap.end(), cmp);
	for(it = heap.begin(); it != heap.end(); it++) {
		temp.str = nodeToString(*it);
		temp.freq = (*it)->freq;
		ret.push_back(temp);
	}
	return ret;
}

void printFreqNode(vector<freqNode> v) {
	vector<freqNode>::iterator it;
	for(it = v.begin(); it != v.end(); it++) {
		cout << (*it).str << " " << (*it).freq << endl;
	}
}

int main()
{
	char str[maxWordLength];
	char *ptr;
	cout << "please input k:" << endl;
	cin >> k;
	FILE * pFile;
 	pFile = fopen ("file.txt","r");
	if(pFile == NULL) {
		cout << "can't open file.txt" << endl;
		return 1;
	}
	while(fscanf(pFile, "%s", str) != EOF) {
		ptr = strtok(str, Delime);
		while(ptr != NULL) {
			build(ptr);
			ptr = strtok(NULL, Delime);
		}
	}
	printFreqNode(mostPopularWord());
	return 0;
}

