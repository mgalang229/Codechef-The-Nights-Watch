#include <bits/stdc++.h>
using namespace std;

void TestCase() {
	int n;
	string s;
	cin >> n >> s;
	int ans = 0;
	int left = 0;
	while (left < n) {
		if (s[left] == '1') { // skip the 1s
			left++;
			continue;
		}
		int right = left;
		while (right < n && s[right] == '0') { // get the substring that contains '0' (s[left], s[left+1], ..., s[right-1])
			right++;
		}
		int len = right - left; // calculate the length of the substring
		if (right < n) { // do not include the last character of the next character is '1'
			len--;
		}
		if (left > 0) {// do not include the first character of the previous character is '1'
			len--;
		}
		len = max(len, 0); // in case the length goes below 0
		ans += ((len + 1) >> 1); // this is the same as placing '1' in the odd positions of the substring
		left = right; // jump the next character after the substring collected
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc = 1;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		TestCase();
	}
	return 0;
}

