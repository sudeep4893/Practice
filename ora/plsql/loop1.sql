DECLARE
 i number;
BEGIN

 i := 1;
 WHILE i < 11
 LOOP
  DBMS_OUTPUT.PUT_LINE(i);
  i := i + 1;
 END LOOP;
END;
/