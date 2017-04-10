int findPivot(int* nums, int lo, int hi) {
    // If low is greater than high, then the array is not rotated at all
    if(lo > hi) {
        return 0;
    }
    
    // If only one element remaining in the search set, return that element
    if(lo == hi) {
        return lo;
    }
    
    int mid = lo + (hi - lo) / 2;
    if(mid > lo && nums[mid] < nums[mid - 1]) {
        return mid;
    }
    
    if(mid < hi && nums[mid + 1] < nums[mid]) {
        return (mid + 1);
    }
    
    if(nums[mid] < nums[hi]) {
        return findPivot(nums, lo, mid - 1);
    }
    
    if(nums[mid] > nums[hi]) {
        return findPivot(nums, mid + 1, hi);
    }
}

int searchUtil(int* nums, int lo, int hi, int target) {
    if(lo > hi) {
        return -1;
    }
    
    int mid = lo + (hi - lo) / 2;
    if(nums[mid] == target) {
        return mid;
    }
    
    else if(nums[mid] < target) {
        return searchUtil(nums, mid + 1, hi, target);
    }
    
    else if(nums[mid] > target) {
        return searchUtil(nums, lo, mid - 1, target);
    }
}

int search(int* nums, int numsSize, int target) {
    int pivot = findPivot(nums, 0, numsSize - 1);

    if(nums[pivot] == target) {
        return pivot;
    }
    
    else if(nums[0] <= target && pivot != 0) {
        return searchUtil(nums, 0, pivot - 1, target);
    }
    
    else if(nums[0] > target && pivot != 0) {
        return searchUtil(nums, pivot + 1, numsSize - 1, target);
    }
    
    else if(pivot == 0) {
        return searchUtil(nums, 0, numsSize - 1, target);
    }
}