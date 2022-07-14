
frequencies = {'A': 0, 'B': 0, 'C': 0, 'D': 0, 'E': 0, 'F': 0, 'G': 0, 'H': 0, 'I': 0, 'J': 0, 'K': 0, 'L': 0, 'M': 0, 'N': 0, 'O': 0, 'P': 0, 'Q': 0, 'R': 0, 'S': 0, 'T': 0, 'U': 0, 'V': 0, 'W': 0, 'X': 0, 'Y': 0, 'Z': 0}

data = (input("Code to analize: ")).replace(" ", "")
for i in data:
    frequencies[i] += 1

frequency = "".join(list(dict(sorted(frequencies.items(), key=lambda x: x[1])).keys())[::-1])


engligh_freq_1 = "ETAOINSHRDLCUMWFGYPBVKJXQZ"
engligh_freq_2 = "EQTSORINHCLDUPMFWGYBKVXQJZ"

print("\nfrequency dic created: ", frequency, "\n")

while True:
    cipher_txt = input("Text to decrypt: ")
    dec_1 = ""
    dec_2 = ""
    for lt in cipher_txt:
        try:
            dec_1 += engligh_freq_1[frequency.index(lt)]
            dec_2 += engligh_freq_2[frequency.index(lt)]
        except:
            dec_1 += lt
            dec_2 += lt
    print("Decrifrado 1: ", dec_1)
    print("Decrifrado 2: ", dec_2, "\n")
