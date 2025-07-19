// Using KMP Algorithm
class Solution {
  private:
  void computeLPSArray(string &pattern, int &p_size, vector<int> &LPS) {
    int len = 0;
    int j = 1;

    LPS[0] = 0;
    while (j < p_size) {
      if (pattern[j] == pattern[len]) {
        LPS[j] = len + 1;
        j++;
        len++;
      } 
      else {
        if (len != 0) {
          len = LPS[len - 1];
        } else {
          LPS[j] = 0;
          j++;
        }
      }
    }
  }

  int KMP(string pattern, string text) {
    int p_size = pattern.size();
    int t_size = text.size();

    vector<int> LPS(p_size);
    computeLPSArray(pattern, p_size, LPS);

    int i = 0, j = 0;
    while (i < t_size) {
      if (text[i] == pattern[j]) {
        i++;
        j++;
      } 
      else {
        if (j != 0) {
          j = LPS[j - 1];
        } else {
          i++;
        }
      }

      if (j == p_size) {
        return i - p_size;
      }
    }

    return -1;
  }

  public:
  int strStr(string haystack, string needle) { 
    return KMP(needle, haystack); 
  }
};

// Using Robin-Karp Algorithm with single hash
using i64 = long long int;
class Solution {
  private:
  i64 MOD = 1e9 + 7;
  i64 getHash(string &text, i64 &size, i64 &RADIX) {
    i64 hash = 0, factor = 1;
    for (i64 i = size - 1; i >= 0; i--) {
      hash = (hash + (text[i] - 'a') * factor) % MOD;
      factor = (factor * RADIX) % MOD;
    }

    return hash;
  }

  public:
  int strStr(string haystack, string needle) {
    i64 n = haystack.size(), m = needle.size();
    if (n < m) {
      return -1;
    }

    i64 RADIX = 26, MAX_WEIGHT = 1;
    for (i64 i = 1; i < m; i++) {
      MAX_WEIGHT = (MAX_WEIGHT * RADIX) % MOD;
    }

    i64 hashNeedle = getHash(needle, m, RADIX);
    i64 hashHaystack = 0;

    for (i64 i = 0; i <= n - m; i++) {
      if (i == 0) {
        hashHaystack = getHash(haystack, m, RADIX);
      } 
      else {
        i64 leftChar = (haystack[i - 1] - 'a') * MAX_WEIGHT % MOD;
        i64 rightChar = (haystack[i + m - 1] - 'a') % MOD;

        hashHaystack = (hashHaystack - leftChar + MOD) % MOD;
        hashHaystack = (hashHaystack * RADIX + rightChar) % MOD;
      }

      if (hashNeedle == hashHaystack) {
        for (i64 j = 0; j < m; j++) {
          if (needle[j] != haystack[j + i]) break;
          if (j == m - 1) return i;
        }
      }
    }

    return -1;
  }
};

// Using Robin-Karp Algorithm with Double hash
using i64 = long long int;
class Solution {
  private:
  i64 MOD1 = 1e9 + 7;
  i64 RADIX1 = 26;
  i64 MOD2 = 1e9 + 33;
  i64 RADIX2 = 27;

  pair<i64, i64> getHash(string &text, i64 &size) {
    i64 hash1 = 0, hash2 = 0;
    i64 factor1 = 1, factor2 = 1;

    for (i64 i = size - 1; i >= 0; i--) {
      hash1 = (hash1 + (text[i] - 'a') * factor1) % MOD1;
      factor1 = (factor1 * RADIX1) % MOD1;

      hash2 = (hash2 + (text[i] - 'a') * factor2) % MOD2;
      factor2 = (factor2 * RADIX2) % MOD2;
    }

    return {hash1, hash2};
  }

  public:
  int strStr(string haystack, string needle) {
    i64 n = haystack.size(), m = needle.size();
    if (n < m) {
      return -1;
    }

    i64 MAX_WEIGHT1 = 1, MAX_WEIGHT2 = 1;
    for (i64 i = 1; i < m; i++) {
      MAX_WEIGHT1 = (MAX_WEIGHT1 * RADIX1) % MOD1;
      MAX_WEIGHT2 = (MAX_WEIGHT2 * RADIX2) % MOD2;
    }

    pair<i64, i64> hashNeedle = getHash(needle, m);
    pair<i64, i64> hashHaystack = {0, 0};

    for (i64 i = 0; i <= n - m; i++) {
      if (i == 0) {
        hashHaystack = getHash(haystack, m);
      } 
      else {
        i64 leftChar1 = (haystack[i - 1] - 'a') * MAX_WEIGHT1 % MOD1;
        i64 rightChar1 = (haystack[i + m - 1] - 'a') % MOD1;
        hashHaystack.first = (hashHaystack.first - leftChar1 + MOD1) % MOD1;
        hashHaystack.first = (hashHaystack.first * RADIX1 + rightChar1) % MOD1;

        i64 leftChar2 = (haystack[i - 1] - 'a') * MAX_WEIGHT2 % MOD2;
        i64 rightChar2 = (haystack[i + m - 1] - 'a') % MOD2;
        hashHaystack.second = (hashHaystack.second - leftChar2 + MOD2) % MOD2;
        hashHaystack.second =
            (hashHaystack.second * RADIX2 + rightChar2) % MOD2;
      }

      if (hashNeedle == hashHaystack) {
        return i;
      }
    }

    return -1;
  }
};