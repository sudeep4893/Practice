DECLARE
 n1 number;
 n2 number;
 n3 number;
 ans number;

BEGIN
 n1 := &number1;
 n2 := &number2;
 n3 := &number3;

 ans := add3nos(n1,n2,n3); 

 DBMS_OUTPUT.PUT_LINE('addition  = ' || ans);
END;
/
