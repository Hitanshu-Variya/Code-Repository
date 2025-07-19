using i64 = long long int;
class Solution {
  public:
  int myAtoi(string s) {
    int size = s.size();
    i64 num = 0;

    int index = 0;
    while (index < size && s[index] == ' ') {
      index++;
    }

    bool isNegative = false;
    if (s[index] == '-') {
      isNegative = true;
      index++;
    } 
    else if (s[index] == '+') {
      index++;
    }

    while (index < size && s[index] == '0') {
      index++;
    }

    for (int i = index; i < size; i++) {
      if (s[i] >= '0' && s[i] <= '9') {
        num = (num * 10 + (s[i] - '1') + 1);

        if (num > INT_MAX) {
          if (isNegative)
            return INT_MIN;
          return INT_MAX;
        }

        if (num <= INT_MIN) {
          return INT_MIN;
        }
      } else {
        break;
      }
    }

    if (isNegative) {
      num = -1LL * num;
    }

    return num;
  }
};