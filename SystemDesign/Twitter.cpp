#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

// Tweet is a linked list
class Tweet
{
private:
    int tweetId;
    int timestamp;
    Tweet* next;

public:
    Tweet( int tweetId, int timestamp )
    {
        this->tweetId = tweetId;
        this->timestamp = timestamp;
        next = nullptr;
    }

    friend class User;
    friend class Twitter;
};

class User
{
private:
    int userId;
    std::unordered_set<int> followees;
    Tweet* tweetsHead;

public:
    User( int userId )
    {
        this->userId = userId;
        tweetsHead = nullptr;
        followees.insert( userId );                         // User first follows himself
    }

    ~User()
    {
        Tweet* temp = tweetsHead;
        while( tweetsHead )
        {
            temp = tweetsHead->next;
            delete tweetsHead;
            tweetsHead = temp;
        }
    }

    void post( int tweetId, int timestamp )
    {
        // Insert at the head of the linked list
        Tweet* t = new Tweet( tweetId, timestamp );
        t->next = tweetsHead;
        tweetsHead = t;
    }

    void follow( int followeeId )
    {
        followees.insert( followeeId );
    }

    void unfollow( int followeeId )
    {
        if( followees.find( followeeId ) != followees.end() && followeeId != userId )
        {
            followees.erase( followeeId );
        }
    }

    friend class Twitter;
};

class Twitter 
{
private:
    std::unordered_map<int, User*> userMap;
    int timestamp;

public:
    /** Initialize your data structure here. */
    Twitter() 
    {
        timestamp = 0;
    }

    /** Compose a new tweet. */
    void postTweet( int userId, int tweetId ) 
    {
        // If user is not present in the DB, create
        if( userMap.find( userId ) == userMap.end() )
        {
            userMap[ userId ] = new User( userId );
        }

        // Post a tweet
        userMap[ userId ]->post( tweetId, timestamp );
        timestamp++;
    }

    // Comparator for priority queue
    class Comparator
    {
    public:
        Comparator() {}
        ~Comparator() {}

        bool operator() ( const Tweet* t1, const Tweet* t2 )
        {
            return t1->timestamp < t2->timestamp;
        }
    };

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    std::vector<int> getNewsFeed( int userId ) 
    {
        std::vector<int> feed;

        // If user not present in DB, return empty feed
        if( userMap.find( userId ) == userMap.end() ) return feed;

        // Create a priority queue and add all the head tweets of the followees in it
        std::priority_queue<Tweet*, std::vector<Tweet*>, Comparator> pq;
        for( int u : userMap[ userId ]->followees )
        {
            if( userMap[u]->tweetsHead != nullptr )
                pq.push( userMap[ u ]->tweetsHead );
        }

        // Start filling the feed, and as you remove tweet from pq, add next element to the 
        // pq if it exists
        for( int i = 0; i < 10 && !pq.empty(); i++ )
        {
            Tweet* t = pq.top();
            pq.pop();
            feed.push_back( t->tweetId );
            if( t->next != nullptr ) pq.push( t->next );
        }

        return feed;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow( int followerId, int followeeId ) 
    {
        // Check if followerId and followeeId are present
        if( userMap.find( followerId ) == userMap.end() )
        {
            userMap[ followerId ] = new User( followerId );
        }

        if( userMap.find( followeeId ) == userMap.end() )
        {
            userMap[ followeeId ] = new User( followeeId );
        }

        // Add followee to the list of followees of follower
        userMap[ followerId ]->follow( followeeId );
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow( int followerId, int followeeId ) 
    {
        // Check if followerId and followeeId are present
        if( userMap.find( followerId ) == userMap.end() || userMap.find( followeeId ) == userMap.end() )
        {
            return;
        }

        // Remove followee from the list of followees of follower
        userMap[ followerId ]->unfollow( followeeId );
    }
};

/**
* Your Twitter object will be instantiated and called as such:
* Twitter obj = new Twitter();
* obj.postTweet(userId,tweetId);
* vector<int> param_2 = obj.getNewsFeed(userId);
* obj.follow(followerId,followeeId);
* obj.unfollow(followerId,followeeId);
*/

int main() 
{
    Twitter* obj = new Twitter();
    obj->postTweet( 1, 5 );
    obj->getNewsFeed( 1 );
    obj->follow( 1, 2 );
    obj->postTweet( 2, 6 );
    obj->getNewsFeed( 1 );
    obj->unfollow( 1, 2 );
    obj->getNewsFeed( 1 );
}
