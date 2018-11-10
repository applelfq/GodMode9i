#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define SHA1_LEN 20

#define AES_BLOCK_SIZE 16

typedef enum {
	ENCRYPT,
	DECRYPT
} crypt_mode_t;

typedef enum {
	NAND,
	NAND_3DS,
	ES
} key_mode_t;

int dsi_sha1_verify(const void *digest_verify, const void *data, unsigned len);

void dsi_crypt_init(const uint8_t *console_id_be, const uint8_t *emmc_cid, int is3DS);

void dsi_nand_crypt_1(uint8_t *out, const uint8_t* in, uint32_t offset);

void dsi_nand_crypt(uint8_t *out, const uint8_t* in, uint32_t offset, unsigned count);

int dsi_es_block_crypt(uint8_t *buf, unsigned buf_len, crypt_mode_t mode);

void dsi_boot2_crypt_set_ctr(uint32_t size_r);

void dsi_boot2_crypt(uint8_t* out, const uint8_t* in, unsigned count);

#ifdef __cplusplus
}
#endif
