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
