class Twitter {
    
    unordered_map<int,vector<int>> followers;
    unordered_map<int,vector<pair<int,int>>> tweets;
    
    int time;
public:
    Twitter() {
        time = 1;
    }
    
    void postTweet(int userId, int tweetId) {
        
        tweets[userId].push_back({tweetId,time});
        time++;
        return ;
        
    }
    
    vector<int> getNewsFeed(int userId) {
        
        vector<int> topRecentTweets, &userFollow = followers[userId];
        unordered_map<int,int> tweetPointer;
        priority_queue<pair<int,int>> q;
        pair<int,int> p;
        int tweetLen;
        for(int i=0;i<userFollow.size();i++)
        {
            vector<pair<int,int>> &followTweets = tweets[userFollow[i]];
            tweetLen = followTweets.size();
            if(tweetLen>0)
            {
                q.push({followTweets[tweetLen-1].second,userFollow[i]});
                tweetPointer[userFollow[i]] = tweetLen-1;
            }
        }
        tweetLen = tweets[userId].size();
        if(tweetLen>0)
        {
            q.push({tweets[userId][tweetLen-1].second,userId});
            tweetPointer[userId] = tweetLen-1;
        }
        
        int count = 10;
        while(!q.empty()&&count--)
        {
            p = q.top();
            q.pop();
            int tweetId = tweets[p.second][tweetPointer[p.second]].first;
            if(tweetPointer[p.second]>0)
            {
                int timeLine = tweets[p.second][tweetPointer[p.second]-1].second;
                q.push({timeLine,p.second});
                tweetPointer[p.second]--;
            }
            topRecentTweets.push_back(tweetId);
        }
        
        
        return topRecentTweets;
        
    }
    
    void follow(int followerId, int followeeId) {
        
        for(int i=0;i<followers[followerId].size();i++)
        {
            if(followers[followerId][i]==followeeId)
                return ;
        }
        followers[followerId].push_back(followeeId);
        return ;
        
    }
    
    void unfollow(int followerId, int followeeId) {
        
        vector<int> &userFollow = followers[followerId];
        int pos = -1;
        for(int i=0;i<userFollow.size();i++)
        {
            if(userFollow[i]==followeeId)
            {
                pos = i;
                break;
            }
        }
        
        if(pos==-1)
            return ;
        
        userFollow.erase(userFollow.begin()+pos);
        return ;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */