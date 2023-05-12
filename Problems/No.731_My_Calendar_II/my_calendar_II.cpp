class Event_Node {

public:
    int start_date, end_date;
    int booking_cnt = 1;
    Event_Node *before, *after;
    Event_Node(int start_date, int end_date) {

        this->start_date = start_date;
        this->end_date = end_date;
        before = nullptr;
        after = nullptr;

    }

};

class MyCalendarTwo {

private:
    Event_Node *root;

    bool check_valid(Event_Node *node, int start, int end) {

        if (node == nullptr) return true;
        else if (start > node->end_date) return check_valid(node->after, start, end);
        else if (end < node->start_date) return check_valid(node->before, start, end);
        else if (node->booking_cnt < 2) return check_valid(node->before, std::min(start, node->start_date), std::max(start, node->start_date)-1) &&
                                         check_valid(node->after, std::min(end, node->end_date)+1, std::max(end, node->end_date)); 
        else return false;

    }

    Event_Node *update_calendar(Event_Node *node, int start, int end) {

        if (node == nullptr) node = new Event_Node(start, end);
        else if (start > node->end_date) node->after = update_calendar(node->after, start, end);
        else if (end < node->start_date) node->before = update_calendar(node->before, start, end);
        else {

            node->before = update_calendar(node->before, std::min(node->start_date, start), std::max(start, node->start_date)-1);
            node->after = update_calendar(node->after, std::min(end, node->end_date)+1, std::max(end, node->end_date));
            node->start_date = std::max(start, node->start_date);
            node->end_date = std::min(end, node->end_date);
            node->booking_cnt++;

        }

        return node;

    }

public:

    MyCalendarTwo() {root = nullptr;}

    bool book(int start, int end) {

        bool valid = check_valid(root, start, end-1);
        if (valid) root = update_calendar(root, start, end-1);
        return valid;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
