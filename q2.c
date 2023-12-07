#include <stdio.h>
#include <openssl/bn.h>

int main() {
    // Initialize BIGNUM variables
    BIGNUM *e = BN_new();
    BIGNUM *n = BN_new();
    BIGNUM *phi_n = BN_new();
    BIGNUM *d = BN_new();

    // Set the values of e, n, and phi(n) in hexadecimal format
    BN_hex2bn(&e, "010001");
    BN_hex2bn(&n, "E103ABD94892E3E74AFD724BF28E78366D9676BCCC70118BD0AA1968DBB143D1");
    BN_hex2bn(&phi_n, "E103ABD94892E3E74AFD724BF28E78348D52298BD687C44DEB3A81065A7981A4");

    // Calculate the modular multiplicative inverse of e modulo phi(n) to find d
    BN_mod_inverse(d, e, phi_n, NULL);

    // Print the private key d in hexadecimal format
    char *d_hex = BN_bn2hex(d);
    printf("Private Key (d): %s\n", d_hex);

    // Free allocated memory
    BN_free(e);
    BN_free(n);
    BN_free(phi_n);
    BN_free(d);
    OPENSSL_free(d_hex);

    return 0;
}