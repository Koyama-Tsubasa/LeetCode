class Solution(object):
    def countStudents(self, students, sandwiches):
        """
        :type students: List[int]
        :type sandwiches: List[int]
        :rtype: int
        """

        # start computing
        while students:
            for sandwich in sandwiches:
                cnt = 0
                while (students[0] != sandwich):
                    students.append(students.pop(0))
                    cnt += 1
                    if (cnt == len(students)):
                        return len(students)
                students.pop(0)
        
        return 0
