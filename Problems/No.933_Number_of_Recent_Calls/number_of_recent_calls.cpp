class RecentCounter {

private:
    std::queue<int> recent_calls;

public:
    int ping(int t) {
        
        recent_calls.push(t);
        while (recent_calls.front() < t-3000) recent_calls.pop();
        return recent_calls.size();

    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
