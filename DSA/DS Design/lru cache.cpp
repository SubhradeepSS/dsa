#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// design the class:

class LRUCache
{
private:
    int size;
    list<pair<int,int>> val;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
public:
    LRUCache(int cap)
    {
        // constructor for cache
        size=cap;
    }
    
    int get(int key)
    {
        // this function should return value corresponding to key
        if(mp.find(key)==mp.end())
            return -1;
        auto it=mp[key];
        //val.erase(it);
        val.push_front(*it);
        val.erase(it);
        mp[key]=val.begin();
        return (*val.begin()).second;
    }
    
    void set(int key, int value)
    {
        // storing key, value pair
        if(mp.find(key)!=mp.end()){
            auto it=mp[key];
            val.erase(it);
            mp.erase(key);
            //it->second=value;
            val.push_front({key,value});
            mp[key]=val.begin();
        }
        else{
            if(val.size()<size){
                val.push_front({key,value});
                mp[key]=val.begin();
            }
            else{
                auto l=val.back();
                auto it=mp[l.first];
                //val.pop_back();
                mp.erase(l.first);
                val.pop_back();
                val.push_front({key,value});
                mp[key]=val.begin();
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends