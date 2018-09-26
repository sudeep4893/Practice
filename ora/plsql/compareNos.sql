DECLARE
  n1 number;
  n2 number;
  n3 number;

BEGIN
-- compare 3 numbers and find the greatest

  n1 := &number1;
  n2 := &number2;
  n3 := &number3;

  if n1 = n2 AND n1 = n3 then
    DBMS_OUTPUT.PUT_LINE('All numbers are ' || n1);
  elsif n1 > n2 AND n1 > n3 then
    DBMS_OUTPUT.PUT_LINE(n1 || ' is greatest ' );
  elsif n2 > n3 then
    DBMS_OUTPUT.PUT_LINE(n2 || ' is greatest ' );
  else
    DBMS_OUTPUT.PUT_LINE(n3 || ' is greatest ' );
  end if;  
  
END;
/