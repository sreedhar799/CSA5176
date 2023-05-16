#include <bits/stdc++.h>
using namespace std;
 
void printString(string S, int N)
{
    string plaintext[5];
 
    int freq[26] = { 0 };
 
    int freqSorted[26];
 
    int Used[26] = { 0 };
 
    for (int i = 0; i < N; i++) {
        if (S[i] != ' ') {
            freq[S[i] - 'A']++;
        }
    }
 
    for (int i = 0; i < 26; i++) {
        freqSorted[i] = freq[i];
    }
 
    string T = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
 
    sort(freqSorted, freqSorted + 26, greater<int>());
 
    for (int i = 0; i < 5; i++) {
 
        int ch = -1;
        for (int j = 0; j < 26; j++) {
 
            if (freqSorted[i] == freq[j] && Used[j] == 0) {
                Used[j] = 1;
                ch = j;
                break;
            }
        }
        if (ch == -1)
            break;
 
        int x = T[i] - 'A';
 
        x = x - ch;
 
        string curr = "";
 
        for (int k = 0; k < N; k++) {
 
            if (S[k] == ' ') {
                curr += ' ';
                continue;
            }
 
            int y = S[k] - 'A';
            y += x;
 
            if (y < 0)
                y += 26;
            if (y > 25)
                y -= 26;
 
            curr += 'A' + y;
        }
 
        plaintext[i] = curr;
    }
 
    for (int i = 0; i < 5; i++) {
        cout << plaintext[i] << endl;
    }
}
 
int main()
{
   
    string S = "B TJNQMF NFTTBHF";
    int N = S.length();
 
    printString(S, N);
 
    return 0;
}
