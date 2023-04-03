class SORTracker {
// reference:
// https://leetcode.com/problems/sequentially-ordinal-rank-tracker/solutions/1958764/c-priority-queue-min-and-max-heap/

private:
    // custom comparison operators
    struct min_comp {
        bool operator()(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {

            if (a.first != b.first) return (a.first > b.first);
            else return (a.second < b.second);

        }
    };
    struct MAX_comp {
        bool operator()(const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {

            if (a.first != b.first) return (a.first < b.first);
            else return (a.second > b.second);
            
        }
    };

    // parameters
    std::priority_queue<
        std::pair<int, std::string>, 
        std::vector<std::pair<int, std::string>>, 
        min_comp> min_Heap;
    std::priority_queue<
        std::pair<int, std::string>, 
        std::vector<std::pair<int, std::string>>,
        MAX_comp> MAX_Heap;

public:
    void add(string name, int score) {
        
        min_Heap.push({score, name});
        MAX_Heap.push(min_Heap.top());
        min_Heap.pop();

    }
    
    string get() {
        
        auto [score, name] = MAX_Heap.top();
        MAX_Heap.pop();
        min_Heap.push({score, name});
        return name;

    }
};

/**
 * Your SORTracker object will be instantiated and called as such:
 * SORTracker* obj = new SORTracker();
 * obj->add(name,score);
 * string param_2 = obj->get();
 */
