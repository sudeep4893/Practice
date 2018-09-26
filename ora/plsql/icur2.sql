DECLARE
 var emp.eno%type;

BEGIN

 var := &empNo;

 --parameter in where clause of implicit cursor
 
 update emp set esal = esal + 1
 where eno = var;

 DBMS_OUTPUT.PUT_LINE(SQL%ROWCOUNT || ' rows updated ');

 --NOTE : NO ERROR IF WHERE CLAUSE FILTERS ALL THE ROWS
 --AND THERE ARE ZERO ROWS UPDATED
END;
/