class Twitter {
public:

    int timer = 0;

    unordered_map<int, vector<pair<int,int>>> tweets;//userId -> [(time, tweetId)]

    unordered_map<int, unordered_set<int>> following;//1 follows -> {2,3,4}


    Twitter() {

    }


    void postTweet(int userId, int tweetId) {

        tweets[userId].push_back({timer, tweetId});

        timer++;
    }


    vector<int> getNewsFeed(int userId) {

        vector<pair<int,int>> feed; //(time, tweetId)


        // own tweets
        for(auto &tweet : tweets[userId]) {

            feed.push_back(tweet);
        }


        // followed users tweets
        for(int followee : following[userId]) {

            for(auto &tweet : tweets[followee]) {

                feed.push_back(tweet);
            }
        }


        // latest first
        sort(feed.begin(), feed.end(), greater<>());


        vector<int> ans;


        for(int i = 0; i < min(10, (int)feed.size()); i++) {

            ans.push_back(feed[i].second);
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
