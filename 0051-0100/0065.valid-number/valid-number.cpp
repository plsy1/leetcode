bool isNumber(char* s) {
  bool bIsNum = false;

  while (' ' == *s) {
    s++;
  }

  if ('-' == *s || '+' == *s) {
    s++;
  }

  while (isdigit(*s)) {
    bIsNum = true;
    s++;
  }

  if ('.' == *s) {
    s++;
  }

  while (isdigit(*s)) {
    bIsNum = true;
    s++;
  }

  if (true == bIsNum && 'e' == *s) {
    s++;
    bIsNum = false;

    if ('+' == *s || '-' == *s) {
      s++;
    }

    while (isdigit(*s)) {
      s++;
      bIsNum = true;
    }
  }

  while (' ' == *s) {
    s++;
  }

  return '\0' == *s && bIsNum;
}
