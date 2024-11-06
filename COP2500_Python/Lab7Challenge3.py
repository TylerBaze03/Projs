<<<<<<< HEAD
# Tyler Bazemore
# Petey Message Decoder
# Decodes the message
def decrypt(message, key):
    LETTERS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    translated = ""
    
    for letter in message:
        if letter in LETTERS:
            value = chr((ord(letter) - ord('A') - key) % 26 + ord('A'))
            translated += value
        else:
            translated += letter
            
    return translated
def main():
    # Welcome Message
    print("Welcome to the Petey Message Decoder")
    print("------------------------------------")
    print("We will be trying to decode messages from Petey.")
    # TODO: Open Files
    fr=open("encodedmsg.txt", "r")
    fw=open("answer.txt", "w")
    
    for l in range(24):
        # TODO: Read from file, decypt, and write files. 
        line = fr.readline()
        decrypted_line = decrypt(line, 8)
        fw.write(decrypted_line)
    # TODO: Close Files
    fr.close()
    fw.close()
    
    print("----------------------------")
    print("Done")
    
main()


=======
# Tyler Bazemore
# Petey Message Decoder
# Decodes the message
def decrypt(message, key):
    LETTERS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    translated = ""
    
    for letter in message:
        if letter in LETTERS:
            value = chr((ord(letter) - ord('A') - key) % 26 + ord('A'))
            translated += value
        else:
            translated += letter
            
    return translated
def main():
    # Welcome Message
    print("Welcome to the Petey Message Decoder")
    print("------------------------------------")
    print("We will be trying to decode messages from Petey.")
    # TODO: Open Files
    fr=open("encodedmsg.txt", "r")
    fw=open("answer.txt", "w")
    
    for l in range(24):
        # TODO: Read from file, decypt, and write files. 
        line = fr.readline()
        decrypted_line = decrypt(line, 8)
        fw.write(decrypted_line)
    # TODO: Close Files
    fr.close()
    fw.close()
    
    print("----------------------------")
    print("Done")
    
main()


>>>>>>> b756d6d (Updating repositroy using git)
