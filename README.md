# DNA_alignment

## Description
Finds the optimal alignment for two DNA sequences of arbitrary lengths. This was done by measuring the similarity between two DNA sequences, by calculating their edit distances. In calculating the edit distance, we align the two strings and insert gaps, align two characters that match, and align two characters that mismatch. When inserting a gap there is a cost of 2, to align two characters that mismatch there is a cost of 1, and 0 if they already match. After the alignment is calculated we then use the Needleman-Wunsch method to go backwards thorugh the matrix to recover the optimal alignment. Then we align the two strings of DNA based on their optimal alignment. 

## Acknowledgements
<https://www.youtube.com/watch?v=18vt6k-2Jbs&ab_channel=AshokKumarT>
<https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html>
