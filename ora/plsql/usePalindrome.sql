DECLARE
 var varchar(30);
 flag number;
BEGIN
 var := '&string';
 flag := palindrome(var);

 IF flag = 1 THEN
  DBMS_OUTPUT.PUT_LINE(var || ' is a palindrome');
 ELSE
  DBMS_OUTPUT.PUT_LINE(var || ' is not a palindrome');
 END IF;

END;
/