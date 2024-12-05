#include <ArraysHashingSolutions.h>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>

bool ArraysHashingSolutions::containsDuplicate(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] == nums[i - 1]) {
            return true;
        }
    }
    return false;
}

bool ArraysHashingSolutions::isAnagram(std::string s, std::string t) {
    std::sort(s.begin(), s.end());
    std::sort(t.begin(), t.end());
    return s == t;
}

std::vector<int> ArraysHashingSolutions::twoSum(std::vector<int> &nums, int target) {
    std::vector<int> newVector;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (nums[i] + nums[j] == target) {
                newVector.push_back(i);
                newVector.push_back(j);
            }
        }
    }
    return newVector;
}

std::vector<std::vector<std::string> > ArraysHashingSolutions::groupAnagrams(std::vector<std::string> &strs) {
    std::unordered_map<std::string, std::vector<std::string> > groups;

    for (const auto &str: strs) {
        std::string sortedWord = str;
        std::sort(sortedWord.begin(), sortedWord.end());
        groups[sortedWord].push_back(str);
    }

    std::vector<std::vector<std::string> > result;
    result.reserve(groups.size());
    for (const auto &[fst, snd]: groups) {
        result.push_back(snd);
    }

    return result;
}

std::vector<int> ArraysHashingSolutions::topKFrequent(std::vector<int> &nums, int k) {
    std::unordered_map<int, int> map;
    for (auto &value: nums) {
        map[value]++;
    }
    std::vector<std::pair<int, int> > freqList(map.begin(), map.end());
    std::sort(freqList.begin(), freqList.end(), [](const auto &a, const auto &b) {
        return a.second > b.second;
    });
    std::vector<int> result;
    result.reserve(k);
    for (int i = 0; i < k; ++i) {
        result.push_back(freqList[i].first);
    }

    return result;
}

std::vector<int> ArraysHashingSolutions::productExceptSelf(std::vector<int> &nums) {
    std::vector result(nums.size(), 1);
    int left = 1;
    for (int i = 0; i < nums.size(); ++i) {
        result[i] = left;
        left *= nums[i];
    }
    int right = 1;
    for (int i = nums.size() - 1; i >= 0; --i) {
        result[i] *= right;
        right *= nums[i];
    }

    return result;
}

int ArraysHashingSolutions::longestConsecutive(std::vector<int> &nums) {
    if (nums.empty()) {
        return 0;
    }
    std::unordered_set numSet(nums.begin(), nums.end());
    int maxLength = 0;
    for (int num : numSet) {
        if (numSet.find(num - 1) == numSet.end()) {
            int currentNum = num;
            int currentLength = 1;
            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum++;
                currentLength++;
            }
            maxLength = std::max(maxLength, currentLength);
        }
    }

    return maxLength;

}
