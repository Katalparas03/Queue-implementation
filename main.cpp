#include <iostream>
#include <list>
using namespace std;
class CircularQueue {
 private:
 int maxSize,f,r;
 list<int> queue;
 public:
 CircularQueue(int size) {
 maxSize = size;
 f=-1;
 r=-1;
 }
 void enqueue(int value) {
 if((f==0 && r==maxSize-1) || (f==r+1))
 {
 cout<<"Circular Queue Overflow\n";
 return;
 }
 if(f==-1)
 {
 queue.push_back(value);
 f=0;
 r=0;
 }
 else
 {
 if(r==maxSize-1)
 {
 queue.push_front(value);
 r=0;
 }
 else
 {
 queue.push_back(value);
 r=r+1;
 }
 }
 }
 int dequeue() {
 if(f==-1)
 {
 cout<<"Circular Queue Underflow\n";
 return -1;
 }
 if(f==r)
 {
 f=-1;
 r=-1;
 int val = queue.front();
 queue.pop_front();
 return val;
 }
 else
 {
 if(f==maxSize-1)
 {
 f=0;
 int val = queue.front();
 queue.pop_front();
 return val;
 }
 else
 {
 f=f+1;
 int val = queue.front();
 queue.pop_front();
 return val;
 }
 }
 }
 int front() {
 if (queue.empty()) {
 cout << "Queue is empty" << endl;
 return -1;
 }
 return queue.front();
 }
 int rear() {
 if (queue.empty()) {
 cout << "Queue is empty" << endl;
 return -1;
 }
 return queue.back();
 }
 int size() {
 return queue.size();
 }
 bool isEmpty() {
 return queue.empty();
 }
};
int main() {
 CircularQueue q(10);
 int n=q.dequeue();
 cout << "Front: " << q.front() << endl;
 cout << "Rear: " << q.rear() << endl;
 while (!q.isEmpty()){
    cout << q.dequeue() << " ";
 }
 return 0;
}
