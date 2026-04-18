class Tweet implements Comparable<Tweet> {
    private final Integer tweetId;
    private final Integer userId;
    private final Integer timestamp;

    public Tweet(Integer tweetId, Integer userId, Integer timestamp) {
        this.tweetId = tweetId;
        this.userId = userId;
        this.timestamp = timestamp;
    }

    public Integer getTimestamp() {
        return timestamp;
    }

    public Integer getTweetId() {
        return tweetId;
    }

    public Integer getUserId() {
        return userId;
    }

    @Override
    public int compareTo(final Tweet other) {
        return Integer.compare(other.getTimestamp(), this.getTimestamp());
    }
}

public class Node {
    Tweet tweet;
    int userId;
    int index;

    Node(Tweet tweet, int userId, int index) {
        this.tweet = tweet;
        this.userId = userId;
        this.index = index;
    }
}

class Twitter {

    private final Map<Integer, List<Tweet>> userTweets;
    private final Map<Integer, List<Tweet>> userFeed;
    private final Map<Integer, Set<Integer>> userFollowings;
    private final Map<Integer, Set<Integer>> userFollowers;
    private final AtomicInteger tweetNumber;

    public Twitter() {
        userTweets = new HashMap<>();
        userFeed = new HashMap<>();
        userFollowings = new HashMap<>();
        userFollowers = new HashMap<>();
        tweetNumber = new AtomicInteger(0);
    }
    
    public void postTweet(int userId, int tweetId) {
        final Tweet tweet = new Tweet(tweetId, userId, tweetNumber.getAndIncrement());
        userTweets.computeIfAbsent(userId, k -> new ArrayList<>()).add(tweet);
    }
    
    public List<Integer> getNewsFeed(int userId) {
        PriorityQueue<Node> feed = new PriorityQueue<>((a, b) -> Integer.compare(b.tweet.getTimestamp(), a.tweet.getTimestamp()));
        Set<Integer> followings = userFollowings.getOrDefault(userId, new HashSet<>());
        for (Integer followingUserId: followings) {
            List<Tweet> followingUserTweets = userTweets.getOrDefault(followingUserId, new ArrayList<>());
            if (!followingUserTweets.isEmpty()) {
                feed.add(new Node(followingUserTweets.getLast(), followingUserId, followingUserTweets.size() - 1));
            }
        }
        if (!userTweets.getOrDefault(userId, new ArrayList<>()).isEmpty()) {
            feed.add(new Node(userTweets.get(userId).getLast(), userId, userTweets.get(userId).size() - 1));
        }

        int count = 0;
        List<Integer> response = new ArrayList<>();

        while (count < 10 && !feed.isEmpty()) {
            Node current = feed.poll();
            response.add(current.tweet.getTweetId());

            if (current.index > 0) {
                Tweet lastTweet = userTweets.get(current.userId).get(current.index - 1);
                feed.add(new Node(lastTweet, current.userId, current.index - 1));
            }

            count++;
        }

        return response;
     }
    
    public void follow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        userFollowings.computeIfAbsent(followerId, k -> new HashSet<>()).add(followeeId);
        userFollowers.computeIfAbsent(followeeId, k -> new HashSet<>()).add(followerId);
    }
    
    public void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId) {
            return;
        }
        userFollowings.computeIfAbsent(followerId, k -> new HashSet<>()).remove(followeeId);
        userFollowers.computeIfAbsent(followeeId, k -> new HashSet<>()).remove(followerId);
        final List<Tweet> followerNewsFeed = userFeed.getOrDefault(followerId, new ArrayList<>());
        followerNewsFeed.removeIf(tweet -> tweet.getUserId() == followeeId);
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */