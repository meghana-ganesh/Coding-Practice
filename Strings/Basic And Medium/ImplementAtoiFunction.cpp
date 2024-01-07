int createAtoi(string s) 
{
   int num = 0;
   int sign = 1; // Initialize sign to positive
   // Skip leading whitespace
   int i = 0;
   while (i < s.length() && s[i] == ' ') 
   {
      i++;
   }
   // Check for sign character
   if (i < s.length() && (s[i] == '+' || s[i] == '-')) 
   {
      sign = (s[i] == '-') ? -1 : 1;
      i++;
   }
   // Parse the numeric part of the string
   while (i < s.length() && isdigit(s[i])) 
   {
      int digit = s[i] - '0';
      // Check for overflow before multiplying by 10
      if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > 7)) 
      {
         return (sign == 1) ? INT_MAX : INT_MIN; // Overflow
      }
      num = num * 10 + digit;
      i++;
   }
   return num * sign;
}
