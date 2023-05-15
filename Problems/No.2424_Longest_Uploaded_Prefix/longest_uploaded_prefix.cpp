class LUPrefix {

private:
    int LUP = 0;
    std::set<int> Vstream;

public:
    LUPrefix(int n) {Vstream.insert(0);}
    
    void upload(int video) {

        Vstream.insert(video);
        while (Vstream.count(LUP+1)) LUP++;

    }
    
    int longest() {return LUP;}
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
