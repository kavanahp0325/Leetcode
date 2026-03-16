char* removeDuplicates(char* s) {
    char* str = malloc(100000);
    int len = 0;
    char ch;
    int i = 0;
    while ((ch = s[i++]) != 0) {
        str[len] = ch;
        if (len == 0 || ch != str[len - 1])
            len++;
        else
            len--;
    }
    str[len] = 0;
    return str;
}