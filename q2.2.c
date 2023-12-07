#include <stdio.h>
#include <string.h>
#include <openssl/bn.h>
#include <stdlib.h>
#include <unistd.h>

void printBN(char *msg, BIGNUM *tmp) {
    char *number_str = BN_bn2hex(tmp); // Convert BIGNUM to hex
    printf("%s%s\n", msg, number_str); // Print hex
    OPENSSL_free(number_str); // Free memory
}

int main(int argc, char *argv[]) {
    BN_CTX *ctx = BN_CTX_new();

    BIGNUM *e = BN_new(); // 1. Encryption Key variable
    BIGNUM *d = BN_new(); // 2. Decryption Key variable
    BIGNUM *n = BN_new(); // 3. product of large prime numbers p and q
    BIGNUM *phi_n = BN_new(); // 4. Totient of (n) Euler's totient function
    BIGNUM *C = BN_new(); // 5. Encrypted Message variable
    BIGNUM *D = BN_new(); // 6. Decrypted Ciphertext variable

    printf("\nEnter your Encrypted Message in hexadecimal format:\n");
    char CC[100];
    scanf("%s", CC);
    BN_hex2bn(&C, CC); // Assign the input value in variable (CC) to Encrypted Message variable

    // Calculate the Decryption Key (Private Key) d = e mod(Phi(n))
    // Here you would assign values to e, Phi(n) (totient), and n, then compute d
    // ...

    // Decrypt ciphertext using D = C^d (mod n)
    BN_mod_exp(D, C, d, n, ctx);

    // Convert Hex string to ASCII letters using Python
    printf("\nOriginal Message:\n");
    char str1[500] = "print(\"";
    char *str2 = BN_bn2hex(D);
    char str3[] = "\".decode(\"hex\"))";
    strcat(str1, str2);
    strcat(str1, str3);
    char *args[] = {"python2", "-c", str1, NULL};
    execvp("python2", args);

    // Free allocated memory
    BN_free(e);
    BN_free(d);
    BN_free(n);
    BN_free(phi_n);
    BN_free(C);
    BN_free(D);
    BN_CTX_free(ctx);

    return EXIT_SUCCESS;
}