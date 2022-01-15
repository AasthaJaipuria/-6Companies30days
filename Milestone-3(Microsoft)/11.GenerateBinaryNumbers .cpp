//GFG Question: https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	// Your code here
	vector <string> ans;
	string temp="1";
	ans.push_back("1");
	
	for(int i=2; i<=N; i++)
	{
        int endIndex = temp.length()-1;
        while(endIndex>=0 && temp[endIndex]=='1')
            {
                temp[endIndex]='0';
                endIndex--;
            }
          
        if(endIndex>=0)
          {
              temp[endIndex]='1';
          }
        else{
            temp = '1'+temp;
        }
	    ans.push_back(temp);
	}
	return ans;
}
