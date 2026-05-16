
class Solution {

public:

    int totalFruit(vector<int>& fruits) {

        std::vector<int> arr(100001,0);

        int i = 0, j = 0, d_fruit = 0, maxNum = 0, size = (int)fruits.size();

        while (j < size) // Processing current element

        {

            // If new fruit not present in array, increment d_fruit by 1

            if (arr[fruits[j]] == 0) {

                d_fruit++;

            }

            arr[fruits[j]]++; // Aage barale notun fruit hole songe songei ++

                            // hoto, tahole arr[nums[j]] kokhonoi 0 hoto na due

                            // to ++.


            while (d_fruit > 2) // If and while mixed

            {

                // Reduce its frequency by 1

                arr[fruits[i]]--;

                if (arr[fruits[i]] == 0)

                    d_fruit--; // if arr[..]=0, its freq reached 0 means it no

                               // ponger exists

                i++;

            }

            maxNum = std::max(j - i + 1, maxNum);

            j++;

        }

        return maxNum;

    }

};
