#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// problem identify 
// arrr/string + subarray/substring+ K(window_size)  -- Question me esa kuch mile iska matlab yhi h ki sliding window approach se hi hoga;
// window size-- two types - 1) fix  -given in question
//                           2) variable window size- asked in question (largest or smallest window nikalo subjected to a condition);
// fixed window - maximum sum subarray of size k;
// variable - find largest subarray whose sum is 5; 
//fixed window size wale question Ezz rhte h level me;
// varibale size wale thode difficult hote h ; //isme map wgera ka use ho skta h;
// is series ke bad sare concept clear ho janege bhaisaab --
// thoda phle coding suru krta to shyd m goggle woggle me chla jata ab to koi thik thak comapny me placed hone pdega aaj 13/8/22 ho gye h 
// mid oct me placement start honge , thoda dr to lg rha h bhaisaab ;

// we wiil discuss here total 10 problem , 5 on fixed & 5 on variable window;




// FIxed-
// 1)Max/Min subarray of size K;
// 2) 1st -ve in every window of size k 
// 3)count occurance of anagram 
// 4)max of all subarray of size k;
// 5)max of min of every window size;

// Variable 
// 1) longest/smallest subarray of sum k 
// 2) longest subarray/sub string of k distinct
// 3) length of longest substring No repeated character
// 4) Pick toy 
// 5) Minimum substring Window   // most important/ Hard problem of sliding window ---