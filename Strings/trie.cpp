//if you're not familiar(solved many questions using this) with this implementation, use the implementation with pointers because debugging will be hard

const int N = 100005;
const int SIG = 27;

int tr[N*10][SIG], eow[N*10];

int sz = 0;

void insert(string s) {
    int v = 0, cur;
    for (char c : s) {
        cur = c - 'a' + 1;
        if (!tr[v][cur])
            v = tr[v][cur] = ++sz;
        else
            v = tr[v][cur];
    }
    eow[v] = 1;
}

bool search(string s) {
    int v = 0;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a' + 1;
        if (!tr[v][c])
            return false;
        v = tr[v][c];
    }
    if (eow[w] == 1)
        return true;
    return false;
}

//lexicographically first non-empty substring with MAX LCP with s
void search(string s, string &res) {
    int v = 0, cur;
    for (char c : s) {
        cur = c - 'a' + 1;
        if (!tr[v][cur]) break;
        res += c;
        v = tr[v][cur];
    }
    while (!eow[v]) {
        for (int i = 1; i <= 26; i++) {
            if (tr[v][i]) {
                res += (char)(i + 'a' - 1);
                v = tr[v][i];
                break;
            }
        }
    }
}
