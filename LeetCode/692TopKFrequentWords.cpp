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

        for(int i = 0; i < words.size(); i++) {
            if(wordFreq.find(words[i]) == wordFreq.end()) {
                wordFreq[words[i]] = 1;
            }
            else {
                wordFreq[words[i]] += 1;
            }
        }

        unordered_map<string, int>::iterator it;
        for(it = wordFreq.begin(); it != wordFreq.end(); it++) {
            pq.push({it->second, it->first});
        }

        while(k != 0) {
            soln.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return soln;
    }
};
