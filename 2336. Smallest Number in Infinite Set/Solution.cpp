class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    unordered_set<int> inQ;
    int toRemove = 1;

    SmallestInfiniteSet() {

    }

    int popSmallest() {
        if (q.empty()){
            return toRemove++;
        }
        int ret = q.top();
        q.pop();
        inQ.erase(ret);
        return ret;
    }

    void addBack(const int num) {
        if (num >= toRemove || inQ.count(num)) return;
        inQ.insert(num);
        q.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
