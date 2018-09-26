DECLARE
 CURSOR c (x number) is
 select ename, ejob, esal from emp
 where esal > x ;

 temp varchar(10);
 es emp.esal%type;

BEGIN
 temp := '&salary';
 es := to_number(NVL(temp,0));

 --CURSOR FOR LOOP

 FOR i in c(es) --PARAMETER TO CURSOR
 LOOP 
   DBMS_OUTPUT.PUT_LINE( RPAD( NVL(i.ename, '####'), 10, ' ') || '  ' || RPAD(i.ejob, 10, ' ') || '  ' ||i.esal);
 END LOOP;
END;
/