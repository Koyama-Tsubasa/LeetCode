class Event_Node {

public:
    int start_date, end_date;
    Event_Node *before, *after;
    Event_Node(int start, int end) {

        start_date = start;
        end_date = end;
        before = nullptr;
        after = nullptr;

    }

};

class MyCalendar {

private:
    Event_Node *root;

    bool check_valid(Event_Node *node, int start, int end) {

        if (node == nullptr) return true;
        else if (start >= node->end_date) {

            if (node->after == nullptr) return true;
            else return check_valid(node->after, start, end);

        }
        else if (end <= node->start_date) {

            if (node->before == nullptr) return true;
            else return check_valid(node->before, start, end);

        }
        else return false;

    }

    Event_Node *update_calender(Event_Node *node, int start, int end) {

        if (node == nullptr) node = new Event_Node(start, end);
        else if (start >= node->end_date) node->after = update_calender(node->after, start, end);
        else node->before = update_calender(node->before, start, end);

        return node;

    }


public:

    MyCalendar() {root = nullptr;}
    
    bool book(int start, int end) {
        
        bool valid = check_valid(root, start, end);
        if (valid) root = update_calender(root, start, end);
        return valid;

    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
