class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Priority queue(max heap) for implementation
        priority_queue<int> pq;

        // Add all stones to the max heap
        for(int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }

        // Until we have 1 or less stones we compare the top two maxes
        while(pq.size() > 1) {
            int stone1 = pq.top();
            pq.pop();
            int stone2 = pq.top();
            pq.pop();
            // If they aren't equal then we add the difference into max heap
            // Otherwise we forget about both
            if(stone1 != stone2) {
                pq.push(stone1 - stone2);
            }
        }
        // We check for the max heap to be empty first to avoid seg fault
        if(pq.empty()) {
            return 0;
        }
        // Otherwise return the only element left in the max heap
        return pq.top();
    }
};
