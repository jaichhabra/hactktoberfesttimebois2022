class Solution {
public:
	long long maximizeHappiness(vector<int>nums){
		using ll = long long int;
		int n = (int)nums.size() / 3;
		priority_queue<ll>pq;
		ll sum = 0;
		vector<ll>l(n+1,0);
		for(int i = 0; i < n; i++){
		    sum += nums[i];
		    pq.push(nums[i]);
		}
		l[0] = sum;
		for(int i = n; i < 2*n; i++){
		    ll x = pq.top();
		    pq.pop();
		    sum = sum - x + nums[i];
		    l[i-n+1] = sum;
		    pq.push(nums[i]);
		}
		sum = 0;
		priority_queue<ll, vector<ll>, greater<ll>>pq1;
		for(int i = 2*n; i < 3*n; i++){
		    sum += nums[i];
		    pq1.push(nums[i]);
		}
		vector<ll>r(n+1, 0);
		r[0] = sum;
		for(int i = 2*n-1; i >= n; i--){
		    ll x = pq1.top();
		    pq1.pop();
		    sum = sum - x + nums[i];
		    r[2*n - i] = sum;
		    pq1.push(nums[i]);
		}
		for(int i = 1; i <= n; i++)r[i] = max(r[i], r[i-1]);
		for(int i = 1; i <= n; i++)l[i] = min(l[i], l[i-1]);
		ll ans = 1e18;
		for(int i = 0; i <= n; i++){
		    ans = min(ans, l[i] - r[n-i]);
		}
		return ans;
	}
};
