void reverseString(char* s, int sSize){
    for(int idx = 0; idx < sSize/2; idx++){
     char buff = s[idx];
     s[idx] = s[sSize - idx - 1];
     s[sSize - idx - 1] = buff;
    }
}
