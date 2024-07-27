class Solution {
public:

    void quickSort(vector<pair<int,int>> &data, int start, int end){
        if(start < end){
            int left = start, right = end;
            int pivot = data[left].second;
            while(left < right){
                while(data[right].second <= pivot && left < right){
                    right--;
                }
                while(data[left].second >= pivot && left < right){
                    left++;
                }
                if(left < right){
                    swap(data[left],data[right]);
                }
            }
            swap(data[left],data[start]);
            quickSort(data,start,left-1);
            quickSort(data,left+1,end);
        }
    }
    void heapify(vector<pair<int,int>> &heap, int n, int root){
        int largest = root;
        int left = 2*root+1;
        int right = 2*root+2;
        if(left < n && heap[left].second > heap[largest].second){
            largest = left;
        }
        if(right < n && heap[right].second > heap[largest].second){
            largest = right;
        }
        if(largest != root){
            swap(heap[largest],heap[root]);
            heapify(heap,n,largest);
        }
        return;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m_map;
        for(int i=0; i<nums.size(); i++){
            m_map[nums[i]]++;
        }
        vector<pair<int,int>> data;
        /*
        for(auto &it : m_map){
            data.emplace_back(pair<int,int>(it.first,it.second));
        }
        quickSort(data,0,data.size()-1);
        */
        for(auto &it : m_map){
            data.emplace_back(pair<int,int>(it.first,it.second));
            for (int i = data.size() / 2 - 1; i >= 0; i--)
                heapify(data, data.size(),i);
        }
        vector<int> result;
        for(int i=0;i<k;i++){
            result.push_back(data[0].first);
            data.erase(data.begin());
            for (int i = data.size() / 2 - 1; i >= 0; i--)
                heapify(data, data.size(),i);
        }
        return result;
    }
};