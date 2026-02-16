To run the tests, you have to use the command line as follows: 

./denoise <input.txt> <output.txt> mean <iterations> 

some example/sample tests are as follows:

edge:
./denoise tests/noisy_edge.txt clean_edge.txt mean 2

salt and pepper:
./denoise tests/noisy_salt_pepper.txt clean_salt_pepper.txt mean 2

small matrix:
./denoise tests/noisy_small.txt clean_small.txt mean 2


where the input txt is whatever text file you want you input, output is the name of the textfile you want to output and the iteration is how many iterations you want the program to run, this will determine how smooth the resultant output is.