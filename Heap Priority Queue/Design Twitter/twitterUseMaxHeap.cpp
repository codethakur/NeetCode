class Twitter {
public:

    int timer = 0;

    unordered_map<int, vector<pair<int,int>>> tweets;//userId -> [(time, tweetId)]

    unordered_map<int, unordered_set<int>> following;//1 follows -> {2,3,4}


    Twitter() {

    }


    void postTweet(int userId, int tweetId) {

        tweets[userId].push_back({timer, tweetId});
        if (tweets[userId].size() > 10) {
            tweets[userId].erase(tweets[userId].begin());
        }
        timer++;
    }


    vector<int> getNewsFeed(int userId) {

       priority_queue<pair<int,int>> maxHeap; //(time, tweetId)


        // own tweets
        for(auto &tweet : tweets[userId]) {

            maxHeap.push(tweet);
        }


        // followed users tweets
        for(int followee : following[userId]) {

            for(auto &tweet : tweets[followee]) {

                maxHeap.push(tweet);
            }
        }


         vector<int> ans;


        while(!maxHeap.empty() && ans.size() < 10) {

            ans.push_back(maxHeap.top().second);

            maxHeap.pop();
        }

        return ans;
    }


    void follow(int followerId, int followeeId) {

        if(followerId == followeeId) {
            return;
        }

        following[followerId].insert(followeeId);
    }


    void unfollow(int followerId, int followeeId) {

        following[followerId].erase(followeeId);
    }
};
