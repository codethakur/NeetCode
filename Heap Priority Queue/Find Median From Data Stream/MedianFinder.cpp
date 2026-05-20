class MedianFinder {

    vector<int> data;

public:

    MedianFinder() {

    }


    void addNum(int num) {

        data.push_back(num);
    }


    double findMedian() {

        vector<int> temp = data;

        sort(temp.begin(), temp.end());

        int n = temp.size();


        // odd size
        if(n % 2 == 1) {

            return temp[n / 2];
        }


        // even size
        return (temp[n / 2] + temp[n / 2 - 1]) / 2.0;
    }
};
