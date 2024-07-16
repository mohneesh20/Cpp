#include <bits/stdc++.h>
using namespace std;
//["SnapshotArray","set","snap","set","get"]
//[[3],[0,5],[],[0,6],[0,0]]
//[null,null,0,null,5]
class time_stamp{
    public:
    int id=0;
    int val=0;
    time_stamp* next=nullptr;
    time_stamp(int ID,int VALUE):id(ID),val(VALUE){}
    time_stamp():id(0),val(0){}
};
class SnapshotArray {
    vector<time_stamp*> container;
    // int len=0;
public:
    SnapshotArray(int length) {
        container.resize(length);
        for(int i=0;i<length;i++){
            time_stamp* node=new time_stamp();
            container[i]=node;
        }
    }    
    void set(int index, int val) {
        container[index]->val=val;
    }    
    int snap() {
        for(int i=0;i<container.size();i++){
            time_stamp* prev_node=container[i];
            container[i]=new time_stamp(prev_node->id+1,prev_node->val);
            container[i]->next=prev_node;
        }
        return container[0]->id-1;
    }    
    int get(int index, int snap_id) {
          time_stamp* itr=container[index];
          while(itr!=nullptr){
            if(itr->id==snap_id){
                return itr->val;
            }
            itr=itr->next;
          }
          return -1;
    }
};
int main()
{
    SnapshotArray* obj=new SnapshotArray(5);    
    obj->set(2,1);    
    obj->snap();
    obj->set(3,2);    
    obj->snap();
    cout<<obj->get(3,1);
}