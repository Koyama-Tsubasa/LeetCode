class LUPrefix {

private:
    int LUP = 0;
    std::map<int, bool> Vstream;

public:
    LUPrefix(int n) {Vstream[0] = true;}
    
    void upload(int video) {

        Vstream[video] = true;
        while (Vstream[LUP+1] == true) LUP++;

    }
    
    int longest() {return LUP;}
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
