#! /bin/bash

# syntax: variable=value

a=z                     # Assign the string "z" to variable a.
b="a string"            # Embedded spaces must be within quotes 
c="a string and $b"     
d="$(ls -l foo.html)"    # Result of a command
e=$((5*7))              # Arithmetic expansion
f="\t\ta string\n"      # Escape sequences such as tabs and newlines

echo $f