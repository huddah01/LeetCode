// We need a comparator class to order our pairs in the priority queue, by default pairs are ordered by
// First value, we also want the case where when first values equal we compare the second values, i.e.
// The condition when we find equally frequent words then the one that comes first alphabetically is ordered
// First
class myComparator {
  public:
    bool operator() (const pair<int, string> &p1, const pair<int, string> &p2) {
      if(p1.first == p2.first) {
          return p1.second > p2.second;
      }
      
      return p1.first < p2.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // Use a hash map to store frequencies then priority queue to get the two maxes
        unordered_map<string, int> wordFreq;
        priority_queue<pair<int, string>, vector<pair<int, string>>, myComparator> pq;
        vector<string> soln;
        
        // We count frequencies with the hash map
        for(int i = 0; i < words.size(); i++) {
            if(wordFreq.find(words[i]) == wordFreq.end()) {
                wordFreq[words[i]] = 1;
            }
            else {
                wordFreq[words[i]] += 1;
            }
        }

        // iterate through the map and push the frequency and word into our priority queue
        unordered_map<string, int>::iterator it;
        for(it = wordFreq.begin(); it != wordFreq.end(); it++) {
            pq.push({it->second, it->first});
        }

        // Now we simply push the the top of our priority queue k times(popping after every push)
        while(k != 0) {
            soln.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return soln;
    }
};
