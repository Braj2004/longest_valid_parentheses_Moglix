#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to find the length of the longest valid parentheses substring
int longestValidParentheses(string s)
{
  // Count of opening and closing parentheses
  int left = 0;
  int right = 0;

  // Stores the maximum valid length found
  int ans = 0;

  // ---------------- Left to Right Scan ----------------
  // This scan handles cases where there are extra ')' parentheses.
  for (int i = 0; i < s.length(); i++)
  {
    // Count opening bracket
    if (s[i] == '(')
      left++;
    // Count closing bracket
    else
      right++;

    // If counts are equal, we found a valid substring
    if (left == right)
    {
      ans = max(ans, 2 * right);
    }
    // More ')' than '(' means substring cannot be valid anymore.
    // Reset both counters and start a new substring.
    else if (right > left)
    {
      left = 0;
      right = 0;
    }
  }

  // Reset counters for the second scan
  left = 0;
  right = 0;

  // ---------------- Right to Left Scan ----------------
  // This scan handles cases where there are extra '(' parentheses.
  for (int i = s.length() - 1; i >= 0; i--)
  {
    // Count closing bracket
    if (s[i] == ')')
      right++;
    // Count opening bracket
    else
      left++;

    // Equal counts means a valid substring is found
    if (left == right)
    {
      ans = max(ans, 2 * left);
    }
    // More '(' than ')' while scanning backwards
    // means this substring cannot be valid.
    // Reset counters.
    else if (left > right)
    {
      left = 0;
      right = 0;
    }
  }

  // Return the maximum valid substring length
  return ans;
}

int main()
{
  string s;

  cout << "Enter parentheses string: ";
  cin >> s;

  cout << "Longest Valid Parentheses Length = "
       << longestValidParentheses(s) << endl;

  return 0;
}