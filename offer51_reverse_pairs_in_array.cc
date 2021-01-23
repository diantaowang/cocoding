#include <stdio.h>
#include <sys/cdefs.h>
#include <stdlib.h>

int countReversePairs(int* nums, int begin, int end, int* tmp) {
    int median, left_pairs, right_pairs;
    if (begin == end - 1)
        return 0;
    median = (begin + end) / 2;
    left_pairs = countReversePairs(nums, begin, median, tmp);
    right_pairs = countReversePairs(nums, median, end, tmp);
     
    int left_array_pos = begin, right_array_pos = median, tmp_pos = 0;
    int reverse_pairs = 0;
    while (left_array_pos != median && right_array_pos != end) {
        if (nums[left_array_pos] > nums[right_array_pos]) {
            tmp[tmp_pos++] = nums[left_array_pos++];
            reverse_pairs += end - right_array_pos;
        } else {
            tmp[tmp_pos++] = nums[right_array_pos++];
        } 
    }
    for (int i = right_array_pos; i < end; ++i)
        tmp[tmp_pos++] = nums[i];
    for (int i = left_array_pos; i < median; ++i)
        tmp[tmp_pos++] = nums[i];
    for (int i = begin, j = 0; i < end; ++i, ++j)
        nums[i] = tmp[j];
    return reverse_pairs + left_pairs + right_pairs;
}

int reversePairs(int* nums, int numsSize)
{
    if (numsSize == 0)
        return 0;
    int* tmp = (int*)malloc(numsSize * sizeof(int));
    int num = countReversePairs(nums, 0, numsSize, tmp);
    free(tmp);
    return num;
}

