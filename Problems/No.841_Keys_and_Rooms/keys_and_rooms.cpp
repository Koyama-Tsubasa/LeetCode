class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        // parameters
        int room_num = rooms.size(), room_count = 0;
        std::vector<bool> visited(room_num, false);
        std::queue<int> keys;

        // start computing
        keys.push(0);
        while (!keys.empty()) {

            auto key = keys.front();
            keys.pop();
            
            if (visited[key] == true) continue;
            else {

                room_count++;
                visited[key] = true;
                for (auto find_key: rooms[key]) 
                    keys.push(find_key);

            }

        }

        return (room_count == room_num);

    }
};
