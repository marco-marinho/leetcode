int myAtoi(char* input) {
    char cur_char;

    //Skip leading white spaces
    do {
        cur_char = *input++;
        if (cur_char == '\0') {
            return 0;
        }
    } while (cur_char == ' ');

    //Check if negative or positive sign
    int negative = 0;
    if (cur_char == '-') {
        negative = 1;
        cur_char = *input++;
    }
    else if (cur_char == '+') {
        cur_char = *input++;
    }
    if (!(cur_char >= 0x30 && cur_char <= 0x39)){
        return 0;
    }

    long long out = 0;
    long max_val = 2147483647;
    do {
        out += (int)(cur_char - 0x30);
        if (out > max_val){
            out = max_val;
            if(negative){
                out += 1;
            }
            out *= 10;
            break;
        }
        out *= 10;
        cur_char = *input++;
    } while (cur_char >= 0x30 && cur_char <= 0x39);
    out = out/10;
    if(negative){
        out *= -1;
    }
    return (int)out;
}
