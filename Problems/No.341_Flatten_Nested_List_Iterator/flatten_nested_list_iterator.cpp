/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {

private:
    std::queue<int> flatten_list;

public:
    NestedIterator(vector<NestedInteger> &nestedList) {initialize_Flist(nestedList);}

    void initialize_Flist(std::vector<NestedInteger> &List) {

        for (auto &element: List) {

            if (element.isInteger()) flatten_list.push(element.getInteger());
            else initialize_Flist(element.getList());

        }

    }
    
    int next() {
        
        int next_value = flatten_list.front();
        flatten_list.pop();

        return next_value;

    }
    
    bool hasNext() {return !flatten_list.empty();}
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
