import nltk 

with open("./data/word_list_MIT.txt", 'r') as in_file:
    words = in_file.readlines()
words_for_pos = []

for i in words:
    words_for_pos.append(i[0:-2])

with open("words_pos.txt", 'w') as output_file: 
    pos_words = nltk.pos_tag(list(tuple(words_for_pos)))
    
    for i in pos_words:     
        for j in i:
            output_file.write(j + " ")
        output_file.write("\n")

output_file.close()
in_file.close()