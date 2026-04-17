class Twitter
{
public:
    stack<pair<int, int>> tweets;
    stack<pair<int, int>> tweetsCopy;
    unordered_map<int, unordered_set<int>> followMap;
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId){
        tweets.push({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> res;
        int i = 0;
        while (i < 10 && tweets.size() != 0)
        {
            auto topElement = tweets.top();
            tweets.pop();
            if (topElement.first == userId || followMap[userId].find(topElement.first) != followMap[userId].end())
            {
                res.push_back(topElement.second);
                i++;
            }
            tweetsCopy.push(topElement);
        }
        while(!tweetsCopy.empty()) {
            tweets.push(tweetsCopy.top());
            tweetsCopy.pop();
        }
        return res;
    }

    void follow(int followerId, int followeeId)
    {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        followMap[followerId].erase(followeeId);
    }
};
