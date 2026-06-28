// Stack impl: Same logic, idea is put EVERYTHING IN STACK.
// Pop two tops and ask if 1 knows 2 knows 1. 
// If 1 knows 2 and 2 knows 1 do not push anyonr
// If 1 knows 2 and 2 does not know 1: push 2 , remove 1 as it is never celeb.
// If 2   ''  1 ''  1  ''   ''  ''  2: push 1 , remove 2 as it is never celeb.

// If no one knows no one, remove both
// Stack empty means no celeb
// stack not empty means at least 1 person is there. It was checked against whoever was bellow/above him/
// But this is not definitive. We have found some instances that he does not know many people who knows him.
// We have to double down on this claim.




Goal is NOT to find the celebrity.

Goal is to eliminate non-celebrities.

One comparison should eliminate at least one candidate.


class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // Elimination problem
        
        int i=0, j=mat.size()-1;
        
        while(i<j){
            // What can we say?
            
            // We can not deterministically say who is CELIBRITY just by single checlking.
            
            // What we can do is: we can eliminate those who are not celebrity.
            
            // if ij = 1 then we are certain i knows j. So, i is NOT a celeb
            // Similarly, ji= 1 means j is NOT a celebrity.
            
            // if ij=0 we can not say anything directly it just says i does not know j.
            // We do not know j yet. if j also does not know i, i-j none of them are celen.
            // If j does know i, i can be a possible celeb. Because ij=0 ji=1 has to be for all j if i is a celeb. So we found only 1 instance of "One way knowing"
            // We can not eleminate i any more, but since j knows i, j is NEVER a celeb.
            
            // So deterministic check first. If i knows j then i++ (i eleminated)
            // If j knows i, j-- j eleminted.
            // If ij = 0, 1) if ji = 0 both are not celeb
            //            2) if ji = 1 i is a possible celeb. But j is not.
            // Notice: If i doesnt know j, j is not celebrity. Why, because everyone MUST know celeb.

            // if ij= 0, hold on to i
            // At every step someone is eleminated..
            // 0 0: surely j is not celebrity. So is i. This variation only eleminates one at a time. so j is not celeb j--
            // Whatever is about j: i does not know j. j is not celeb

            // 0 1: Again, idk j. but i does not know j, so j is not celeb.
            
            // 1 0: i knows j. So i is not celeb
            // 1 1: i knows j. So i is not celeb.

 
            if(mat[i][j] == 1) i++;
            else j--;


            // ======================================================
            // Only 4 combs possible: 00 01 10 11
            // if(mat[i][j] == 0 && mat[j][i] == 0){
            //     i++;
            //     j--;
            // }
            // else if(mat[i][j] == 0 && mat[j][i] == 1){
            //     // i is potential not j.
            //     j--;
            // }
            // else if(mat[i][j] == 1 && mat[j][i] == 0){
            //     i++;
            // }
            
            // else{ // ij = 1 and ji 1
            //     i++;
            //     j--;
            // }
            // ========================================================
        }
        
        // Now we do not know anything about this specific element.
        // We need to check : for all possible k: ik = 0 (unless i=k then 1) AND ki=1
        if(i==j){
            // This is where the loop may end. Other possibility is that i>j in that case weare certain there are no celeb
            for(j = 0; j<mat[0].size(); j++){
                if(i==j) continue;
                else{
                    if(mat[i][j] == 0 && mat[j][i] == 1) continue;
                    else return -1;
                }
            }
            
            return i;
        }
        else return -1;
        
    }
};