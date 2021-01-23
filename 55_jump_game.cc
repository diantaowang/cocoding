#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize)
{
    bool stop_jump = 0, can_jump = 1;
    int left = 0, right = 0;
    while (!stop_jump) {
        int max_pos = 0;
        for (int i = left; i <= right; ++i) {
            if (i + nums[i] > max_pos)
                max_pos = i + nums[i];
        }
        if (max_pos >= numsSize - 1) {
            stop_jump = 1;
            can_jump = 1;
        } else if (max_pos <= right) {
            stop_jump = 1;
            can_jump = 0;
        } else {
            left = right + 1;
            right = max_pos;
        } 
    }
    return can_jump;
}

int main()
{
    return 0;
}
