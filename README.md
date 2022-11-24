# XOR-Crypting-in-C++
This C++ project is managing a small team of computer science students(at most 10 people).To protect their name and id,this program is encrypting their data with the following rules:the name is reverted and the id is encoded with 2 keys(the primary key and the secondary key).The primary key means how many bit flips will be done(to the right) and,then,the result will be XORed with the secondary key.
This being said,here is how to run and use this program:
-First,you need to create 2 text files in the same diretory with the executable file,called "encoded_data" and "decoded_data".Then you need tocomment the last function(decode_data()) and run the program.
-You will insert from standard input the number of students in your team(at most 10),the id(at most 9) and the name for each student,and the data will be encoded and written in the "encoded_data" file
-Then,you need to comment the first 3 functions and uncomment the last one.Run the program again and you will see the original data again!
-Pay attention!After running the first part,all the data will be lost and stored (in the crypted form) in "encoded_data" file.The last function is decoding the data from this file,using the reverse process of the encoding and prints in the "decoded_data" file.
-The format of the crypted information of a student may look like this:[reversed_name]x[encoded_id][primary_key][secondary_key]
