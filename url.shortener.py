
import random
import string

short_to_long = {}
long_to_short = {}

def generate_code(): #function definition
  characters = string.ascii_lowercase + string.digits  #all lowercase alphabets
  #plus all digit 0-9
  code = ''.join(random.choices(characters, k = 6)) #for random 6 strings out of all in characters
  return code

def shorten(url):
  if url not in long_to_short: #new url , not in map
    code = generate_code()     #generate code
    long_to_short[url] = code  #assign to key url
    short_to_long[code] = url  #assign value to key code
    return code
  else:
    return long_to_short[url]

def expand(code):
  if code in short_to_long:
    return short_to_long[code]
  else:
    return "Code not found"

def main():
  while True:
    print("\nMenu:")
    print("1. Shorten URL")
    print("2. Expand Code")
    print("3. Exit")

    option = int(input("Enter your choice:"))

    if option == 1:
      url = input("Enter the URL to shorten:")
      print("Shortened code:" , shorten(url))

    if option == 2:
      code = input("Enter the code to expand:")
      print("Expanded URL:" , expand(code))

    if option == 3:
       break

main()

