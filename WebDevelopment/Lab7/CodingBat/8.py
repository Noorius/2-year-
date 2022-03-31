def front_back(str):
  if len(str) <= 1:
    return str
  
  ans = str[len(str)-1]
  
  for i in range(1,len(str)-1):
    ans += str[i]
  
  
  ans+=str[0]
  
  return ans