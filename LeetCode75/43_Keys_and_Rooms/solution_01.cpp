class Solution {
public:
    bool detectCycleDFS(int src,vector<vector<int>>&rooms,vector<bool>&visited){
          if(visited[src]){
            return false;
          }
          visited[src]=true;
          for(auto it:rooms[src]){
            detectCycleDFS(it,rooms,visited);
          }
          return true;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int len=rooms.size();
        vector<bool>visited(len);
        bool hasCycle=detectCycleDFS(0,rooms,visited);
        for(int i=0;i<len;i++){
            if(!visited[i]){
                return false;
            }
        }
        return hasCycle;
    }
};