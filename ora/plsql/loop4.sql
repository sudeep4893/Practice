DECLARE
 i number;
BEGIN

 i:=1;

 LOOP
  DBMS_OUTPUT.PUT_LINE(i);
  i:= i+1;
  EXIT WHEN i = 11; --explicitly broken

 END LOOP;
  
 DBMS_OUTPUT.PUT_LINE('AFTER LOOP');
END;
/