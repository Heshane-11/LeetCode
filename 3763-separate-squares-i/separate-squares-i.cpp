class Solution {
public:

    bool check(vector<vector<int>>& squares, double& totalarea, double ym){
        double bottomarea = 0;
        for(int i = 0; i < squares.size(); i++){
            double y = squares[i][1];
            double l = squares[i][2];

            if(ym <= y) continue;
            else if(ym >= y + l) bottomarea += l*l; 
            else bottomarea += l * (ym - y);
        }
        return bottomarea >= totalarea/2;
    }

    double separateSquares(vector<vector<int>>& squares) {
        sort(squares.begin(), squares.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int n = squares.size();
        double totalarea = 0;
        double high = 0;
        for(int i = 0; i < squares.size(); i++){
            high = max(high, (double)squares[i][1] + squares[i][2]);
        }

        double low = squares[0][1];
        for(int i = 0; i < squares.size(); i++){
            int l = squares[i][2];
            totalarea += (double)l * l;

        }
        double mid = (high + low)/2;
        while(high - low > pow(10,-5)){
            if(check(squares, totalarea, mid)){
                high = mid;
            }
            else{
                low = mid;
            }
            mid = (high + low)/2;
        }
        return mid;
    }
};