class Solution(object):
    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """

        # parameters
        room_num, room_count = len(rooms), 0
        visited = [False] * room_num
        keys = []

        # start computing
        keys.append(0)
        while keys:
            key = keys.pop(0)
            if visited[key]:
                continue
            else:
                room_count += 1
                visited[key] = True
                for find_key in rooms[key]:
                    keys.append(find_key)

        return (room_count == room_num)
                    
