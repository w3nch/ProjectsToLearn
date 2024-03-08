import random
import string
import secrets
import hashlib

def generate_key(passphrase, chars):
    # Generate a cryptographic hash of the passphrase
    hash_value = hashlib.sha256(passphrase.encode()).digest()
    # Shuffle the characters using the hash value as a seed
    random.seed(hash_value)
    key = chars.copy()
    random.shuffle(key)
    return key

chars = " " + string.punctuation + string.digits + string.ascii_letters

# Get passphrase from user
passphrase = input("Enter passphrase: ")

# Generate key from passphrase
key = generate_key(passphrase, list(chars))

# Create a dictionary for index lookup
index_lookup = {char: index for index, char in enumerate(chars)}

print(f"chars: {chars}")
print(f"key: {key}")

# ENCRYPT
plain_text = input("Enter Message: ")
cipher_text = "".join(key[index_lookup[letter]] for letter in plain_text)

print(f"Original Message: {plain_text}")
print(f"Encrypted Message: {cipher_text}")
