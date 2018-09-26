DECLARE
 n1 number;
 n2 number;
 ans number;

BEGIN
 n1 := &number1;
 n2 := &number2;
 ans := n1 + n2; 

 DBMS_OUTPUT.PUT_LINE(n1 || ' + ' ||  n2 || ' = ' || ans);
END;
/
