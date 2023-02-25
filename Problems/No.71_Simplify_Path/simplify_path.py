class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """

        # parameter
        relative_paths = []

        # start computing
        for rp in path.split("/"):
            if ((rp == "..") and relative_paths):
                relative_paths.pop()
            elif rp not in ["", ".", ".."]:
                relative_paths.append(rp)

        return "/" + "/".join(relative_paths)
