def missing_char(str, n):
  ans = ""
  for i in range(0,len(str)):
    if i!=n:
      ans += str[i]
  
  return ans