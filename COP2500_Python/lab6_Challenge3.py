# Tyler Bazemore
# Cop2500 0v64
# Lab 6 Challenge 3
# Oct 13, 2022
fight_song = ("UCF charge onto the field. With our spirit, we’ll never yield. Black and gold, Charge right through the line. Victory is our cry, V-I-C-T-O-R-Y. Tonight our Knights will shine!")
def knight_check(word):
    if word in fight_song:
        return True
    else:
        return False
print(knight_check("in"))
