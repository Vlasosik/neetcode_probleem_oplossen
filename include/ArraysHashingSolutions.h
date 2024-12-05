#ifndef ARRAYSHASHINGSOLUTIONS_U
#define ARRAYSHASHINGSOLUTIONS_U
#include <vector>

class ArraysHashingSolutions {
public:
    static bool containsDuplicate(std::vector<int> &nums);

    static bool isAnagram(std::string s, std::string t);

    static std::vector<int> twoSum(std::vector<int> &nums, int target);

    static std::vector<std::vector<std::string> > groupAnagrams(std::vector<std::string> &strs);

    static std::vector<int> topKFrequent(std::vector<int> &nums, int k);

    static std::vector<int> productExceptSelf(std::vector<int> &nums);

    static int longestConsecutive(std::vector<int> &nums);
};
#endif //ARRAYSHASHINGSOLUTIONS-U
