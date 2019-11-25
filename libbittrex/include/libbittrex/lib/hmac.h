#ifndef BITTREX_CPP_HMAC_H
#define BITTREX_CPP_HMAC_H

#include <openssl/hmac.h>

std::string hmac_sha512(const std::string &uri, const std::string &secret) {
    unsigned char *digest;
    digest = HMAC(EVP_sha512(),
                  reinterpret_cast<const unsigned char *>(secret.c_str()), secret.length(),
                  reinterpret_cast<const unsigned char *>(uri.c_str()), uri.length(),
                  nullptr, nullptr);

    char sha512_str[HMAC_MAX_MD_CBLOCK];
    for (int i = 0; i < 64; i++)
        sprintf(&sha512_str[i * 2], "%02x", (unsigned int) digest[i]);

    return std::move(std::string(sha512_str));
}

#endif //BITTREX_CPP_HMAC_H