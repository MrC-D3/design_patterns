// Given two integer arrays nums1 and nums2, return the maximum length of a 
//  subarray that appears in both arrays.
// Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7] Output: 3
//  Explanation: The repeated subarray with maximum length is [3,2,1].
// ****************************************************************************
// Ridondanza: Nota che quando confronti nums1[i:i+k] con nums2[j:j+k], poi 
//  confronti nums1[i+1:i+1+k] con nums2[j+1:j+1+k]. C'è del lavoro che stai 
//  ripetendo?
// Memorizzazione: Se sapessi già la lunghezza del sottoarray comune più lungo 
//  che inizia da nums1[i+1] e nums2[j+1], potresti usare questa informazione 
//  per calcolare quello che inizia da nums1[i] e nums2[j]?
// Approccio bottom-up: Invece di partire dall'inizio degli array e andare 
//  avanti, cosa succederebbe se partissi dalla fine e andassi indietro?
// Prova a pensare a una tabella 2D dove dp[i][j] rappresenta la lunghezza del 
//  sottoarray comune più lungo che inizia esattamente a nums1[i] e nums2[j]. 
//  Che relazione ci sarebbe tra dp[i][j] e dp[i+1][j+1]? 
//  dp[i][j] = 1 + dp[i+1][j+1].
// ****************************************************************************
// Hai davvero bisogno di mantenere tutta la matrice indexed_subarrays in 
//  memoria? Quando calcoli la riga i, di quali righe precedenti hai ancora 
//  bisogno? Potresti usare solo due righe invece di tutta la matrice? O magari 
//  anche meno di due righe?
// Dato che stai andando da destra-basso verso sinistra-alto, e ogni cella 
//  dipende solo dalla cella diagonale in basso a destra, prova a pensare se 
//  puoi usare un singolo array 1D invece di una matrice 2D. E in che direzione 
//  dovresti riempire questo array per evitare di sovrascrivere valori di cui 
//  hai ancora bisogno

#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

class Solution 
{
public:
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        vector<int> prev_line(nums2_size, 0);
        int result = 0;

        // Process.
        for (int i = 0; i < nums1_size; i++)
        {
            for (int j = nums2_size - 1; j > 0 ; j--)
            {
                if (nums1[i] == nums2[j])
                {
                    prev_line[j] = 1 + prev_line[j-1];

                    if (result < prev_line[j])
                    {
                        result = prev_line[j];
                    }
                }
                else
                {
                    prev_line[j] = 0;
                }
            }

            prev_line[0] = 0;
            if(nums1[i] == nums2[0])
            {
                prev_line[0] = 1;
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    vector<int> nums1{1, 2, 3, 2, 1};
    vector<int> nums2{3, 2, 1, 4, 7};
    auto result = s.findLength(nums1, nums2);

    cout << "Result: " << result << endl;

    return 0;
}