Copilot Denoise
===============================

To Compile:
===============================
g++ src/main.cpp -o denoise

To Run:
===============================
./denoise tests/noisy_small.txt clean.txt mean 2 

this is for the small noisy file. to use any other file, change the file name to text/"file name". 
The command line works as follows: denoise <input.txt> <output.txt> <filter (where the filter is mean)> <iterations>

The program works/denoises by taking the average of the 8 numbers around the spike and then changing the spike to be that average which smooths out the image.


Here are some tests and results:
=================================
Small: 
input:
6 8
50 52 49 51 53 50 48 52
51 200 52 49 50 51 54 49
49 50 48 0 52 53 51 50
52 49 51 53 50 255 49 52
50 51 52 49 50 51 53 48
49 52 50 51 49 52 50 51

output: 
6 8
67 66 60 54 50 50 51 51
67 66 59 55 53 57 56 53
61 59 54 54 57 64 61 56
56 55 52 56 63 72 66 58
50 50 49 54 59 65 61 55
50 51 51 53 55 58 56 53

=====================================================
Salt and pepper:
input:
 10 10
120 120 120 120 120 120 120 120 120 120
120 120 120 120   0 120 120 120 120 120
120 120 255 120 120 120 120 120 120 120
120 120 120 120 120 120 255 120 120 120
120   0 120 120 120 120 120 120 120 120
120 120 120 255 120 120 120 120   0 120
120 120 120 120 120 120 120 255 120 120
120 120 120 120 120   0 120 120 120 120
120 255 120 120 120 120 120 120 120 120
120 120 120 120 120 120 120 120 120 255

output:
10 10
122 123 121 115 109 111 116 120 120 120
123 127 126 118 112 115 121 123 122 120
121 126 129 123 120 121 127 127 123 120
115 120 126 126 127 129 132 127 121 116
109 114 123 129 132 132 130 126 118 113
111 116 124 131 129 127 124 123 115 110
121 124 127 127 121 120 121 126 121 116
130 132 130 124 115 112 117 124 127 127
135 135 130 122 114 113 118 127 138 147
135 135 130 124 117 116 117 127 145 162

=====================================================
edge:
input: 
5 5
255  10  10  10  10
 10  10  10  10  10
 10  10  10  10  10
 10  10  10  10  10
 10  10  10  10   0

output:
5 5
85 55 25 10 10
55 37 19 10 10
25 19 13 10 9
10 10 10 9 8
10 10 9 8 7

=====================================================

For more information about testing, please refer to TESTING.md

In the program, I used copilot for the majority structure which helped me understand exactly what I needed to do for the program and how it worked. I also used copilot and had it explain to me the logic behind the program and how it should work. For example, I had copilot explain to me how the mean method of denoising worked. I then implemented the mean denoising method with the help of copilot where it helped me code some of the structural parts and helped me used the included libraries which I am not familiar with. I also used copilot to help me write the code for creating the text file where the final clean denoised image would be. Through this, I learned that to make a text file, you need to use out instead of cout as cout would just output this into the terminal. For the rest of the program, I wrote some of it with copilot helping correct mistakes and use libraries that are included which I a not familiar with. I also used copilot to help me code alot of the main program where it used things such as try and catch loops. it is worth noting tha copilot used cerr for alot of the cout statements. Finally, I used copilot to generate a small noisy text file to test the program. one bug that copilot missed it used a different variable name that I had or I had changed the variable name but it was still using the old name. I fixed this by simply reading through the code and changing it to the correct one.