string encode(string src)
{     
  //Your code here 
  if(src.length()<=0)
  return src;
  
  if(src.length()==1)
  {
      src += "1";
      return src;
  }
  
  int i=0;
  while(i<src.length())
  {
      int j=i+1;
      int count=1;
     while(j<src.length() && src[i]==src[j])
     {
         count++;
         j++;
     }
     string temp=to_string(count);
     src.insert(i+1, temp);
     int t=temp.length();
     src.erase(i+t+1, count-1);
     i=i+t+1;
  }
  return src;
}     
