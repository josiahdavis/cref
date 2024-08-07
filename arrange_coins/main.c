#include <stdio.h>

/*
How many complete rows of stairs could we create from n coins? 
    Example: 
    If we have 10 coins (n=10) we could create four complete rows of stairs.
    # 
    # # 
    # # # 
    # # # # 

Reframe the stair-steps as series of integers: 1 + 2 + 3 + 4 = 10

Exploit symmetry. Quick solve using guassian sum/folding: total = (n + 1) * (n / 2)

Translation: coins needed to achieve a specified number of rows:
    coins_needed = (rows + 1) * (rows / 2)

Solve using binary search: Number of possible rows is bounded by 1 and number of coins available n.
*/

int max(int a, int b)
{
    return a > b ? a : b;
}

int arrangeCoins(int n) {
    // n = coins available to build our staircase
    long left = 1;
    long right = n;
    long res = 0;
    long mid;
    double coins_needed;

    while (left <= right) {

        // find midpoint (keep as integers to round down)
        mid = (left + right)/2;

        // calculate how many coins we need for "mid" number of complete rows using gauss formula
        coins_needed = ((double)mid / 2) * (mid + 1);
        printf("left=%-10lu right=%-10lu -> mid=%-10lu -> needed=%-25.0f", left, right, mid, coins_needed);

        // update range of possible values for next search
        if (coins_needed > n) {
            printf(" -> going left\n");
            // need more coins than we have, truncate out the right side
            right = mid - 1;
        } else {
            printf(" -> going right");
            // have enough coins, truncate out the left side and update our max rows tracker 
            left = mid + 1;
            res = max(res, mid);
            printf(" -> num stairs=%-7li\n", res);
        }
    }
    printf("With %i total coins, you can create %lu complete rows\n", n, res);
    return res;
}

int main()
{
    arrangeCoins(4); // 2
    arrangeCoins(5); // 2
    arrangeCoins(8); // 3
    arrangeCoins(100); // 13
    arrangeCoins(2146467960); // 65520
    return 0;
}