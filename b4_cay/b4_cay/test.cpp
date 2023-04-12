#include<iostream>
#include<stack>
#include<string>
using namespace std;

float tinhToan(char op, float num1, float num2) {
    if (op == '+')
        return num1 + num2;
    else if (op == '-')
        return num1 - num2;
    else if (op == '*')
        return num1 * num2;
    else if (op == '/')
        return num1 / num2;
    else
        return 0;
}

float tinhBieuThuc(string s) {
    stack<float> st;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            float num2 = st.top();
            st.pop();
            float num1 = st.top();
            st.pop();
            float res = tinhToan(s[i], num1, num2);
            st.push(res);
        }
        else {
            float num = 0;
            while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--;
            st.push(num);
        }
    }
    return st.top();
}

int main() {
    string s = "8-1+3*9-5+3-2*7-4";
    cout << "Ket qua: " << tinhBieuThuc(s);
    return 0;
}
