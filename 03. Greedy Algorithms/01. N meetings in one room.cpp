// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1
// T.C => O(n*log(n))

class Triplet {
public:
	int id;
	int start;
	int end;
	Triplet(int id, int s, int e) {
		this.id = id;
		this.start = s;
		this.end = e;
	}
};

bool comp(Triplet &t1, Triplet &t2) {
	return t1.end < t2.end;
}

void maxMeetings(int start[], int end[], int n) {
	vector<Triplet> meetings;
	for (int i = 0; i < n; ++i) {
		meetings.push_back({i + 1, start[i], end[i]});
	}
	// sort acc to increasing order of end time
	sort(meetings.begin(), meetings.end(), comp);
	Triplet prev = meetings[0];
	cout << prev.id << " ";
	for (auto &m : meetings) {
		// if the start time of curr selected metting is greater than or equal to prev selected
		// metting then print it and update prev selected to curr
		if (m.start >= prev.end) {
			cout << m.id << " ";
			prev = m;
		}
	}
}