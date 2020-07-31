class SnapshotArray {
public:
    vector<pair<int , int> > v[50005];
    int id = 0;
    SnapshotArray(int length) {
        for(int i=0;i<=length;i++){
            v[i].push_back({0 , 0});
        }
    }
    
    void set(int index, int val) {
        v[index].push_back({id, val});
    }
    
    int snap() {
        id++;
        return id-1;
    }
    int get(int index, int snap_id) {
        auto it = --lower_bound(v[index].begin(), v[index].end() , make_pair(snap_id+1 , -1));
        pair<int , int> temp = *it;
        return temp.second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
