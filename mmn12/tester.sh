#! /bin/sh

echo  ==================================================
echo  "          magic.c Tester initiated!"
echo  ==================================================
echo
echo  ==================================================
echo  "  Making sure there is magic executable ready."
echo  ==================================================
file="./magic/magic"
if [ -f "$file" ]
then
  echo "$file found."
else
  echo "Not found, trying to 'make'"
  gcc -o ./magic/magic ./magic/magic.c -Wall -ansi -pedantic -I./magic/
  if [ ! $? ]
  then
    echo "Error: Could not automatically run 'make', aborting tester."
  else
    echo "magic executable has been created!" 
  fi
fi
echo
echo  ==================================================
echo  "               Testing matrix - 3"
echo  ==================================================
cat ./matrix3 | ./magic/magic
echo
echo
echo  ==================================================
echo  "               Testing matrix - 5"
echo  ==================================================
cat ./matrix5 | ./magic/magic
echo
echo
echo  ==================================================
echo  "               Testing matrix - 6"
echo  ==================================================
cat ./matrix6 | ./magic/magic
echo
echo
echo  ==================================================
echo  "               Testing matrix - 9"
echo  ==================================================
cat ./matrix9 | ./magic/magic
echo
echo
echo  ==================================================
echo  "     Testing matrix - 3 - Too many numbers"
echo  "           Last digit is another 9"
echo  ==================================================
cat ./matrix3_toomanyNum | ./magic/magic
echo
echo
echo  ==================================================
echo  "     Testing matrix - 5 - Too many numbers"
echo  "        There is many numbers, and a 26"
echo  ==================================================
cat ./matrix5_bad_too_many_and_number26 | ./magic/magic
echo
echo
echo  ==================================================
echo  "     Testing matrix - 6 - same number twice"
echo  "        Same number goes twice, number 22"
echo  ==================================================
cat ./matrix6_sameNum_twice22 | ./magic/magic
echo
echo
echo  ==================================================
echo  "     Testing matrix - 9 - One number is missing"
echo  "        	Number 8 is missing"
echo  ==================================================
cat ./matrix9_lessNum_no_8 | ./magic/magic
echo
echo
echo  ==================================================
echo  "     Testing matrix - 3 - Not Int, float"
echo  "        	Last number is 1.1"
echo  ==================================================
cat ./matrix3_NotInt | ./magic/magic
echo
echo
echo  ==================================================
echo  "     Testing matrix - 3 - Not Int, char"
echo  "        	Last number is a char"
echo  ==================================================
cat ./matrix3_aLetter | ./magic/magic
echo
echo
echo  ==================================================
echo  "     Testing matrix - 11"
echo  "       Outside Scope"
echo  ==================================================
cat ./matrix11_outsideScope | ./magic/magic
echo
echo
echo  ==================================================
echo  "          Testing is done, that is all."
echo  ==================================================
