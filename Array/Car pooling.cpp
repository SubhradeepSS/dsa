/* You are driving a vehicle that has capacity empty seats initially available for passengers.  The vehicle only drives east (ie. it cannot turn around and drive west.)
Given a list of trips, trip[i] = [num_passengers, start_location, end_location] contains information about the i-th trip: the number of passengers that must be picked up, and the locations to pick them up and drop them off.  The locations are given as the number of kilometers due east from your vehicle's initial location.

Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 

Input: trips = [[2,1,5],[3,5,7]], capacity = 3
Output: true

Input: trips = [[3,2,7],[3,7,9],[8,3,9]], capacity = 11
Output: true 
Constraints:
    trips.length <= 1000
    trips[i].length == 3
    1 <= trips[i][0] <= 100
    0 <= trips[i][1] < trips[i][2] <= 1000
    1 <= capacity <= 100000
*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>> util;
        for(auto v:trips){
            util.push_back({v[1],v[0]});
            util.push_back({v[2],-v[0]});
        }
        sort(util.begin(),util.end());
        int curr=0;
        for(auto d:util){
            curr+=d.second;
            if(curr>capacity)
                return false; 
        }
        return true;
    }
};


// another solution
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> util(1001, 0);
        for(auto t:trips){
            util[t[1]] += t[0];
            util[t[2]] -= t[0];
        }
        int curr=0;
        for(int i:util){
            curr += i;
            if(curr>capacity)
                return false;
        }
        return true;
    }
};
