# Parabolic-Encryptor

A C project made as a part of the Secure Programming with C course (UE18CS257C) course at PES University to demonstrate static code
analysis. The objective of the project was to find and display the effects of vulnerabilities in the C programming language and
the necessary steps required to prevent such errors in product development.

Created and tested on Linux Environment :)

# Encryption Algorithm

The project implements the parabolic encryption algorithm, which takes in a string input, converts each character of the string 
into some another based on the equation of an upward parabola: <code>y<sup>2</sup> = 4ax</code>, where x is the index of that particular input character, 
a is a the encryption distance calculated during runtime and y is the function of x, which is added to the ASCII value of the original 
character to get the encrypted character.

Similarly, the decryption algorithm takes in the encrypted string obtained using the above encryption algorithm, 
applies the inverse function of the parabola function : ```x = -√4ay```  on each character of the string, where y is the index of the 
encrypted input character, a is the same encryption distance as before and x is the function of y, which is added to the ASCII value 
of the encrypted character to get the decrypted character.


# Compilation 
Compile the corresponding Main and Dependency files to create the outfile.

To compile the source code with vulnerabilities, use 

```gcc Main-vulnerable.c Dependencies-vulnerable.c -lm```

To compile the secure file, use

```gcc Main-secure.c Dependencies-secure.c -lm```

While executing the outfile, the input text can either be -

* provided at runtime after executing with ```./a.out```
* or passed as input redirection using ```./a.out < Document.txt```
