void reverseString(char* s, int sSize){
    for(int idx = 0; idx < sSize/2; idx++){
     char buff = s[idx];
     s[idx] = s[sSize - idx - 1];
     s[sSize - idx - 1] = buff;
    }
}


char* reverseWords(char* s){
    int start = 0;
    int end = 1;
    while(1){
        if(s[end] == ' '){
            reverseString(s+start, end - start);
            start = end + 1;
        }
        else if(s[end] == '\0'){
            reverseString(s+start, end - start);
            break;
        }
        end++;
    }
    return s;
}
