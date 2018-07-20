class MedianFinder
{
    double mid;
    priority_queue<int, vector<int>, less<int>> lessQ;
    priority_queue<int, vector<int>, greater<int>> greaterQ;

  public:
    /** initialize your data structure here. */
    MedianFinder()
    {
        mid = 0;
    }

    void addNum(int num)
    {
        if (num > mid)
        {
            greaterQ.push(num);
        }
        else
        {
            lessQ.push(num);
        }
        //注意一个问题，uint int -> uint 必须强制转为int比较
        if ((int)lessQ.size() - (int)greaterQ.size() > 1)
        {
            cout << lessQ.size() << " " << greaterQ.size() << " \n";
            greaterQ.push(lessQ.top());
            lessQ.pop();
        }
        if ((int)greaterQ.size() - (int)lessQ.size() > 1)
        {
            lessQ.push(greaterQ.top());
            greaterQ.pop();
        }
        mid = lessQ.size() == greaterQ.size() ? (lessQ.top() + greaterQ.top()) / 2.0 : lessQ.size() > greaterQ.size() ? lessQ.top() : greaterQ.top();
    }

    double findMedian()
    {
        return mid;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
