DECLARE
 i number;
BEGIN
 FOR i IN 1..10
 LOOP
   DBMS_OUTPUT.PUT_LINE(i);
   --i will by default increment by 1
   --1 and 10  are inclusive
 END LOOP;
END;
/