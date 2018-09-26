create or replace function palindrome(x varchar)
return number
IS
 i number;
 j number;

BEGIN
 i := 1;
 j := length(x);

 while i < j
 LOOP
  IF substr(x,i,1) <> substr(x, j,1) THEN
   return 0; -- not palindrome
  END IF;
  i := i+ 1;
  j := j-1;
 END LOOP;

 return 1; --palindrome
END;
/