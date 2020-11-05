/*

		Codeforces 673 Div3 D
	
		
Kolya got an integer array a1,a2,…,an. The array can contain both positive and negative integers, but Kolya doesn't like 0, so the array doesn't contain any zeros.

Kolya doesn't like that the sum of some subsegments of his array can be 0. The subsegment is some consecutive segment of elements of the array.

You have to help Kolya and change his array in such a way that it doesn't contain any subsegments with the sum 0. To reach this goal, you can insert any integers between any pair of adjacent elements of the array (integers can be really any: positive, negative, 0, any by absolute value, even such a huge that they can't be represented in most standard programming languages).

Your task is to find the minimum number of integers you have to insert into Kolya's array in such a way that the resulting array doesn't contain any subsegments with the sum 0.


*/
#define ll long long
ll fun(ll arr[])
{
unordered_set<ll> map;
    map.insert(0LL);
    ll sum = 0, res = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += arr[i];
        if (map.find(sum) != map.end())
        {
            res++;
            map.clear();
            map.insert(0LL);
            sum = arr[i];
        }
        map.insert(sum);
    }
    return res;
}
