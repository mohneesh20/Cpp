#include<vector>
class PriorityQueue{
    vector<int> pq;
    public:
    bool isEmpty(){
        return pq.size()==0;
    }
    int getSize(){
        return pq.size();
    }
    int getMin(){
        if(pq.size()!=0){
        return pq[0];
        }
    }
    void insert(int data){
        if(pq.size()==0){
            pq.push_back(data);
        }
        else{
            int childIndex=pq.size()-1;
            while(childIndex>0){
            int parentIndex=(childIndex-1)/2;
            if(pq[childIndex]<pq[parentIndex]){
                int temp=pq[parentIndex];
                pq[parentIndex]=pq[childIndex];
                pq[childIndex]=temp;
            }
            else{
                break;
            }
            childIndex=parentIndex;
            }
        }
    }
    void removeMin(){
        if(isEmpty()){
            return;
        }
        else{
            int ans=pq[0];
            pq[0]=pq[pq.size()-1];
            pq.pop_back();
            int rootIndex=0;
            int leftChildIndex=2*rootIndex+1;
            int rightChildIndex=2*rootIndex+2;
            while(leftChildIndex<pq.size()){
                int minIndex=rootIndex;
                if(pq[minIndex]>pq[leftChildIndex]){
                    minIndex=leftChildIndex;
                }
                if(rightChildIndex<pq.size()&&pq[minIndex]>pq[rightChildIndex]){
                    minIndex=rightChildIndex;
                }
                int tmp=pq[minIndex];
                pq[minIndex]=pq[rootIndex];
                pq[rootIndex]=tmp;
                rootIndex=minIndex;
                int leftChildIndex=2*rootIndex+1;
                int rightChildIndex=2*rootIndex+2;
            }
        }
    }
};