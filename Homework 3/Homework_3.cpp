#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;



vector<vector<int>> GetAdjacencyList(int n, vector<pair<int, int>>& edges);

int MinMeetingRooms(vector<vector<int>>& intervals);

int main()
{
	vector<vector<int>> intervals = { {0,30}, {5,10},{15,20} };
	cout << "Minimum number of meeting rooms required: " << MinMeetingRooms(intervals) << endl;
	
	
	
	
	return 0;
}




vector<vector<int>> GetAdjacencyList(int n, vector<pair<int, int>>& edges)
{
	vector<vector<int>> adjList(n);
	for (size_t i = 0; i < edges.size(); ++i)
	{
		int u = edges[i].first;
		int v = edges[i].second;

		adjList[u].push_back(v);
	}
	return adjList;
}



int MinMeetingRooms(vector<vector<int>>& intervals)
{
	if (intervals.empty())
	{
		return 0;
	}

	sort(intervals.begin(), intervals.end());

	priority_queue<int, vector<int>, greater<int>> min_heap;

	min_heap.push(intervals[0][1]);

	for (int i = 1; i < intervals.size(); ++i)
	{
		if (intervals[i][0] >= min_heap.top())
		{
			min_heap.pop();
		}
		min_heap.push(intervals[i][1]);
	}
	return min_heap.size();

}



//References