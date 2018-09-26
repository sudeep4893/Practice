DECLARE
  q number;
  sqr number;

BEGIN

 q := &number;
 procCalSquare(sqr, q);--using a stored procedure in a PLSQL block
 DBMS_OUTPUT.PUT_LINE('square : ' || sqr );

 procCalSquare(sqr);--test of default value
 DBMS_OUTPUT.PUT_LINE('square : ' || sqr );

END;
/