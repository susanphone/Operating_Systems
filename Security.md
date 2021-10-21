# Security
# Diffie-Hellman Key Exchange Algorithm
* Def: g is a primitive root modulo n iff g is a generator of the multiplicative group of integers modulo n
## Example:
    
    g = 3, n = 7
    3^1 = 3 -> 3 mod 7
    3^9 = 9 -> 2 mod 7 -> 3^1 * 3 -> 2 mod 7
    3^3 = 27 -> 6 mod 7 -> 3^2 * 3 -> 2*3 mod 7 -> 6 mod 7
    3^4 = 81 -> 4 mod 7 -> 3^3 8 3 -> 6 * 3 mod 7 -> 4 mod 7
    3^5 = 243 -> 5 mod 7 -> 3^4*3 -> 4*3 mod 7 -> 5 mod 5
    3^6 = 729 -> 1 mod 7 -> 3^5 *3 -> 5*3 mod 7 -> 1 mod 7
    3^7 = 2187 -> 3 mod 7
    326451 pattern will repeat
* **In design algorithms, g and n should be prime numbers**
* Ralph Merkle, 1975
* Diffie-Hellman, 1976 -> Turing Award
* US PAtents: Hellman, Diffie, Merkle (inventors)
* 1997, declassified info: Ellis, Fox, and Williamson did it as classified work 1969 - 1973

## Algorithm
1. Alice, Bob pick p = 23, 9 = 5 (g is a primitive root modulo 23)
    * P and g could be known to Eve , the eavesdropper
2. Alice chooses a secret integer -> a =4, then sends $A=g^a mod P = 5^4 mod 23 = 4$
    * A- ALice's public key
3. Bob chooses a secret integer b = 3, then he sends $B = g^b mod P = 5^3 mod 23 = 10$ to Alice
    * B - Bob's public key
4. Alice computes $s = B^a mod P = 10^4 mod 23 = 18$
5. Bob computes $s = A^b mod P = 4^3 mod 23 = 18
    * S would only be known to Alice and Bob, with no communication over internet
6. Alice and Bob shares a secret key 18.
* Proof Sketch:

        A^b mod P = g^ab mod P
            = B^a mod P
* In practice, P must be very large

### Example: 

    5 is a multiplicative root modulo 23
    5^1 = 5 mod 23
    5^2 -> 5^1 * 5 mod 23 -> 2 mod 23
    5^3 -> 5^2 * 5 mod 23 -> 10 mod 23
    5^4 -> 5^3 * 5 mod 23 -> 10 * 5 mod 23
    5^5 -> 5^4 * 5 mod 23 -> 20 mod 23



# In class example

    P = 23
    g = 5
    Alice selects a = 6
    Bob selects b = 15
    A?
    B? 
    S?
    g^ab mod P
    Alice: 
        A = 5^6 mod 23 = 8 to Bob
    Bob:
        B = 5^15 mod 23 = 19 to Alice
    
    Alice's S = B^a mod P -> 19^6 mod 23 = 2
    Bob's S = A^b mod P -> 8^15 mod 23 = 2
    Bob and Alice shares a secret key 2

    Proof Sketch:
        A^b mod P = g^ab mod P = g^ba mod P

5^6 = 8 * 5 = 40  = 17 mod 23