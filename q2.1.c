#include <stdio.h>
#include <openssl/bn.h>

void printBN(char *msg, BIGNUM *a) {
    char *number_str = BN_bn2hex(a);
    printf("%s: %s\n", msg, number_str);
    OPENSSL_free(number_str);
}

int main() {
    // Initialize BIGNUM variables
    BIGNUM *e = BN_new();
    BIGNUM *n = BN_new();
    BIGNUM *d = BN_new();
    BIGNUM *ciphertext = BN_new();
    BIGNUM *plaintext = BN_new();
    BIGNUM *res = BN_new();
    BN_CTX *ctx = BN_CTX_new();

    // Set the values of e, n, and the ciphertext in hexadecimal format
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&n, "E103ABD94892E3E74AFD724BF28E78366D9676BCCC70118BD0AA1968DBB143D1");
    BN_hex2bn(&ciphertext, "858FF93C7C313EDC14E79A13EAF539D0893DACC7C70D335384965088E88AFC");

    // Calculate the private key d (modular inverse of e modulo phi(n))
    BN_mod_inverse(d, e, n, ctx);

    // Decrypt the ciphertext using the formula: plaintext = ciphertext^d mod n
    BN_mod_exp(res, ciphertext, d, n, ctx);
    BN_copy(plaintext, res);

    // Print the decrypted plaintext in hexadecimal format
    printBN("Decrypted Plaintext", plaintext);

    // Free allocated memory
    BN_free(e);
    BN_free(n);
    BN_free(d);
    BN_free(ciphertext);
    BN_free(plaintext);
    BN_free(res);
    BN_CTX_free(ctx);

    return 0;
}