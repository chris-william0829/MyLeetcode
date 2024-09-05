class Solution {
public:

    void buildHead(vector<int>& nums, int n){
        for(int i=n/2-1; i>=0;i--){
            int current = i;
            while(current < n){
                int left = 2 * current + 1;
                int right = 2 * current + 2;
                int largest = current;
                if(left < n && nums[left] > nums[largest]){
                    largest = left;
                }
                if(right < n && nums[right] > nums[largest]){
                    largest = right;
                }
                if(largest == current){
                    break;
                }else{
                    int temp = nums[largest];
                    nums[largest] = nums[current];
                    nums[current] = temp;
                }
            }
        }
    }

    //buildheap timeout, use priority_queue;

    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        long long ans = 0;
        for (int _ = 0; _ < k; ++_) {
            int x = q.top();
            q.pop();
            ans += x;
            q.push((x + 2) / 3);
        }
        return ans;
    }
};