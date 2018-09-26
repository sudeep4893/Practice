DECLARE
 i number;
BEGIN

 FOR i in REVERSE 1..10
 LOOP
   DBMS_OUTPUT.PUT_LINE(i);
   -- i will by default decrement by 1
   -- 1 and 10 are inclusive
 END LOOP;

END;
/