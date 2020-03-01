/*

362. Design Hit Counter -- Medium
http://www.leetfree.com/problems/design-hit-counter.html


Design a hit counter which counts the number of hits received in the past 5 minutes.

Each function accepts a timestamp parameter (in seconds granularity) and you may assume 
that calls are being made to the system in chronological order (ie, the timestamp is monotonically increasing). 
You may assume that the earliest timestamp starts at 1.

It is possible that several hits arrive roughly at the same time.

Example:

HitCounter counter = new HitCounter();

// hit at timestamp 1.
counter.hit(1);

// hit at timestamp 2.
counter.hit(2);

// hit at timestamp 3.
counter.hit(3);

// get hits at timestamp 4, should return 3.
counter.getHits(4);

// hit at timestamp 300.
counter.hit(300);

// get hits at timestamp 300, should return 4.
counter.getHits(300);

// get hits at timestamp 301, should return 3.
counter.getHits(301);

*/

/*

使用一个queue存放所有hit的timestamp
每次hit(timestamp)就把timestamp存放到queue
每次getHits(timestamp)就从queue开头移除掉那些超时的timestamp

*/
class HitCounter {  
private:
    queue<int> Q;

public:  
    /** Initialize your data structure here. */  
    HitCounter() {  
          
    }  
      
    /** Record a hit. 
        @param timestamp - The current timestamp (in seconds granularity). */  
    void hit(int timestamp) {  
        Q.push(timestamp);
    }  
      
    /** Return the number of hits in the past 5 minutes. 
        @param timestamp - The current timestamp (in seconds granularity). */  
    int getHits(int timestamp) {  
        int startTime = timestamp - 300;
        while(!Q.empty() && Q.front() < startTime){     // pop out outliers
            Q.pop();
        }
        return Q.size();          // the remainings are all in time range
    }  
};  
  

/*

使用两个小为300的一维数组timestamps和hits存放时间戳和hit次数，即
hits[i]表示在timestamp=i的时候hit的次数
timestamps[i]表示第i个时间戳是多少

hit(int timestamp): 对timestamp 取余数，得到在数组中对应的坐标位置，
再看坐标位置存的timestamp跟这个新的timestamp是否一样，
如果不一样，则证明坐标位置存的timestamp已经过期了，把这个新的timestamp存入即可。

getHits(int timestamp): 遍历数组，把没过期的timestamp对应的hits加和。

*/
class HitCounter {  
private:
    vector<int> hits(300), timestamps(300);

public:  
    /** Initialize your data structure here. */  
    HitCounter() {  

    }  
      
    /** Record a hit. 
        @param timestamp - The current timestamp (in seconds granularity). */  
    void hit(int timestamp) {  
        int index = timestamp % 300;
        if(timestamps[index] != timestamp){
            timestamps[index] = timestamp;
            hits[index] = 1;
        }else{
            hits[index]++;
        }

    }  
      
    /** Return the number of hits in the past 5 minutes. 
        @param timestamp - The current timestamp (in seconds granularity). */  
    int getHits(int timestamp) {  
        int ans = 0;
        for(int i = 0; i < 300; i++){
            if(timestamp - timestamps[i] < 300){
                ans += hits[i];
            }
        }
        return ans;
    }  
}; 


/** 
 * Your HitCounter object will be instantiated and called as such: 
 * HitCounter obj = new HitCounter(); 
 * obj.hit(timestamp); 
 * int param_2 = obj.getHits(timestamp); 
 */ 

