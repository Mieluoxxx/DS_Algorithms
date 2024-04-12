#include <iostream>
using namespace std;

#define MAXSIZE 255

typedef struct {
    char ch[MAXSIZE];
    int length;
} SString;

typedef struct StringNode{
    char ch;    // 1B
    struct StringNode *next;    // 32位4B, 64位8B
}StringNode, *String;

// typedef struct StringNode{
//     char ch[4];    // 4B
//     struct StringNode *next;    // 32位4B, 64位8B
// }StringNode, *String;

// 串的位序从1开始
void StrAssign(SString &S, char *ch) {
    S.length = ch[0] == '\0' ? 0 : strlen(ch);  // 计算串的长度
    for (int i = 1; ch[i-1] != '\0'; i++) {
        S.ch[i] = ch[i-1];                      // 将ch串的字符复制到T串中
    }
}

// 求子串
bool SubString(SString &T, SString &S, int pos, int len) {
    if (pos+len-1>S.length)
        return false;
    for (int i = pos; i < pos+len; i++) {
        T.ch[i-pos+1] = S.ch[i];
    }
    T.length = len;
    return true;
}

int StrCompare(SString S, SString T) {
    for (int i = 1; i <= S.length && i <= T.length; i++) {
        if (S.ch[i] != T.ch[i]) {
            return S.ch[i] - T.ch[i];
        }
    }
    return S.length - T.length;
}

void Print(SString S) {
    for (int i = 1; i <= S.length; i++) {
        cout << S.ch[i];
    }
    cout << " " << S.length << endl;
}

// int Index(SString S, SString T) {
//     int i = 1, n = S.length, m = T.length;
//     SString sub;    // 用于暂存子串
//     while (i <= n - m + 1) { 
//         SubString(sub, S, i, m);
//         if (StrCompare(sub, T) != 0)    ++i;
//         else    return i;
//     }
//     return 0;
// }

// 朴素模式匹配
int Index(SString S, SString T) {
    int i = 1, j = 1;
    while(i <= S.length && j <= T.length) {
        if (S.ch[i] == T.ch[i]) {
            ++i; ++j;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    
    if (j > T.length)
        return i - T.length;
    else 
        return 0;
}

int Index_KMP(SString S, SString T, int next[]) {
    int i = 1, j = 1;
    while(i <= S.length && j <= T.length) {
        if (j == 0 || S.ch[i] == T.ch[j]) {
            ++i; ++j;   // 继续比较后继字符
        } else {
            j = next[j];    // 模式串向右移动
        }
    }
    
    if (j > T.length)   // 匹配成功
        return i - T.length;
    else    // 匹配失败
        return 0;
}

void get_next(SString T, int* next) {
    int i = 1, j = 0;
    next[1] = 0;    // next[1]的值总是0
    while (i < T.length) {  // 求解next[i+1]
        if (j == 0 || T.ch[i] == T.ch[j]) { 
            // T.ch[i]表示后缀的单个字符, T.ch[j]表示前缀的单个字符
            ++i; ++j;   // 继续比较后继字符
            next[i] = j;    // 当前的j就是next的值
        } else {
            j = next[j];    // 若字符不相同, 则j值回溯
        }
    }
}

void get_nextval(SString T, int nextval[]) {
    int i = 1, j = 0;
    nextval[1] = 0;
    while(i < T.length) {
        if(j==0 || T.ch[i] == T.ch[j]) {
            ++i; ++j;
            if (T.ch[i] != T.ch[j]) nextval[i] = j;
            else nextval[i] = nextval[j];
        }
        else {
            j = nextval[j];
        }
    }
}

int main() {
    SString S;
    char ch[] = "hello world!";
    StrAssign(S, ch);
    Print(S);

    SString T;
    SubString(T, S, 2, 5);
    Print(T);

    int result = StrCompare(S, T);

    if (result > 0)
        cout << "S > T" << endl;
    else if (result < 0)
        cout << "S < T" << endl;
    else
        cout << "S = T" << endl;

    int index = Index(S, T);
    cout << "Index: " << index << endl;


    SString S1;
    char ch1[] = "abababca";
    StrAssign(S1, ch1);
    int next[MAXSIZE];
    get_next(S1, next);

    return 0;
}