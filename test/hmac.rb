##
# HMAC Tests

assert('HMAC.sha256') do
  key = 'Jefe'
  msg = 'what do ya want for nothing?'
  result = '5bdcc146bf60754e6a042426089575c75a003f089d2739839dec58b964ec3843'
  assert_equal result, HMAC.sha256(key, msg)
end

assert('HMAC.sha512') do
  key = 'Jefe'
  msg = 'what do ya want for nothing?'
  result = '164b7a7bfcf819e2e395fbe73b56e0a387bd64222e831fd610270cd7ea2505549758bf75c05a994a6d034f65f8f0e6fdcaeab1a34d4a6b4b636e070a38bce737'
  assert_equal result, HMAC.sha512(key, msg)
end
