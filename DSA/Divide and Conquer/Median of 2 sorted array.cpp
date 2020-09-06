class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;vector<int> b;
        int n=nums1.size(),m=nums2.size();
        if(n==0){
            if(m%2)
                return nums2[m/2];
            else return (nums2[m/2]+nums2[m/2-1])/2.0;
        }
        if(m==0){
            if(n%2)
                return nums1[n/2];
            else return (nums1[n/2]+nums1[n/2-1])/2.0;
        }
        if(n<m){
            a=nums1;b=nums2;
        }
        else {a=nums2;b=nums1;swap(n,m);}
        int min_ind=0,max_ind=n,median,i,j;
        while(min_ind<=max_ind){
            i=(min_ind+max_ind)/2;
            j=(m+n+1)/2-i;
            if(i<n&&j>0&&a[i]<b[j-1])
                min_ind=i+1;
            else if(i>0&&j<m&&b[j]<a[i-1])
                max_ind=i-1;
            else{
                if(i==0)
                    median=b[j-1];
                else if(j==0)
                    median=a[i-1];
                else
                    median=max(a[i-1],b[j-1]);
                break;
            }
        }
        if((m+n)%2)
            return (double)median;
        if(i==n)
            return (median+b[j])/2.0;
        if(j==m)
            return (median+a[i])/2.0;
        return (median+min(a[i],b[j]))/2.0;
    }
};
