//判断快乐数
//发放
#include<iostream>
#include<vector>
using namespace std;

vector<int> getnum(int n2)
{
vector<int>num;
int tmp = 0;
for (int i = n2; i >= 1; i = i / 10)
{
	tmp = i % 10;
	num.push_back(tmp);
}
return num;
}

bool isHappy(int n)
{
	int maxsize = 10;
	int sum = 0;
	vector<int>num;
	num = getnum(n);
	while (maxsize > 0)
	{
		sum = 0;
		for (int j = 0; j < num.size(); ++j)
		{
			sum += num[j] * num[j];
		}
		if (sum == 1)return true;
		else num = getnum(sum);
		maxsize--;
	}

	if (sum == 1)return true;

}
int main1()
{
	int nn = 21;
	bool a=isHappy(nn);
	cout << a << endl;
	system("pause");
	return 0;
}

//从排序数组中删除重复项
int removeDuplicates(vector<int>&nums)
{
	/*if (nums.size() == 0)
	{
		return 0;
	}
	int number = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		if (nums[number] != nums[i])
		{
			number++;
		}
		nums[number] = nums[i];

	}
	return number+1;*/
	if (nums.empty()) {
		return 0;
	}
	int number = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[number] != nums[i]) {
			number++;
			nums[number] = nums[i];
		}
	}
	return (number + 1);

}

int main2()
{
	vector<int>nums = { 0, 2, 2, 2, 3 ,4,4,5,5,5};
	int ret=removeDuplicates(nums);
	cout << ret << endl;
	for (int i = 0; i < ret; ++i)
	{
		cout << nums[i] << " ";
	}
	system("pause");
	return 0;
}

//买卖股票的最佳时机 II

int maxProfit(vector<int>& prices) 
{
	if (prices.size() == 0)
	{
		return 0;
	}
	int buyday = 0;
	int sellday = 0;
	int summoney = 0;
	int bi = 0;
	while(bi < prices.size()-1)
	{
		if (prices[bi] < prices[bi + 1])
		{
			buyday = bi;
			sellday = bi + 1;
			for (int si = bi + 1; si < prices.size()-1; ++si)
			{
				if (prices[si]>prices[si + 1])
				{
					sellday = si;
					break;
				}
				sellday = si+1;
			}
			summoney += prices[sellday] - prices[buyday];
			bi = sellday + 1;
		}
		else
		{
			bi++;
		}
		

	}
	return summoney;

}

int main3()
{
	vector<int> prices = {};
	int summoney =maxProfit(prices);
	cout << summoney << endl;
	system("pause");
	return 0;
}


//旋转数组
void rotate(vector<int>& nums, int k) {
	int maxsize = nums.size();
	k = k%maxsize;
	int tmp = 0;
	int *nums_tmp = new int[maxsize];
	for (int i = 0; i < maxsize; ++i)
	{
		nums_tmp[i] = nums[i];
	}
	for (int i = 0; i < maxsize; ++i)
	{
		nums[i] = nums_tmp[(maxsize - k + i) % maxsize];
	}

}
int main()
{
	vector<int>nums = { 1, 2 };
	rotate(nums, 3);
	for (int i = 0; i < nums.size(); ++i)
	{
		cout << nums[i] << " ";
	}
	return 0;
}
