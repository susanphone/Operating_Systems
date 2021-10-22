# ISA Algorithm
 RSA Public-Key Cryptosystem
 * Rivest-Shamir-Adleman, 1977
 1. Select at random two large prime numbers p,q.
 2. Compute $n = p x q$
 3. select a small odd integer $e$ which is relatively prime to $(p-1) x (q-1)$
    * relatively prime: gcd (e, (p-1) x (q-1))
        * p =5 q = 7
            * (p-1) x (q-1) = 24 => e = 5, 7
4. Compute d as the multiplicative inverse of e, modulo (p-1) x (q-1), i.e. $e x d = 1 % [(p-1) x (q-1)]$.
5. Publish P = (e,n) as RSA pubic key
6. Keep S = (d,n) as RSA private key

        p=13, q=17, n = p x q = 13 x 17 = 221
        e = 5, (p-1) x (q-1) = 12 x 16 = 192
        5 x d = 1 + k x 192 for some k.
            k = 1: 5 xd = 1 + 1 x 192 = 193, no good
            k = 2: 5 x d = 1 + 2 x 192 = 385, good
                d = 77
        P = (5,221), S = (77,221)

## Applications
1. 

        Alice <-----> Bob
                 M
    * Bob obtains Alice's public key PA.
        Everyone publishes the public key
    * Bob computes cophertext C = PA(M), where M is the original message Bob tries to send to Alice.
        * Anyone with network access can access C
    * When Alice receives C, she applies her secret key SA to obtain SA(PA(M)) = M
        * cannot open message without secret key
    * **$P(M) = M^e mod n, S(C) = C^d mod n$**


2. Digital Signature
    * Alice claims to be Alice, and Bob needs to check
    * Alice computes her digital signature delta
        * **$\delta = SA(M')$**
    * Alice sends $(M', \delta)$ to Bob
    * Bob obtains Alice's Public Key PA and runs PA on delta. If $M' = PA(\delta)$, Bob concludes that $M'$ was actually signed by Alice. Otherwise, if $M' \neq PA(\delta)$, then a forgery has occurred


## Fermat's Theorem Example

    P = 7
    Z_p = {0,1,2,3,4,5,6}
    Z_p* = {2,3,4,5,6}
    2^6 mod 7 = 64 mod 7 = 1
    3^6 mod 7 = 721 mod 7 = 1
    4^6 mod 7 = 4096 mod 7 = 1
    5^6 mod 7 = ...
    6^6 mod 7 = ...

* three line = means mod equals?
## Chinese Remainder Theorem Examples

    Example 1
    n1 = 2, n2 = 3, n3 = 5
    n = 2 x 3 x 5 = 30
    x = 31      31 mod 2 = 1
    a = 1       31 mod 3 = 1
                31 mod 5 = 1
    31 mod 30 = 1


    Example 2
    n1 = 5, n2 = 7, n3 = 9
    n = 5 x 7 x 9 = 315
    x = 319     319 mod 5 = 4
    a = 4       319 mod 7 = 4
                319 mod 9 = 4
    319 mod 315 = 4