// 加快输入输出速度，用于大量的输入
ios::sync_with_stdio(0);
cout.tie(0);
cin.tie(0);

//优先对列 （greater代表由小到大排序，小根堆）
priority_queue<ll, vector<ll>, greater<ll> > pq; 

//set的upper_bound，当想要查找指定值附近的数却不确定是否有该指定值，可以先查找大于改指定值的数，然后再将迭代器--
std::set 的 upper_bound 函数用于返回一个指向集合中第一个大于给定键值的元素的迭代器。