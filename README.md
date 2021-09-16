# I'm Making a Cool Parser

Just for fun

## functionality

run the executable with the input file as the only arg.
e.g.  './run input.txt'



TODO
 - maybe i shouldn't split strs and ints by token, in the case of
   hex things like hex values and mem addresses? maybe i could use
   an escape char or something that sets contFlag to 3 which means
   to continue even over interchanging chars, such as the case 
   of making a string inside quotes.
