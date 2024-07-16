#include<iostream>
#include"PriorityQueue.h"
using namespace std;
int main(){
    PriorityQueue pq;
    pq.insert(100);
    pq.insert(10);
    pq.insert(15);
    pq.insert(4);
    pq.insert(17);
    pq.insert(21);
    pq.insert(67);
    while(pq.getSize()!=0){
        cout<<pq.getMin()<<endl;
        pq.removeMin();
    }
}