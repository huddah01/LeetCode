class Solution {
public:
    bool isHappy(int n) {
        int temp = -1;
        string temp2 = to_string(n);
        unordered_map<int, bool> temp3;

        while(temp3.find(temp) == temp3.end()) {
            temp3[temp] = true;
            temp = 0;

            for(int i = 0; i < temp2.size(); i++) {
                /**
                cout << "temp2[i] is " << temp2[i] << " ";
                cout << "int(temp2[i]) is " << int(temp2[i]) - 48 << " ";
                cout << "temp2[i] squared is " << pow((int(temp2[i]) - 48), 2) << endl;
                */
                temp += pow((int(temp2[i]) - 48), 2);
            }
            temp2 = to_string(temp);

            if(temp == 1) {
                return true;
            }
        }

        return false;
    }
};
