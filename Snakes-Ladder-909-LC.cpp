class Solution {
public:

	int bfs (vector<int> b, int des){
    des = des*des;
	queue<int> q;
	vector<bool> visited (des+1, false);

	int turns = 0;

	q.push(1);
	visited[1] = true;

	while(!q.empty())
	{
		int nn = q.size();
		for(int i=0;i<nn;i++)
		{
			int curr = q.front();
			q.pop();

			if(curr == des)
			return turns;

			for(int i=curr+1;i<=curr+6;i++){
			 if(i>des) break;
			 if(visited[i]) continue;

			 if(b[i]!=-1)
			 		q.push(b[i]);
			 else q.push(i);
			 
			 visited[i] = true;		

			}
		}

		turns++;
	}
	return -1;
}



	
    int snakesAndLadders(vector<vector<int>>& board) {

      int n = board.size();
      vector<int> b;
      b.push_back(0);
      int f = 1;
      for(int i=n-1;i>=0;i--){

      if(f==1){
      for(int j=0;j<n;j++)
      	b.push_back(board[i][j]);
      }
      else{
      for(int j=n-1;j>=0;j--)
       b.push_back(board[i][j]);
      }
      f = -f;


      }
      int des = n;
      int ans = bfs(b,n);
      return ans;  
    }
};