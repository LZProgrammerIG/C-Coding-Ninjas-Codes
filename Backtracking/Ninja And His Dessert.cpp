/*
Ninja is planning to make dessert. For which he is going to buy ingredients. 
There are 'N' base flavors and 'M' toppings. Ninja has a target that he will be needing an 
amount of 'K' for making the dessert.

For making dessert, there are some basic rules:-
1. There should be exactly one base flavor.
2. Toppings can be one or more or none.
3. There are at most two toppings of each type.

Ninja wants to make a dessert with a total cost as close to the target price as possible.

You will be given an array/list flavor of size N representing the cost of each base flavor 
and another array/list toppings of size 'M' representing the cost of each topping and the target price.

Your task is to help Ninja to find the closest possible cost of the dessert to the target price 'K'. 
If there are multiple answers, return the lower one.

Example:- 
Let N = 2 , M = 2 , K = 10, FLAVOR = [1,7] , TOPPING = [3, 4] , K = 10

Here we can make a dessert with the base flavor of price 7 and adding 1 topping of price 3. 
Which will cost 7 + 3 = 10, which is exactly equal to k, so the closest possible price would be 10.


Input Format:-
The first line of input contains an integer 'T' denoting the number of test cases to run. 
Then the test case follows.

The first line of each test case contains an integer 'N' representing the number of base FALVOURS.

The second line of each test case contains 'N' integer representing the cost base FLAVOURS.

The third line of each test case contains an integer 'M' representing the number of TOPPINGS.

The second line of each test case contains 'M' integer representing the cost TOPPINGS.

The fifth and last line of each test case contains an integer 'K' representing the target price 
for dessert.


Output Format:- 
For each test case, print a single line containing a single integer denoting the closest 
possible price of the dessert to the target price.

The output of each test case will be printed in a separate line.
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int update(int old_amount, int target, int new_amount){
    if (abs(old_amount - target) > abs(new_amount - target)){
        old_amount = new_amount;

    }else if(abs(old_amount - target) == abs(new_amount - target)){
        old_amount = min(old_amount, new_amount);
    }

    return old_amount;
}

void closestCost_helper(vector<int> &toppingCosts, int m, int index, int &ans, int amount, int target){
    // Base Case
    if (index == m){
        ans = update(ans, target, amount);
        return;
    }

    // Main Code

    // Number of toppings = 0
    closestCost_helper(toppingCosts, m, index + 1, ans, amount, target);

    // Number of toppings = 1
    closestCost_helper(toppingCosts, m, index + 1, ans, amount + toppingCosts[index], target);

    // Number of toppings = 2
    closestCost_helper(toppingCosts, m, index + 1, ans, amount + (2*toppingCosts[index]), target);

}

int closestCost(int n, int m, vector<int> &baseCosts, vector<int> &toppingCosts, int target){
    int ans = INT_MAX;

    for (int i = 0; i < n; i++){
        int base_cost = baseCosts[i];
        closestCost_helper(toppingCosts, m, 0, ans, base_cost, target);
    }

    return ans;
}

class Runner
{
    int t;
    vector<int> n, m, target;
    vector<vector<int>> base, toppings;

public:
    void takeInput()
    {
        cin >> t;

        for (int i = 0; i < t; i++)
        {
            int N;
            cin >> N;
            n.push_back(N);

            vector<int> v;
            for (int j = 0; j < N; j++)
            {
                int B;
                cin >> B;
                v.push_back(B);
            }
            base.push_back(v);

            int M;
            cin >> M;
            m.push_back(M);

            vector<int> u;
            for (int k = 0; k < M; k++)
            {
                int top;
                cin >> top;
                u.push_back(top);
            }

            toppings.push_back(u);

            int tar;
            cin >> tar;

            target.push_back(tar);
        }
    }

    void execute()
    {
        vector<vector<int>> cpyB = base;
        vector<vector<int>> cpyT = toppings;

        for (int i = 0; i < t; i++)
        {
            int ans = closestCost(n[i], m[i], base[i], toppings[i], target[i]);
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            int ans = closestCost(n[i], m[i], base[i], toppings[i], target[i]);
            cout << ans << "\n";
        }
    }
};

int main()
{
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();
    return 0;
}
