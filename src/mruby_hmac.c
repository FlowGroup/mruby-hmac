/*
** mruby_hmac.c - HMAC
**
** See Copyright Notice in hmac_sha2.c
*/

#include "string.h"
#include "hmac_sha2.h"
#include "mruby.h"
#include "mruby/string.h"

static mrb_value
digest2hexdigest(mrb_state *mrb, mrb_value b)
{
  mrb_value h;
  int i, len;
  char *bp, buf[3];

  bp = RSTRING_PTR(b);
  len = RSTRING_LEN(b);
  h = mrb_str_buf_new(mrb, len * 2);
  for (i = 0; i < len; i++) {
    snprintf(buf, sizeof(buf), "%02x", (unsigned char )bp[i]);
    mrb_str_buf_cat(mrb, h, buf, 2);
  }
  return h;
}

static mrb_value
hmac_hexdigest(mrb_state *mrb, mrb_value self, unsigned int sha_len, unsigned int mac_len)
{
  unsigned char *key;
  mrb_int key_len;
  unsigned char *msg;
  mrb_int msg_len;
  unsigned char mac[mac_len];

  mrb_get_args(mrb, "ss", &key, &key_len, &msg, &msg_len);

  switch (sha_len) {
    case 512:
      hmac_sha512(key, key_len, msg, msg_len, mac, mac_len);
      break;
  }

  return digest2hexdigest(mrb, mrb_str_new(mrb, (char *)mac, mac_len));
}

static mrb_value
mrb_hmac_sha256(mrb_state *mrb, mrb_value self)
{
  return hmac_hexdigest(mrb, self, 256, 32);
}

static mrb_value
mrb_hmac_sha512(mrb_state *mrb, mrb_value self)
{
  return hmac_hexdigest(mrb, self, 512, 64);
}

void
mrb_mruby_hmac_gem_init(mrb_state *mrb)
{
  struct RClass *h;

  h = mrb_define_module(mrb, "HMAC");

  mrb_define_class_method(mrb, h, "sha256", mrb_hmac_sha256, MRB_ARGS_REQ(2));
  mrb_define_class_method(mrb, h, "sha512", mrb_hmac_sha512, MRB_ARGS_REQ(2));
}

void
mrb_mruby_hmac_gem_final(mrb_state *mrb)
{
}
