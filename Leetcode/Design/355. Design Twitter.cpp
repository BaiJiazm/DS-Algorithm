class Twitter
{
    struct Tweet
    {
        int time;
        int id;
        Tweet(int time, int id) : time(time), id(id) {}
    };

    std::unordered_map<int, std::vector<Tweet>> tweets; // [u] = array of tweets by u
    std::unordered_map<int, std::unordered_set<int>> following; // [u] = array of users followed by u

    int time;

public:
    Twitter() : time(0) {}

    void postTweet(int userId, int tweetId)
    {
        tweets[userId].emplace_back(time++, tweetId);
    }

    std::vector<int> getNewsFeed(int userId)
    {
        std::vector<std::pair<Tweet*, Tweet*>> h; // pair of pointers (begin, current)

        for (auto& u: following[userId])
        {
            auto& t = tweets[u];
            if (t.size() > 0)
                h.emplace_back(t.data(), t.data() + t.size() - 1);
        }
        auto& t = tweets[userId]; // self
        if (t.size() > 0)
            h.emplace_back(t.data(), t.data() + t.size() - 1);

        auto f = [](const std::pair<Tweet*, Tweet*>& x, const std::pair<Tweet*, Tweet*>& y) {
            return x.second->time < y.second->time;
        };
        std::make_heap(h.begin(), h.end(), f);

        const int n = 10;
        std::vector<int> o;
        o.reserve(n);
        for (int i = 0; (i < n) && !h.empty(); ++i)
        {
            std::pop_heap(h.begin(), h.end(), f);

            auto& hb = h.back();
            o.push_back(hb.second->id);

            if (hb.first == hb.second--)
                h.pop_back();
            else
                std::push_heap(h.begin(), h.end(), f);
        }
        return o;
    }

    void follow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
            following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        following[followerId].erase(followeeId);
    }
};