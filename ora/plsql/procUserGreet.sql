create or replace procedure procUserGreet(userName varchar)
IS
  temp varchar(20);

BEGIN
--userName is a parameter (argument) for the procedure
--By default it is an IN parameter
--so it can be read only and cannot be modified by the procedure

 --username := upper(username);
 temp := upper(username);
 DBMS_OUTPUT.PUT_LINE('HELLO ' || temp);
END;
/