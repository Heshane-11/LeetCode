class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(letters[0] > target){
            return letters[0];
        }
        int s = 0, e = letters.size()-1;
        int mid = s + (e-s)/2;
        while(s < e){
            if(letters[mid] <= target){
                s = mid + 1;
            }
            else {
                e = mid;
            }
            mid = s + (e-s)/2;
        }
        if(letters[mid] > target){
            return letters[mid];
        }
        return letters[0];
    }
}; 