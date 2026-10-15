# Assignment5
An Artifical Idiot For Assignment 5 of Programming Techniques II

## Description of Code
The software trains itself of a provided textfile, and records the frequency of character sets of size k (also provided as an arguemnt), known as kgrams, it then generates new text based on the number of characters desired (another argument). It generates this text using the relative weightings of a kgram, to generate a starting kgram known as $w$, where $w=w_1w_2..w_k$, with $w_i$, representing the $i$th character. The first character, $w_1$, of $w$ is removed, and then depending on a distribution $P(c|w)$, a new character $c$ is generated and appended to the kgram such that $w = w_2w_3....w_kc$, a new character is generated according to $P(c|w)$, $c_2$ and appended to $w$, so we get $w = w_2w_3....w_kcc_2$, and so on until the length of the generated text is that which is desired. $P(c|w)$ by default or if the argument for $\alpha$ is provided as 0, is the probability of a given character $c$, following kgram $w$, and is calculated as $$P(c|w) = \frac{n(w,c)}{\sum_c n(w,c)},$$ where $n(w,c)$ is the number of times $c$, follows $w$. Alterantively when $\alpha > 0$, $P(c|w)$ is instead calculated with a pseudocount to allow for unseen kgrams to be generated, thus $P(c|w)$ is now $$P(c|w) = \frac{n(w,c) + \alpha}{(\sum_c n(w,c)) + \alpha |\Sigma|},$$ where $|\Sigma|$ is the size of set of all distinct characters observed in the training set.


## How to Run
### Compiling
run the Makefile using "make" from the project directory, to compile the program.

### Running the Program
then slm can be run using:
./slm [k] [input_file_name.txt] [length]

where:

- [k] - int - [k] $> 1$ - the size of the kgrams the training file is divded into
- [input_file_name.txt] - string - the path to the training file
- [length] - int - [lenght] $\ge$ [k] the number of characters long the generated text will be

Example:

./slm 3 TrainingFiles/moby_dick.txt 10

This will generate 10 characters using 3 character long kgrams based on moby_dick.txt


Clean Up:
To remove generated files after usage use command:
make clean

### Arguments
The program can take in an argument to set $\alpha$ to be non-zero, if $\alpha > $ the program will then run with a pseudcount.
-a [alpha]
- [alpha] - float - [alpha]$\ge 0$ - the value of $\alpha $ to use in pseudocounts

Example: 

./slm -a 1 3 TrainingFiles/moby_dick.txt 10

This will generate 10 characters using 3 character long kgrams based on moby_dick.txt, with a pseudocount that has Laplace smoothing.

$\alpha = 0.3$ obtains effective results

## Dependencies

- iostream
- unistd.h
- map
- random
- fstream