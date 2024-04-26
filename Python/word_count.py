def count_freq(path):
    
    obj = {}
    
    with open(path,'r') as file:
        
        lines = file.readlines()
        
        for line in lines:
            words = line.strip().split()
            
            for word in words:
                
                word = word.strip('.,!?;:()[]{}"\'').lower()
                
                if word and word not in obj:
                    obj[word] =1
                else:
                    obj[word] +=1
    return obj

file_path = 'example.txt'  # Replace 'example.txt' with the path to your text file
word_freq = count_freq(file_path)

# Print the word frequencies
print("Word Frequencies:")
for word, freq in word_freq.items():
    print(f"{word}: {freq}")
                    
    