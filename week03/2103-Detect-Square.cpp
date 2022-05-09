class DetectSquares {
public:
    map<pair<int, int>, int> points;
    DetectSquares() {
        points.clear();
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        points[{x, y}]++;
    }
    
    int count(vector<int> qpoint) {
        int total = 0;
        
        for( auto point : points) {
            int x1 = point.first.first;
            int y1 = point.first.second;
            int x4 = qpoint[0];
            int y4 = qpoint[1];
            
            if((x1 == x4) || (abs(x4 - x1) != abs(y4 - y1))) continue;

            if(points.count({x1, y4}) && points.count({x4, y1})){
                total += (points[{x1, y4}] * points[{x4, y1}] * point.second);
            }
        }
        return total;
    }
};