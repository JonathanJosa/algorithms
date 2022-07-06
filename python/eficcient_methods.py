def count_bits(n):
    return n.bit_length()

def base_conversion(n, x):
    return "%x" % int(n, x)

def same_border_list(a):
    res = a[:]
    while res and res[0] != res[-1]:
        _, *res, _ = res
    return res

import textwrap
def wrap_text(feedback, size):
    return textwrap.wrap(feedback, width=size, replace_whitespace=True)

def palindrome(word):
    return word == word[::-1]

def capital(message):
    return message.capitalize()

def cipher_translate(password, key):
    return password.translate(str.maketrans(string.ascii_lowercase, key))

def decimalPrecision_stringWidth(t, width, precision):
    return ('{0:^{1}.{2}f}').format(t,width,precision)

#s = "%d%d%%-growth in products is expected quite soon"
#s = "New style formatting (like %s) is waay cooler than old-style (i.e. %s)"
def string_format(s):
    return '%'.join(re.sub('%\w', '{}', part) for part in s.split('%%'))

def remove_substring_init(commit):
    return re.sub('[0\?\+\!]*', '', commit)

def sub_odds_index(students):
    return sum(students) - sum(students[1::2])

def print_list(lst):
    return f'Integer array format: {lst}'

def vacuum_permittivity():
    return 8.854e-12
