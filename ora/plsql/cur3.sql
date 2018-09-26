DECLARE
 CURSOR c is
 select ename, ejob, esal from emp;

BEGIN
 --CURSOR FOR LOOP

 FOR i in c
 LOOP 
   DBMS_OUTPUT.PUT_LINE( RPAD( NVL(i.ename, '####'), 10, ' ') || '  ' || RPAD(i.ejob, 10, ' ') || '  ' ||i.esal);
 END LOOP;
END;
/